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
 * @file force.cpp
 * @brief Definition of the Force class.
 *
 * @date 03, Apr 2025
 */

#include "force.h"
#include "decimal_prefix.h"
#include "newton.h"
#include <array>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Force::Force() :
            DerivedVectorQty("Force", "F", "Represents the derived SI Force quantity.",
                             std::make_unique<Newton>())
        {
            // Store internally in base units
            this->_value[0] = 0.0;
            this->_value[1] = 0.0;
            this->_value[2] = 0.0;

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

        // Constructor
        Force::Force(std::array<double, 3> value, DecimalPrefix::Name prefix) :
            DerivedVectorQty("Force", "F", "Represents the derived SI Force quantity.",
                             std::make_unique<Newton>())
        {
            // Store internally in base units
            this->_value[0] = value[0] * DecimalPrefix::getMultiplier(prefix);
            this->_value[1] = value[1] * DecimalPrefix::getMultiplier(prefix);
            this->_value[2] = value[2] * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }

        // Constructor
        Force::Force(std::array<double, 3> value, DecimalPrefix::Symbol prefix) :
            DerivedVectorQty("Force", "F", "Represents the derived SI Force quantity.",
                             std::make_unique<Newton>())
        {
            // Store internally in base units
            this->_value[0] = value[0] * DecimalPrefix::getMultiplier(prefix);
            this->_value[1] = value[1] * DecimalPrefix::getMultiplier(prefix);
            this->_value[2] = value[2] * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = static_cast<DecimalPrefix::Name>(prefix);
        }

        Force::Force(const Force &other) :
            DerivedVectorQty("Force", "F", "Represents the derived SI Force quantity.",
                             std::make_unique<Newton>())
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;
        }

        Force &Force::operator=(const Force &other)
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

        Force Force::operator+(const Force &other) const
        {
            std::array<double, 3> newValue = {0.0, 0.0, 0.0};
            newValue[0]                    = this->getValue()[0] + other.getValue()[0];
            newValue[1]                    = this->getValue()[1] + other.getValue()[1];
            newValue[2]                    = this->getValue()[2] + other.getValue()[2];
            return Force(newValue, DecimalPrefix::Name::base);
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
