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
        Length::Length() :
            FundamentalQty("Length", "l", "Represents the fundamental SI Length quantity.",
                           std::make_unique<Metre>())
        {
            // Store internally in base units
            this->_value = 1.0;

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

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

        // Constructor
        Length::Length(double value, DecimalPrefix::Symbol prefix) :
            FundamentalQty("Length", "l", "Represents the fundamental SI Length quantity.",
                           std::make_unique<Metre>())
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = static_cast<DecimalPrefix::Name>(prefix);
        }

        Length::Length(const Length &other) :
            FundamentalQty("Length", "l", "Represents the fundamental SI Length quantity.",
                           std::make_unique<Metre>())
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;
        }

        Length &Length::operator=(const Length &other)
        {
            // Copy assignment operator
            if (this != &other)
            {
                _value  = other._value;
                _prefix = other._prefix;

                // If there's an existing owned object, remove it
                _unit.reset();

                // Deep-copy from other
                _unit =
                    other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            }
            return *this;
        }

        Length Length::operator+(const Length &other) const
        {
            return Length(this->getValue() + other.getValue(), DecimalPrefix::Name::base);
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
