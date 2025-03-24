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
 * @file ampere.cpp
 * @brief Definition of the Ampere unit class.
 *
 * @date 24, Mar 2025
 */

#include "ampere.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Ampere::DESCRIPTION =
            "The ampere, symbol A, is the SI unit of electric current. It is "
            "defined by taking the fixed numerical value of the elementary "
            "charge e to be 1.602 176 634 x 10^–19 when expressed in the unit C, "
            "which is equal to A s, where the second is defined in terms of ΔνCs.";

        Ampere::Ampere() : PhysicalUnit("ampere", "amperes", "A", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
