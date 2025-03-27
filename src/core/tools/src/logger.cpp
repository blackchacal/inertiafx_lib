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
 * @file logger.cpp
 * @brief Definition of the Logger class.
 *
 * @date 26, Mar 2025
 */

#include "Logger.h"
#include <ctime>

namespace InertiaFX
{
namespace Core
{
    namespace Tools
    {
        Logger::Logger() : _enabled(true), _threshold(LogLevel::Debug)
        {
        }

        Logger::~Logger() = default;

        void Logger::log(LogLevel level, const char *format, ...)
        {
            // If logging is disabled or level is below threshold, skip.
            if (!_enabled || level < _threshold)
            {
                return;
            }

            // Decide which stream to write to based on log level.
            FILE *outputFile =
                (level == LogLevel::Error || level == LogLevel::Critical) ? stderr : stdout;

            // Variadic argument handling
            va_list args;
            va_start(args, format);
            vLog(level, outputFile, format, args);
            va_end(args);
        }

        void Logger::enable()
        {
            _enabled = true;
        }

        void Logger::disable()
        {
            _enabled = false;
        }

        void Logger::setThreshold(LogLevel level)
        {
            _threshold = level;
        }

        void Logger::vLog(LogLevel level, FILE *outputFile, const char *format, va_list args)
        {
            // Get current time
            std::time_t now   = std::time(nullptr);
            std::tm localTime = *std::localtime(&now);

            // Format the time string
            char timeBuf[32];
            std::strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", &localTime);

            // Print prefix: [YYYY-MM-DD HH:MM:SS] [LEVEL]
            fprintf(outputFile, "[%s] [%s] ", timeBuf, logLevelToString(level));

            // Print the user-supplied message
            vfprintf(outputFile, format, args);

            // Terminate with a newline
            fprintf(outputFile, "\n");
        }

        const char *Logger::logLevelToString(LogLevel level) const
        {
            switch (level)
            {
                case LogLevel::Debug:
                    return "Debug";
                    break;
                case LogLevel::Info:
                    return "Info";
                    break;
                case LogLevel::Warning:
                    return "Warning";
                    break;
                case LogLevel::Error:
                    return "Error";
                    break;
                case LogLevel::Critical:
                    return "Critical";
                    break;
                default:
                    return "Unknown";
            }
        }

    }  // namespace Tools
}  // namespace Core
}  // namespace InertiaFX
