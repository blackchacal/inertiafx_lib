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
 * @file length.cpp
 * @brief Definition of the Length class.
 *
 * @date 22, Mar 2025
 */

#include "length.h"
#include "decimal_prefix.h"
#include "metre.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Length::Length(double value, DecimalPrefix::Name prefix) :
            FundamentalQty("Length", "l", "Represents the fundamental SI Length quantity.",
                           std::make_unique<Metre>())
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
