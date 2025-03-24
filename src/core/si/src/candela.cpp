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
 * @file candela.cpp
 * @brief Definition of the Candela unit class.
 *
 * @date 24, Mar 2025
 */

#include "candela.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Candela::DESCRIPTION =
            "The candela, symbol cd, is the SI unit of luminous intensity "
            "in a given direction. It is defined by taking the fixed numerical "
            "value of the luminous efficacy of monochromatic radiation of "
            "frequency 540 x 1012 Hz, Kcd, to be 683 when expressed in the unit "
            "lm W^–1, which is equal to cd sr W^–1, or cd sr kg^–1 m^–2 s^3, where "
            "the kilogram, metre and second are defined in terms of h, c and ΔνCs.";

        Candela::Candela() : PhysicalUnit("candela", "candelas", "cd", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
