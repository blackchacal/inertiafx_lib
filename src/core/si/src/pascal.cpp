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
 * @file pascal.cpp
 * @brief Definition of the Pascal unit class.
 *
 * @date 14, Apr 2025
 */

#include "pascal.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Static description string
        const std::string Pascal::DESCRIPTION =
            "The pascal, symbol Pa, is the SI unit of pressure."
            "It is defined as 1 newton per square metre (N/m^2)."
            "The pascal is named after Blaise Pascal, a French mathematician, physicist, and "
            "inventor.";

        Pascal::Pascal() : PhysicalUnit("pascal", "pascals", "Pa", DESCRIPTION)
        {
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
