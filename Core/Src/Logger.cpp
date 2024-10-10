/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Logger.cpp                                                           *
 * \brief Logger class.                                                       *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 9th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include <ctime>
#include "Logger.h"

using namespace InertiaFX::Core;

Logger::Logger()
{
    this->min_lvl = LogLevel::INFO;
    this->enable = true;
    this->log_to_console = true;
    this->log_to_file = false;
}

Logger::Logger(const std::string &filename)
{
    this->min_lvl = LogLevel::INFO;
    this->enable = true;
    this->log_to_console = true;

    this->log_file.open(filename, std::ios::app);
    if (!this->log_file.is_open())
    {
        std::cerr << "Error opening log file." << std::endl;
        this->log_to_file = false;
    }
    else
    {
        this->filename = filename;  
        this->log_to_file = true;
    }
}

Logger::~Logger()
{
    this->log_file.close();
}

void Logger::log(LogLevel lvl, const char *tag, const char *message, ...)
{
    if ((this->enable) && (lvl >= this->min_lvl))
    {
        std::va_list list;
        va_start(list, message);

        std::vsnprintf(this->log_msg, sizeof(this->log_msg), message, list);

        /* Get current timestamp */
        time_t now = time(0);
        tm *timeinfo = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

        /* Create log entry */
        std::ostringstream log_entry;
        log_entry << "[" << timestamp << "] "
                  << levelToString(lvl) << " {" << tag << "}" << " : "
                  << this->log_msg
                  << std::endl;

        /* Log to console */
        if (this->log_to_console)
        {
            std::cout << log_entry.str();
        }

        /* Log to file */
        if (this->log_to_file && this->log_file.is_open())
        {
            this->log_file << log_entry.str();
            this->log_file.flush();
        }

        va_end(list);
    }
}

void Logger::setMinLevel(LogLevel lvl)
{
    this->min_lvl = lvl;
}

void Logger::setLogFilename(const std::string &filename)
{
    this->log_file.open(filename, std::ios::app);
    if (!this->log_file.is_open())
    {
        std::cerr << "Error opening log file." << std::endl;
        this->log_to_file = false;
    }
    else
    {
        this->filename = filename;
        this->log_to_file = true;
    }
}

void Logger::enableLogToConsole()
{
    this->log_to_console = true;
}

void Logger::enableLogToFile()
{
    this->log_to_file = true;
}

void Logger::disableLogToConsole()
{
    this->log_to_console = false;
}

void Logger::disableLogToFile()
{
    this->log_to_file = false;
}

void Logger::disable()
{
    this->enable = false;
}

void Logger::clearLogFile()
{
    if (!this->filename.empty())
    {
        this->log_file.close();
        this->log_file.open(this->filename, std::ofstream::out | std::ofstream::ate | std::ofstream::trunc);
        this->log_file.close();
    }
}

std::string Logger::levelToString(LogLevel lvl)
{
    switch (lvl)
    {
    case LogLevel::DEBUG:
        return "DEBUG";
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    case LogLevel::CRITICAL:
        return "CRITICAL";
    default:
        return "UNKNOWN";
    }
}