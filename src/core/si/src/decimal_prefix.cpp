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
 * @file decimal_prefix.cpp
 * @brief Implements the DecimalPrefix class and its methods.
 *
 * @details This class provides SI (Système International d'Unités) decimal prefix information.
 * It provides static functions to get the prefix name (based on symbol), symbol (based on name) and
 * multiplier (based both on symbol and name).
 *
 * @date 10, Mar 2025
 */

#include "decimal_prefix.h"
#include <cmath>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        std::string DecimalPrefix::getName(Name prefix)
        {
            switch (prefix)
            {
                case Name::quetta:
                    return "quetta";
                case Name::ronna:
                    return "ronna";
                case Name::yotta:
                    return "yotta";
                case Name::zetta:
                    return "zetta";
                case Name::exa:
                    return "exa";
                case Name::peta:
                    return "peta";
                case Name::tera:
                    return "tera";
                case Name::giga:
                    return "giga";
                case Name::mega:
                    return "mega";
                case Name::kilo:
                    return "kilo";
                case Name::hecto:
                    return "hecto";
                case Name::deca:
                    return "deca";
                case Name::base:
                    return "";
                case Name::deci:
                    return "deci";
                case Name::centi:
                    return "centi";
                case Name::milli:
                    return "milli";
                case Name::micro:
                    return "micro";  // Greek letter mu
                case Name::nano:
                    return "nano";
                case Name::pico:
                    return "pico";
                case Name::femto:
                    return "femto";
                case Name::atto:
                    return "atto";
                case Name::zepto:
                    return "zepto";
                case Name::yocto:
                    return "yocto";
                case Name::ronto:
                    return "ronto";
                case Name::quecto:
                    return "quecto";
                default:
                    return "";
            }
        }

        std::string DecimalPrefix::getName(Symbol prefix)
        {
            switch (prefix)
            {
                case Symbol::Q:
                    return "quetta";
                case Symbol::R:
                    return "ronna";
                case Symbol::Y:
                    return "yotta";
                case Symbol::Z:
                    return "zetta";
                case Symbol::E:
                    return "exa";
                case Symbol::P:
                    return "peta";
                case Symbol::T:
                    return "tera";
                case Symbol::G:
                    return "giga";
                case Symbol::M:
                    return "mega";
                case Symbol::k:
                    return "kilo";
                case Symbol::h:
                    return "hecto";
                case Symbol::da:
                    return "deca";
                case Symbol::base:
                    return "";
                case Symbol::d:
                    return "deci";
                case Symbol::c:
                    return "centi";
                case Symbol::m:
                    return "milli";
                case Symbol::mu:
                    return "micro";
                case Symbol::n:
                    return "nano";
                case Symbol::p:
                    return "pico";
                case Symbol::f:
                    return "femto";
                case Symbol::a:
                    return "atto";
                case Symbol::z:
                    return "zepto";
                case Symbol::y:
                    return "yocto";
                case Symbol::r:
                    return "ronto";
                case Symbol::q:
                    return "quecto";
                default:
                    return "";
            }
        }

        std::string DecimalPrefix::getSymbol(Name prefix)
        {
            switch (prefix)
            {
                case Name::quetta:
                    return "Q";
                case Name::ronna:
                    return "R";
                case Name::yotta:
                    return "Y";
                case Name::zetta:
                    return "Z";
                case Name::exa:
                    return "E";
                case Name::peta:
                    return "P";
                case Name::tera:
                    return "T";
                case Name::giga:
                    return "G";
                case Name::mega:
                    return "M";
                case Name::kilo:
                    return "k";
                case Name::hecto:
                    return "h";
                case Name::deca:
                    return "da";
                case Name::base:
                    return "";
                case Name::deci:
                    return "d";
                case Name::centi:
                    return "c";
                case Name::milli:
                    return "m";
                case Name::micro:
                    return "\u03BC";  // Greek letter mu
                case Name::nano:
                    return "n";
                case Name::pico:
                    return "p";
                case Name::femto:
                    return "f";
                case Name::atto:
                    return "a";
                case Name::zepto:
                    return "z";
                case Name::yocto:
                    return "y";
                case Name::ronto:
                    return "r";
                case Name::quecto:
                    return "q";
                default:
                    return "";
            }
        }

        std::string DecimalPrefix::getSymbol(Symbol prefix)
        {
            switch (prefix)
            {
                case Symbol::Q:
                    return "Q";
                case Symbol::R:
                    return "R";
                case Symbol::Y:
                    return "Y";
                case Symbol::Z:
                    return "Z";
                case Symbol::E:
                    return "E";
                case Symbol::P:
                    return "P";
                case Symbol::T:
                    return "T";
                case Symbol::G:
                    return "G";
                case Symbol::M:
                    return "M";
                case Symbol::k:
                    return "k";
                case Symbol::h:
                    return "h";
                case Symbol::da:
                    return "da";
                case Symbol::base:
                    return "";
                case Symbol::d:
                    return "d";
                case Symbol::c:
                    return "c";
                case Symbol::m:
                    return "m";
                case Symbol::mu:
                    return "\u03BC";  // Greek letter mu
                case Symbol::n:
                    return "n";
                case Symbol::p:
                    return "p";
                case Symbol::f:
                    return "f";
                case Symbol::a:
                    return "a";
                case Symbol::z:
                    return "z";
                case Symbol::y:
                    return "y";
                case Symbol::r:
                    return "r";
                case Symbol::q:
                    return "q";
                default:
                    return "";
            }
        }

        double DecimalPrefix::getMultiplier(Symbol prefix)
        {
            return std::pow(10.0, static_cast<int>(prefix));
        }

        double DecimalPrefix::getMultiplier(Name prefix)
        {
            return std::pow(10.0, static_cast<int>(prefix));
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX