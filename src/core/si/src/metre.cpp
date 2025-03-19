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
 * @file metre.cpp
 * @brief Definition of the Metre unit class.
 *
 * @date 16, Mar 2025
 */

#include "metre.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Metre::DESCRIPTION =
            "The metre, symbol m, is the SI unit of length."
            "It is defined by taking the fixed numerical value of the speed of light"
            " in vacuum c to be 299 792 458 when expressed in the unit m s^(–1), where the "
            "second is defined in terms of the caesium frequency ΔνCs.";

        Metre::Metre() : PhysicalUnit("metre", "metres", "m", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
