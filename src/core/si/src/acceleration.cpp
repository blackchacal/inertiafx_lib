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
 * @file acceleration.cpp
 * @brief Definition of the Acceleration class.
 *
 * @date 25, Mar 2025
 */

#include "acceleration.h"
#include "decimal_prefix.h"
#include "derived_physical_unit.h"
#include "metre.h"
#include "second.h"
#include <array>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Acceleration::Acceleration() :
            DerivedVectorQty(
                "Acceleration", "a", "Represents the derived SI Acceleration quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{
                        PhysicalUnitPower{std::make_unique<Metre>(), 1},
                        PhysicalUnitPower{std::make_unique<Second>(), -2}},
                    "The metre per second squared, symbol m s^-2, is an SI coherent derived "
                    "unit of acceleration."))
        {
            // Store internally in base units
            this->_value[0] = 0.0;
            this->_value[1] = 0.0;
            this->_value[2] = 0.0;

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

        // Constructor
        Acceleration::Acceleration(std::array<double, 3> value, DecimalPrefix::Name prefix) :
            DerivedVectorQty(
                "Acceleration", "a", "Represents the derived SI Acceleration quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{
                        PhysicalUnitPower{std::make_unique<Metre>(), 1},
                        PhysicalUnitPower{std::make_unique<Second>(), -2}},
                    "The metre per second squared, symbol m s^-2, is an SI coherent derived "
                    "unit of acceleration."))
        {
            // Store internally in base units
            this->_value[0] = value[0] * DecimalPrefix::getMultiplier(prefix);
            this->_value[1] = value[1] * DecimalPrefix::getMultiplier(prefix);
            this->_value[2] = value[2] * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }

        Acceleration::Acceleration(const Acceleration &other) :
            DerivedVectorQty(
                "Acceleration", "a", "Represents the derived SI Acceleration quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{
                        PhysicalUnitPower{std::make_unique<Metre>(), 1},
                        PhysicalUnitPower{std::make_unique<Second>(), -2}},
                    "The metre per second squared, symbol m s^-2, is an SI coherent derived "
                    "unit of acceleration."))
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;
        }

        Acceleration &Acceleration::operator=(const Acceleration &other)
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

        Acceleration Acceleration::operator+(const Acceleration &other) const
        {
            std::array<double, 3> newValue = {0.0, 0.0, 0.0};
            newValue[0]                    = this->getValue()[0] + other.getValue()[0];
            newValue[1]                    = this->getValue()[1] + other.getValue()[1];
            newValue[2]                    = this->getValue()[2] + other.getValue()[2];
            return Acceleration(newValue);
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
