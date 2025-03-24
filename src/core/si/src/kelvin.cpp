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
 * @file kelvin.cpp
 * @brief Definition of the Kelvin unit class.
 *
 * @date 24, Mar 2025
 */

#include "kelvin.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Kelvin::DESCRIPTION =
            "The kelvin, symbol K, is the SI unit of thermodynamic "
            "temperature. It is defined by taking the fixed numerical "
            "value of the Boltzmann constant k to be 1.380 649 x 10^–23 "
            "when expressed in the unit J K^–1, which is equal to kg "
            "m^2 s^–2 K^–1, where the kilogram, metre and second are "
            "defined in terms of h, c and ΔνCs.";

        Kelvin::Kelvin() : PhysicalUnit("kelvin", "kelvins", "K", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
