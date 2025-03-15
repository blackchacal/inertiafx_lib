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
                case Symbol::none:
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
                case Name::none:
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