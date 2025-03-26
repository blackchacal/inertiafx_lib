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
 * @file metre_per_second.cpp
 * @brief Definition of the MetrePerSecond unit class.
 *
 * @date 16, Mar 2025
 */

#include "metre_per_second.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string MetrePerSecond::DESCRIPTION =
            "The metre per second, symbol m s^-1 or m/s, is a derived SI unit of speed or "
            "velocity.";

        MetrePerSecond::MetrePerSecond() :
            PhysicalUnit("metre per second", "metres per second", "m s^-1", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
