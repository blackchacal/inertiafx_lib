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
 * @file kilogram.cpp
 * @brief Definition of the Kilogram unit class.
 *
 * @date 18, Mar 2025
 */

#include "kilogram.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Kilogram::DESCRIPTION =
            "The kilogram, symbol kg, is the SI unit of mass. "
            "It is defined by taking the fixed numerical value of the"
            " Planck constant h to be 6.626 070 15 x 10–34 when expressed"
            " in the unit J s, which is equal to kg m2 s–1, where the metre"
            " and the second are defined in terms of c and ΔνCs.";

        Kilogram::Kilogram() : PhysicalUnit("kilogram", "kilograms", "kg", DESCRIPTION)
        {
        }

        std::string Kilogram::toString(DecimalPrefix::Name prefixName) const
        {
            std::string s;
            switch (prefixName)
            {
                case DecimalPrefix::Name::kilo:
                    s = "ton";
                    break;
                case DecimalPrefix::Name::deci:
                    s = "hg";
                    break;
                case DecimalPrefix::Name::centi:
                    s = "dag";
                    break;
                case DecimalPrefix::Name::milli:
                    s = "g";
                    break;
                case DecimalPrefix::Name::micro:
                    s = "mg";
                    break;
                case DecimalPrefix::Name::nano:
                    s = "\u03BCg";
                    break;
                default:
                    std::string pSymbol = DecimalPrefix::getSymbol(prefixName);
                    s                   = pSymbol + _symbol;
                    break;
            }
            return s;
        }

        std::string Kilogram::toString(DecimalPrefix::Symbol prefixSymbol) const
        {
            std::string s;
            switch (prefixSymbol)
            {
                case DecimalPrefix::Symbol::k:
                    s = "ton";
                    break;
                case DecimalPrefix::Symbol::d:
                    s = "hg";
                    break;
                case DecimalPrefix::Symbol::c:
                    s = "dag";
                    break;
                case DecimalPrefix::Symbol::m:
                    s = "g";
                    break;
                case DecimalPrefix::Symbol::mu:
                    s = "mg";
                    break;
                case DecimalPrefix::Symbol::n:
                    s = "\u03BCg";
                    break;
                default:
                    std::string pSymbol = DecimalPrefix::getSymbol(prefixSymbol);
                    s                   = pSymbol + _symbol;
                    break;
            }
            return s;
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
