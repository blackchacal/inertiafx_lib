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

#include "si_time.h"
#include "decimal_prefix.h"
#include "second.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Time::Time() :
            FundamentalQty("Time", "t", "Represents the fundamental SI Time quantity.",
                           std::make_unique<Second>())
        {
            // Store internally in base units
            this->_value = 1.0;

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

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

        Time::Time(const Time &other) :
            FundamentalQty("Time", "t", "Represents the fundamental SI Time quantity.",
                           std::make_unique<Second>())
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;
        }

        Time &Time::operator=(const Time &other)
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

        Time Time::operator+(const Time &other) const
        {
            return Time(this->getValue() + other.getValue());
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
