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
 * @file ilogger.h
 * @brief Declaration of the ILogger interface.
 *
 * @date 26, Mar 2025
 */

#ifndef INERTIAFX_ILOGGER_H
#define INERTIAFX_ILOGGER_H

#include <cstdarg>
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace Tools
    {
        /**
         * @brief Logging levels for message categorization.
         */
        enum class LogLevel
        {
            Debug,
            Info,
            Warning,
            Error,
            Critical
        };

        /**
         * @interface ILogger
         * @brief Interface for log message output in the InertiaFX library.
         *
         * Provides a unified logging abstraction with configurable log level threshold
         * and optional enable/disable control.
         */
        class ILogger
        {
          public:
            /**
             * @brief Virtual destructor.
             */
            virtual ~ILogger() = default;

            /**
             * @brief Logs a formatted message at the given log level.
             *
             * @param level The severity level of the log message.
             * @param format A printf-style format string.
             * @param ... Variadic arguments to format the string.
             */
            virtual void log(LogLevel level, const char *format, ...) = 0;

            /**
             * @brief Enables the logger, allowing log output.
             */
            virtual void enable() = 0;

            /**
             * @brief Disables the logger, suppressing all log output.
             */
            virtual void disable() = 0;

            /**
             * @brief Sets the minimum severity level required for messages to be logged.
             *
             * @param level The threshold log level.
             */
            virtual void setThreshold(LogLevel level) = 0;
        };
    }  // namespace Tools
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_ILOGGER_H
