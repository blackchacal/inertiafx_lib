/**
 * InertiaFX_Lib - Physics Simulation Library.
 * Copyright (C) 2025  Ricardo Tonet <https://github.com/blackchacal>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file file_logger.cpp
 * @brief Definition of the FileLogger class.
 *
 * @date 28, Mar 2025
 */

#include "file_logger.h"

#include <cstdarg>  // For va_list, va_start, va_end, va_copy
#include <ctime>    // For std::time, std::localtime, std::strftime
#include <iomanip>  // For std::setw, std::setfill
#include <sstream>  // For std::ostringstream
#include <stdexcept>

namespace InertiaFX
{
namespace Core
{
    namespace Tools
    {
        FileLogger::FileLogger(const std::string &filepath, LogLevel levelThreshold,
                               bool printToFile) : _filepath(filepath), _printToFile(printToFile)
        {
            // Set the base logger threshold
            setThreshold(levelThreshold);

            // Attempt to open file in append mode
            _fileStream.open(filepath, std::ios::app);
            if (!_fileStream.is_open())
            {
                throw std::runtime_error("Failed to open log file: " + filepath);
            }
        }

        FileLogger::~FileLogger()
        {
            if (_fileStream.is_open())
            {
                _fileStream.close();  // Close the file stream if it is open
            }
        }

        void FileLogger::setPrintToFile(bool printToFile)
        {
            _printToFile = printToFile;
        }

        void FileLogger::clearLogs()
        {
            if (_fileStream.is_open())
            {
                _fileStream.close();  // Close the file stream if it is open
            }
            _fileStream.open(_filepath, std::ios::trunc);  // Clear the log file
        }

        void FileLogger::log(LogLevel level, const char *format, ...)
        {
            if (_enabled && level >= _threshold)
            {
                std::string formatStr(format);
                if (formatStr.size() > FileLogger::MAX_LOG_MESSAGE_LENGTH)
                {
                    std::string errorMsg = "Log message exceeds maximum length of " +
                                           std::to_string(FileLogger::MAX_LOG_MESSAGE_LENGTH) +
                                           " characters.";
                    throw std::runtime_error(errorMsg);
                }
                va_list args;
                va_start(args, format);

                // Duplicate variadic arguments for file logging
                va_list argsFile;
                va_copy(argsFile, args);

                char msgBuffer[FileLogger::MAX_LOG_MESSAGE_LENGTH + 40];
                vsnprintf(msgBuffer, sizeof(msgBuffer), format, args);
                va_end(args);

                // Log to console using the base Logger
                Logger::log(level, "%s", msgBuffer);

                // Log to file using the duplicated arguments
                if (_fileStream.is_open())
                {
                    vLogFile(level, format, argsFile);
                }
                va_end(argsFile);
            }
        }

        void FileLogger::vLogFile(LogLevel level, const char *format, va_list args)
        {
            // Get current time
            std::time_t now   = std::time(nullptr);
            std::tm localTime = *std::localtime(&now);

            // Format the time string: [YYYY-MM-DD HH:MM:SS]
            char timeBuf[32];
            std::strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", &localTime);

            // Convert LogLevel to string
            const char *levelStr = logLevelToString(level);

            // Format the user message
            char messageBuffer[FileLogger::MAX_LOG_MESSAGE_LENGTH + 40];
            vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);

            // Output to file: [time] [level] message
            _fileStream << "[" << timeBuf << "] "
                        << "[" << levelStr << "] " << messageBuffer << "\n";

            // Flush to ensure timely writes (optional, but often helpful for log files)
            _fileStream.flush();
        }

    }  // namespace Tools
}  // namespace Core
}  // namespace InertiaFX
