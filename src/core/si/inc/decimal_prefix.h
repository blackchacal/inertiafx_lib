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
 * @file decimal_prefix.h
 * @brief Declaration of the DecimalPrefix class.
 *
 * @details This class provides SI (Système International d'Unités) decimal prefix information.
 * It provides static functions to get the prefix name (based on symbol), symbol (based on name) and
 * multiplier (based both on symbol and name).
 *
 * @date 10, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_DECIMALPREFIX_H
#define INERTIAFX_CORE_SI_DECIMALPREFIX_H

#include <iostream>
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class DecimalPrefix
         * @brief Provides SI prefix name, symbol, and multiplier.
         *
         * This class encapsulates SI decimal prefix functionality.
         * The enum classes define recognized prefixes and their respective exponents.
         * Static functions provide name, symbol, and multiplier for each prefix.
         */
        class DecimalPrefix
        {
          public:
            /**
             * @enum Name
             * @brief Enumerates SI decimal prefix names with their exponent values.
             *
             * The value of each enum entry represents the exponent of 10
             * that corresponds to the prefix. For example, Name::milli
             * has the value -3, representing 10^-3.
             */
            enum class Name : int
            {
                quetta = 30,
                ronna  = 27,
                yotta  = 24,
                zetta  = 21,
                exa    = 18,
                peta   = 15,
                tera   = 12,
                giga   = 9,
                mega   = 6,
                kilo   = 3,
                hecto  = 2,
                deca   = 1,
                base   = 0,
                deci   = -1,
                centi  = -2,
                milli  = -3,
                micro  = -6,
                nano   = -9,
                pico   = -12,
                femto  = -15,
                atto   = -18,
                zepto  = -21,
                yocto  = -24,
                ronto  = -27,
                quecto = -30
            };

            /**
             * @enum Symbol
             * @brief Enumerates SI decimal prefix symbols with their exponent values.
             *
             * The value of each enum entry represents the exponent of 10
             * that corresponds to the symbol. For instance, Symbol::m
             * has the value -3, representing 10^-3.
             */
            enum class Symbol : int
            {
                Q    = 30,
                R    = 27,
                Y    = 24,
                Z    = 21,
                E    = 18,
                P    = 15,
                T    = 12,
                G    = 9,
                M    = 6,
                k    = 3,
                h    = 2,
                da   = 1,
                base = 0,
                d    = -1,
                c    = -2,
                m    = -3,
                mu   = -6,  // Will translate to the Unicode 'μ' symbol
                n    = -9,
                p    = -12,
                f    = -15,
                a    = -18,
                z    = -21,
                y    = -24,
                r    = -27,
                q    = -30,
            };

            /**
             * @brief Returns the textual name (e.g. "milli") for the specified prefix name.
             * @param prefix Enum value representing the decimal prefix name.
             * @return A std::string containing the prefix name.
             */
            static std::string getName(Name prefix);

            /**
             * @brief Returns the textual name (e.g. "milli") for the specified prefix symbol.
             * @param prefix Enum value representing the decimal prefix symbol.
             * @return A std::string containing the prefix name.
             */
            static std::string getName(Symbol prefix);

            /**
             * @brief Returns the symbol (e.g. "m") for the specified prefix name.
             * @param prefix Enum value representing the decimal prefix name.
             * @return A std::string containing the prefix symbol.
             */
            static std::string getSymbol(Name prefix);

            /**
             * @brief Returns the symbol (e.g. "m") for the specified prefix symbol.
             * @param prefix Enum value representing the decimal prefix symbol.
             * @return A std::string containing the prefix symbol.
             */
            static std::string getSymbol(Symbol prefix);

            /**
             * @brief Returns the decimal multiplier for the specified prefix symbol.
             * @param prefix Enum value representing the decimal prefix symbol.
             * @return A double containing the multiplier (10^exponent).
             */
            static double getMultiplier(Symbol prefix);

            /**
             * @brief Returns the decimal multiplier for the specified prefix name.
             * @param prefix Enum value representing the decimal prefix name.
             * @return A double containing the multiplier (10^exponent).
             */
            static double getMultiplier(Name prefix);
        };
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_DECIMALPREFIX_H
