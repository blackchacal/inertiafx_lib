/**
 * InertiaFX_Lib - Physics Simulation Library.
 * Copyright (C) 2025  Ricardo Tonet <https://github.com/blackchacal>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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
 * @file file_logger.h
 * @brief Declaration of the FileLogger class.
 *
 * @date 28, Mar 2025
 */

#ifndef INERTIAFX_CORE_TOOLS_FILELOGGER_H
#define INERTIAFX_CORE_TOOLS_FILELOGGER_H

#include "Logger.h"
#include <fstream>

namespace InertiaFX
{
namespace Core
{
    namespace Tools
    {

        /**
         * @class FileLogger
         * @brief Logger that optionally writes log messages to both console and a file.
         */
        class FileLogger : public Logger
        {
          public:
            static const int MAX_LOG_MESSAGE_LENGTH = 1024; /**< Maximum length of log message. */

            /**
             * @brief Constructs a FileLogger with a file path, log threshold, and file-logging
             * toggle.
             *
             * @param filepath Path to the log file.
             * @param levelThreshold Minimum severity level to be logged.
             * @param printToFile If true, messages are also logged to the file.
             */
            FileLogger(const std::string &filepath, LogLevel levelThreshold, bool printToFile);

            /**
             * @brief Destructor for FileLogger.
             *
             * Closes the file stream if it is open.
             */
            ~FileLogger();

            /**
             * @brief Sets whether or not to log messages to the file.
             *
             * @param printToFile If true, writes messages to the file in addition to console.
             */
            void setPrintToFile(bool printToFile);

            /**
             * @brief Clears the log file.
             */
            void clearLogs();

            /**
             * @brief Logs a formatted message at the given log level.
             *
             * The message is written to console via Logger. If file logging is enabled,
             * it is also written to the output file.
             *
             * @param level The severity level of the log message.
             * @param format A printf-style format string.
             * @param ... Variadic arguments to format the string.
             */
            void log(LogLevel level, const char *format, ...) override;

          private:
            bool _printToFile;     /**< Indicates whether the message is also written to file. */
            std::string _filepath; /**< File path. */
            std::ofstream _fileStream; /**< File stream for writing log messages. */

            /**
             * @brief Writes the formatted log to the file (if open).
             *
             * This replicates the parent's time stamp + level format, but outputs to std::ofstream.
             *
             * @param level LogLevel for the message.
             * @param format The format string.
             * @param args Variadic argument list (va_list).
             */
            void vLogFile(LogLevel level, const char *format, va_list args);
        };

    }  // namespace Tools
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_TOOLS_FILELOGGER_H
