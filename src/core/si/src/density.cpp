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
 * @file density.cpp
 * @brief Definition of the Density class.
 *
 * @date 09, Apr 2025
 */

#include "density.h"
#include "decimal_prefix.h"
#include "derived_physical_unit.h"
#include "kilogram.h"
#include "metre.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Density::Density() :
            DerivedScalarQty("Density", "ρ", "Represents the derived SI Density quantity.",
                             std::make_unique<DerivedPhysicalUnit>(
                                 std::vector<PhysicalUnitPower>{
                                     PhysicalUnitPower{std::make_unique<Kilogram>(), 1},
                                     PhysicalUnitPower{std::make_unique<Metre>(), -3}},
                                 "The kilogram per cubic metre, symbol kg m^-3, is an SI coherent "
                                 "derived unit of density."))
        {
            // Store internally in base units
            this->_value = 1.0;

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

        // Constructor
        Density::Density(double value, DecimalPrefix::Name prefix) :
            DerivedScalarQty("Density", "ρ", "Represents the derived SI Density quantity.",
                             std::make_unique<DerivedPhysicalUnit>(
                                 std::vector<PhysicalUnitPower>{
                                     PhysicalUnitPower{std::make_unique<Kilogram>(), 1},
                                     PhysicalUnitPower{std::make_unique<Metre>(), -3}},
                                 "The kilogram per cubic metre, symbol kg m^-3, is an SI coherent "
                                 "derived unit of density."))
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }

        // Constructor
        Density::Density(double value, DecimalPrefix::Symbol prefix) :
            DerivedScalarQty("Density", "ρ", "Represents the derived SI Density quantity.",
                             std::make_unique<DerivedPhysicalUnit>(
                                 std::vector<PhysicalUnitPower>{
                                     PhysicalUnitPower{std::make_unique<Kilogram>(), 1},
                                     PhysicalUnitPower{std::make_unique<Metre>(), -3}},
                                 "The kilogram per cubic metre, symbol kg m^-3, is an SI coherent "
                                 "derived unit of density."))
        {
            // Store internally in base units
            this->_value = value * DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = static_cast<DecimalPrefix::Name>(prefix);
        }

        Density::Density(const Density &other) :
            DerivedScalarQty("Density", "ρ", "Represents the derived SI Density quantity.",
                             std::make_unique<DerivedPhysicalUnit>(
                                 std::vector<PhysicalUnitPower>{
                                     PhysicalUnitPower{std::make_unique<Kilogram>(), 1},
                                     PhysicalUnitPower{std::make_unique<Metre>(), -3}},
                                 "The kilogram per cubic metre, symbol kg m^-3, is an SI coherent "
                                 "derived unit of density."))
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;
        }

        Density &Density::operator=(const Density &other)
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

        Density Density::operator+(const Density &other) const
        {
            return Density(this->getValue() + other.getValue(), DecimalPrefix::Name::base);
        }

        bool Density::operator==(const Density &other) const
        {
            constexpr double EPS = 1e-9;
            return std::abs(_value - other._value) < EPS && _prefix == other._prefix;
        }
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
