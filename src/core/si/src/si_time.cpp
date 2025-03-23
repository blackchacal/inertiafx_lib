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
 * @file si_time.cpp
 * @brief Definition of the Time class.
 *
 * @date 23, Mar 2025
 */

#include "decimal_prefix.h"
#include "second.h"
#include "si_time.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Time::Time(double value, DecimalPrefix::Name prefix) :
            FundamentalQty("Time", "t", "Represents the fundamental SI Time quantity.",
                           std::make_unique<Second>())
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
