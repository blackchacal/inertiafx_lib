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
 * @file metre_per_second_sq.cpp
 * @brief Definition of the MetrePerSecondSq unit class.
 *
 * @date 16, Mar 2025
 */

#include "metre_per_second_sq.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string MetrePerSecondSq::DESCRIPTION =
            "The metre per second squared, symbol m s^-2 or m/s^2, is a derived SI unit of "
            "acceleration.";

        MetrePerSecondSq::MetrePerSecondSq() :
            PhysicalUnit("metre per second squared", "metres per second squared", "m s^-2",
                         DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
