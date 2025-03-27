#include "logger.h"
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>
#include <regex>
#include <sstream>
#include <string>

using namespace InertiaFX::Core::Tools;

class LoggerTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        logger = std::make_unique<Logger>();
    }

    bool MatchLogPattern(const std::string &log, LogLevel level, const std::string &message)
    {
        std::string logLevel = "";
        switch (level)
        {
            case LogLevel::Debug:
                logLevel = "Debug";
                break;
            case LogLevel::Info:
                logLevel = "Info";
                break;
            case LogLevel::Warning:
                logLevel = "Warning";
                break;
            case LogLevel::Error:
                logLevel = "Error";
                break;
            case LogLevel::Critical:
                logLevel = "Critical";
                break;
            default:
                break;
        }

        // Pattern: [YYYY-MM-DD HH:MM:SS] [LEVEL] message\n
        std::regex pattern("\\[\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] \\[" + logLevel +
                           "\\] " + message + "\n");
        return std::regex_match(log, pattern);
    }

    std::unique_ptr<Logger> logger;
};

TEST_F(LoggerTest, DefaultConstructor)
{
    EXPECT_NO_THROW(Logger());
}

TEST_F(LoggerTest, EnableDisable)
{
    logger->disable();
    testing::internal::CaptureStdout();
    logger->log(LogLevel::Info, "This should not appear");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());

    logger->enable();
    testing::internal::CaptureStdout();
    logger->log(LogLevel::Info, "This should appear");
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output2.empty());
}

TEST_F(LoggerTest, LogLevels)
{
    const char *message = "Test message";

    // Test each log level
    testing::internal::CaptureStdout();
    logger->log(LogLevel::Debug, message);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Debug, message));

    testing::internal::CaptureStdout();
    logger->log(LogLevel::Info, message);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(MatchLogPattern(output2, LogLevel::Info, message));

    testing::internal::CaptureStdout();
    logger->log(LogLevel::Warning, message);
    std::string output3 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(MatchLogPattern(output3, LogLevel::Warning, message));

    testing::internal::CaptureStderr();
    logger->log(LogLevel::Error, message);
    std::string output4 = testing::internal::GetCapturedStderr();
    EXPECT_TRUE(MatchLogPattern(output4, LogLevel::Error, message));

    testing::internal::CaptureStderr();
    logger->log(LogLevel::Critical, message);
    std::string output5 = testing::internal::GetCapturedStderr();
    EXPECT_TRUE(MatchLogPattern(output5, LogLevel::Critical, message));
}

TEST_F(LoggerTest, Threshold)
{
    const char *message = "Test message";

    // Set threshold to Warning
    logger->setThreshold(LogLevel::Warning);

    // These should not appear
    testing::internal::CaptureStdout();
    logger->log(LogLevel::Debug, message);
    logger->log(LogLevel::Info, message);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.empty());

    // These should appear
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    logger->log(LogLevel::Warning, message);
    logger->log(LogLevel::Error, message);
    logger->log(LogLevel::Critical, message);
    std::string output2 = testing::internal::GetCapturedStdout();
    std::string output3 = testing::internal::GetCapturedStderr();
    EXPECT_FALSE(output2.empty());
    EXPECT_FALSE(output3.empty());
}

TEST_F(LoggerTest, Formatting)
{
    testing::internal::CaptureStdout();
    logger->log(LogLevel::Info, "Test %s %d", "number", 42);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Info, "Test number 42"));
}