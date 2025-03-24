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
 * @file second.cpp
 * @brief Definition of the Second unit class.
 *
 * @date 18, Mar 2025
 */

#include "second.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Second::DESCRIPTION =
            "The second, symbol s, is the SI unit of time. "
            "It is defined by taking the fixed numerical value of the caesium"
            "frequency ΔνCs, the unperturbed ground-state hyperfine transition "
            "frequency of the caesium-133 atom, to be 9 192 631 770 when expressed"
            " in the unit Hz, which is equal to s^–1.";

        Second::Second() : PhysicalUnit("second", "seconds", "s", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
