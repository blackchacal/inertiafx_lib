/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Logger.h                                                             *
 * \brief Logger class.                                                       *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 9th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_LOGGER_H
#define _IFX_CORE_LOGGER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdarg>
#include "InertiaFX.h"

#ifndef LOGGER_MAX_LOG_MSG_SIZE
#define LOGGER_MAX_LOG_MSG_SIZE (256)
#endif

namespace InertiaFX
{
    namespace Core
    {
        enum class LogLevel
        {
            INFO,
            DEBUG,
            WARNING,
            ERROR,
            CRITICAL,
        };

        class Logger
        {
        public:
            Logger();
            Logger(const std::string &filename);
            ~Logger();

            void log(LogLevel lvl, const char *tag, const char *message, ...);
            void setMinLevel(LogLevel lvl);
            void setLogFilename(const std::string &filename);
            void enableLogToConsole();
            void enableLogToFile();
            void disableLogToConsole();
            void disableLogToFile();
            void disable();
            void clearLogFile();

        private:
            LogLevel min_lvl;
            bool enable;
            bool log_to_console;
            bool log_to_file;
            char log_msg[LOGGER_MAX_LOG_MSG_SIZE];
            std::ofstream log_file;
            std::string filename;

            std::string levelToString(LogLevel lvl);
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_ENGINE_H */