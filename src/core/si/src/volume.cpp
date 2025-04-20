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
 * @file volume.cpp
 * @brief Definition of the Volume class.
 *
 * @date 02, Apr 2025
 */

#include "volume.h"
#include "decimal_prefix.h"
#include "derived_physical_unit.h"
#include "metre.h"
#include <cmath>
#include <numbers>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        // Constructor
        Volume::Volume() :
            _length(1.0), _width(1.0), _height(1.0), _radius(0.0), _type(Type::Box),
            DerivedScalarQty(
                "Volume", "V", "Represents the derived SI Volume quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{PhysicalUnitPower{std::make_unique<Metre>(), 3}},
                    "The cubic metre, symbol m^3, is an SI coherent derived unit of volume."))
        {
            // Store internally in base units
            this->_value = 1.0;

            // Optionally store the base prefix for reference or user logic
            this->_prefix = DecimalPrefix::Name::base;
        }

        // Constructor
        Volume::Volume(double length, double width, double height, DecimalPrefix::Name prefix) :
            _length(length), _width(width), _height(height), _radius(0.0), _type(Type::Box),
            DerivedScalarQty(
                "Volume", "V", "Represents the derived SI Volume quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{PhysicalUnitPower{std::make_unique<Metre>(), 3}},
                    "The cubic metre, symbol m^3, is an SI coherent derived unit of volume."))
        {
            // Store internally in base units
            this->_value = length * DecimalPrefix::getMultiplier(prefix) * width *
                           DecimalPrefix::getMultiplier(prefix) * height *
                           DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }

        // Constructor
        Volume::Volume(double length, double width, double height, DecimalPrefix::Symbol prefix) :
            _length(length), _width(width), _height(height), _radius(0.0), _type(Type::Box),
            DerivedScalarQty(
                "Volume", "V", "Represents the derived SI Volume quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{PhysicalUnitPower{std::make_unique<Metre>(), 3}},
                    "The cubic metre, symbol m^3, is an SI coherent derived unit of volume."))
        {
            // Store internally in base units
            this->_value = length * DecimalPrefix::getMultiplier(prefix) * width *
                           DecimalPrefix::getMultiplier(prefix) * height *
                           DecimalPrefix::getMultiplier(prefix);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = static_cast<DecimalPrefix::Name>(prefix);
        }

        // Constructor
        Volume::Volume(double radius, DecimalPrefix::Name prefix) :
            _length(0.0), _width(0.0), _height(0.0), _radius(radius), _type(Type::Sphere),
            DerivedScalarQty(
                "Volume", "V", "Represents the derived SI Volume quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{PhysicalUnitPower{std::make_unique<Metre>(), 3}},
                    "The cubic metre, symbol m^3, is an SI coherent derived unit of volume."))
        {
            // Store internally in base units
            this->_value = (4.0 / 3.0) * std::numbers::pi *
                           std::pow(radius * DecimalPrefix::getMultiplier(prefix), 3);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = prefix;
        }

        // Constructor
        Volume::Volume(double radius, DecimalPrefix::Symbol prefix) :
            _length(0.0), _width(0.0), _height(0.0), _radius(radius), _type(Type::Sphere),
            DerivedScalarQty(
                "Volume", "V", "Represents the derived SI Volume quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{PhysicalUnitPower{std::make_unique<Metre>(), 3}},
                    "The cubic metre, symbol m^3, is an SI coherent derived unit of volume."))
        {

            // Store internally in base units
            this->_value = (4.0 / 3.0) * std::numbers::pi *
                           std::pow(radius * DecimalPrefix::getMultiplier(prefix), 3);

            // Optionally store the chosen prefix for reference or user logic
            this->_prefix = static_cast<DecimalPrefix::Name>(prefix);
        }

        Volume::Volume(const Volume &other) :
            DerivedScalarQty(
                "Volume", "V", "Represents the derived SI Volume quantity.",
                std::make_unique<DerivedPhysicalUnit>(
                    std::vector<PhysicalUnitPower>{PhysicalUnitPower{std::make_unique<Metre>(), 3}},
                    "The cubic metre, symbol m^3, is an SI coherent derived unit of volume."))
        {
            // Copy constructor
            _value  = other._value;
            _unit   = other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            _prefix = other._prefix;

            _length = other._length;
            _width  = other._width;
            _height = other._height;
            _radius = other._radius;
            _type   = other._type;
        }

        Volume &Volume::operator=(const Volume &other)
        {
            // Copy assignment operator
            if (this != &other)
            {
                _value  = other._value;
                _prefix = other._prefix;

                _length = other._length;
                _width  = other._width;
                _height = other._height;
                _radius = other._radius;
                _type   = other._type;

                // If there's an existing owned object, remove it
                _unit.reset();

                // Deep-copy from other
                _unit =
                    other._unit ? std::unique_ptr<IPhysicalUnit>(other._unit->clone()) : nullptr;
            }
            return *this;
        }

        Volume Volume::operator+(const Volume &other) const
        {
            Volume vol;
            vol.setValue(this->getValue() + other.getValue());
            return vol;
        }

        bool Volume::operator==(const Volume &other) const
        {
            constexpr double EPS = 1e-9;
            return std::abs(_value - other._value) < EPS && _prefix == other._prefix &&
                   _type == other._type && std::abs(_length - other._length) < EPS &&
                   std::abs(_width - other._width) < EPS &&
                   std::abs(_height - other._height) < EPS &&
                   std::abs(_radius - other._radius) < EPS;
        }

        std::tuple<double, double, double> Volume::getBoxDimensions() const
        {
            return std::make_tuple(_length, _width, _height);
        }

        double Volume::getSphereDimensions() const
        {
            return _radius;
        }

        Volume::Type Volume::getType() const
        {
            return _type;
        }

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
