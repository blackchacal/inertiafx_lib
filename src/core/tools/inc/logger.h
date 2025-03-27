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
 * @file logger.h
 * @brief Declaration of the Logger class.
 *
 * @date 26, Mar 2025
 */

#ifndef INERTIAFX_LOGGER_H
#define INERTIAFX_LOGGER_H

#include "ILogger.h"
#include <cstdarg>
#include <cstdio>

namespace InertiaFX
{
namespace Core
{
    namespace Tools
    {
        /**
         * @class Logger
         * @brief Concrete implementation of ILogger for logging to stdout/stderr.
         */
        class Logger : public ILogger
        {
          public:
            /**
             * @brief Constructor initializes the logger with default settings.
             */
            Logger();

            /**
             * @brief Destructor for the Logger.
             */
            virtual ~Logger();

            /**
             * @brief Logs a formatted message at the given log level.
             *
             * @param level The severity level of the log message.
             * @param format A printf-style format string.
             * @param ... Variadic arguments to format the string.
             */
            void log(LogLevel level, const char *format, ...) override;

            /**
             * @brief Enables the logger, allowing log output.
             */
            void enable() override;

            /**
             * @brief Disables the logger, suppressing all log output.
             */
            void disable() override;

            /**
             * @brief Sets the minimum severity level required for messages to be logged.
             *
             * @param level The threshold log level.
             */
            void setThreshold(LogLevel level) override;

          private:
            bool _enabled;       /**< Indicates whether logging is enabled. */
            LogLevel _threshold; /**< Minimum severity level for messages to be logged. */

            /**
             * @brief Internal helper to perform the formatted output.
             *
             * @param level The severity level of the log message.
             * @param outputFile File handle to write into (stdout or stderr).
             * @param format A printf-style format string.
             * @param args Variadic argument list.
             */
            void vLog(LogLevel level, FILE *outputFile, const char *format, va_list args);

            /**
             * @brief Converts a LogLevel enum into a string for display.
             *
             * @param level The log level to convert.
             * @return const char* The string representation of the log level.
             */
            const char *logLevelToString(LogLevel level) const;
        };

    }  // namespace Tools
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_LOGGER_H
