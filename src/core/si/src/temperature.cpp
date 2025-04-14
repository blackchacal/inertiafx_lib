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
 * @file temperature.cpp
 * @brief Definition of the Temperature class.
 *
 * @date 14, Apr 2025
 */

#include "temperature.h"
#include "decimal_prefix.h"
#include "kelvin.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Temperature::Temperature() :
            FundamentalQty("Temperature", "T",
                           "Represents the fundamental SI Temperature quantity.",
                           std::make_unique<Kelvin>())
        {
            // Store internally in base units
            this->_value = 273.15;  // Default to zero degree Celsius in Kelvin

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

        // Constructor
        Temperature::Temperature(double value, DecimalPrefix::Name prefix) :
            FundamentalQty("Temperature", "T",
                           "Represents the fundamental SI Temperature quantity.",
                           std::make_unique<Kelvin>())
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }

        // Constructor
        Temperature::Temperature(double value, DecimalPrefix::Symbol prefix) :
            FundamentalQty("Temperature", "T",
                           "Represents the fundamental SI Temperature quantity.",
                           std::make_unique<Kelvin>())
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = static_cast<DecimalPrefix::Name>(prefix);
        }

        Temperature::Temperature(const Temperature &other) :
            FundamentalQty("Temperature", "T",
                           "Represents the fundamental SI Temperature quantity.",
                           std::make_unique<Kelvin>())
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;
        }

        Temperature &Temperature::operator=(const Temperature &other)
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

        Temperature Temperature::operator+(const Temperature &other) const
        {
            return Temperature(this->getValue() + other.getValue(), DecimalPrefix::Name::base);
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
