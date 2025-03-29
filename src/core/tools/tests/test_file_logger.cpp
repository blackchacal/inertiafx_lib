#include "file_logger.h"
#include <fstream>
#include <gtest/gtest.h>
#include <regex>
#include <string>

using namespace InertiaFX::Core::Tools;

class FileLoggerTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Create a test log file path
        testLogPath = "test.log";
        logger      = std::make_unique<FileLogger>(testLogPath, LogLevel::Debug, true);
    }

    void TearDown() override
    {
        logger.reset();  // Reset logger to ensure file is closed

        // Clean up test log file
        if (std::remove(testLogPath.c_str()) != 0)
        {
            std::cerr << "Error deleting test log file" << std::endl;
        }
    }

    std::string ReadLogFile()
    {
        std::ifstream file(testLogPath);  // Open file in read mode
        if (!file.is_open())
        {
            return "";  // Return empty string if the file cannot be opened
        }
        std::stringstream buffer;
        buffer << file.rdbuf();  // Read the entire file content
        file.close();            // Close the file after reading
        return buffer.str();
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

    std::string testLogPath;
    std::unique_ptr<FileLogger> logger;
};

TEST_F(FileLoggerTest, Constructor)
{
    EXPECT_NO_THROW(FileLogger("new_test.log", LogLevel::Info, true));
    std::remove("new_test.log");
}

TEST_F(FileLoggerTest, ConstructorWithInvalidPath)
{
    EXPECT_THROW(FileLogger("/invalid/path/test.log", LogLevel::Info, true), std::runtime_error);
}

TEST_F(FileLoggerTest, EnableDisable)
{
    logger->disable();
    logger->log(LogLevel::Info, "This should not appear");
    EXPECT_TRUE(ReadLogFile().empty());

    logger->enable();
    logger->log(LogLevel::Info, "This should appear");
    EXPECT_FALSE(ReadLogFile().empty());
}

TEST_F(FileLoggerTest, ClearLogFile)
{
    logger->log(LogLevel::Info, "This should appear");
    EXPECT_FALSE(ReadLogFile().empty());

    logger->clearLogs();  // Clear the log file
    EXPECT_TRUE(ReadLogFile().empty());
}

TEST_F(FileLoggerTest, LogLevels)
{
    const char *message = "Test message";

    // Test each log level
    logger->log(LogLevel::Debug, message);
    std::string output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Debug, message));

    logger->clearLogs();
    logger->log(LogLevel::Info, message);
    output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Info, message));

    logger->clearLogs();
    logger->log(LogLevel::Warning, message);
    output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Warning, message));

    logger->clearLogs();
    logger->log(LogLevel::Error, message);
    output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Error, message));

    logger->clearLogs();
    logger->log(LogLevel::Critical, message);
    output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Critical, message));
}

TEST_F(FileLoggerTest, Threshold)
{
    const char *message = "Test message";

    logger->setThreshold(LogLevel::Warning);

    // These should not appear
    logger->log(LogLevel::Debug, message);
    logger->log(LogLevel::Info, message);
    EXPECT_TRUE(ReadLogFile().empty());

    // These should appear
    logger->log(LogLevel::Warning, message);
    logger->log(LogLevel::Error, message);
    logger->log(LogLevel::Critical, message);
    EXPECT_FALSE(ReadLogFile().empty());
}

TEST_F(FileLoggerTest, Formatting)
{
    logger->log(LogLevel::Info, "Test %s %d", "number", 42);
    std::string output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Info, "Test number 42"));
}

TEST_F(FileLoggerTest, LongMessage)
{
    std::string longMessage(FileLogger::MAX_LOG_MESSAGE_LENGTH, 'a');  // 1KB message
    EXPECT_NO_THROW(logger->log(LogLevel::Info, longMessage.c_str()));
    std::string output = ReadLogFile();
    EXPECT_TRUE(MatchLogPattern(output, LogLevel::Info, longMessage));

    std::string longMessage2(FileLogger::MAX_LOG_MESSAGE_LENGTH + 1, 'a');  // 1KB message
    EXPECT_THROW(logger->log(LogLevel::Info, longMessage2.c_str()), std::runtime_error);
}

TEST_F(FileLoggerTest, MultipleMessages)
{
    logger->log(LogLevel::Info, "Message 1");
    logger->log(LogLevel::Info, "Message 2");
    logger->log(LogLevel::Info, "Message 3");

    std::string output = ReadLogFile();
    EXPECT_TRUE(output.find("Message 1") != std::string::npos);
    EXPECT_TRUE(output.find("Message 2") != std::string::npos);
    EXPECT_TRUE(output.find("Message 3") != std::string::npos);
}