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
 * @file derived_physical_unit.cpp
 * @brief Definition of the DerivedPhysicalUnit class.
 *
 * @date 03, Apr 2025
 */

#include "derived_physical_unit.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        DerivedPhysicalUnit::DerivedPhysicalUnit(std::vector<PhysicalUnitPower> baseUnits,
                                                 const std::string &description) :
            _description(description)
        {
            // Initialize the name, plural name, and symbol based on the base units.
            // Combine base unit symbols and powers to create a derived unit symbol.
            for (const auto &baseUnit : baseUnits)
            {
                _symbol +=
                    baseUnit.unit->getSymbol() +
                    ((baseUnit.power == 1) ? " " : "^" + std::to_string(baseUnit.power) + " ");
                _name += buildBaseUnitName(baseUnit) + " ";
                _pluralName += buildBaseUnitPluralName(baseUnit) + " ";
            }
            _symbol.pop_back();      // Remove trailing space
            _name.pop_back();        // Remove trailing space
            _pluralName.pop_back();  // Remove trailing space
        }

        std::string DerivedPhysicalUnit::getName() const
        {
            return _name;
        }

        std::string DerivedPhysicalUnit::getPluralName() const
        {
            return _pluralName;
        }

        std::string DerivedPhysicalUnit::getSymbol() const
        {
            return _symbol;
        }

        std::string DerivedPhysicalUnit::getDescription() const
        {
            return _description;
        }

        std::string DerivedPhysicalUnit::toString() const
        {
            // Example output for meters: "m"
            return _symbol;
        }

        std::string DerivedPhysicalUnit::toString(DecimalPrefix::Name prefixName) const
        {
            // Example output for millimeters: "mm"
            std::string pSymbol = DecimalPrefix::getSymbol(prefixName);
            return pSymbol + _symbol;
        }

        std::string DerivedPhysicalUnit::toString(DecimalPrefix::Symbol prefixSymbol) const
        {
            // Example output for centimeters: "cm"
            std::string pSymbol = DecimalPrefix::getSymbol(prefixSymbol);
            return pSymbol + _symbol;
        }

        std::string DerivedPhysicalUnit::buildBaseUnitName(PhysicalUnitPower baseUnit) const
        {
            std::string unitPowerString = "";
            switch (baseUnit.power)
            {
                case -1:
                    unitPowerString = "per " + baseUnit.unit->getName();
                    break;
                case -2:
                    unitPowerString = "per " + baseUnit.unit->getName() + " squared";
                    break;
                case -3:
                    unitPowerString = "per cubic " + baseUnit.unit->getName();
                    break;
                case 1:
                    unitPowerString = baseUnit.unit->getName();
                    break;
                case 2:
                    unitPowerString = " square " + baseUnit.unit->getName();
                    break;
                case 3:
                    unitPowerString = "cubic " + baseUnit.unit->getName();
                    break;
                case 4:
                    unitPowerString = "quartic " + baseUnit.unit->getName();
                    break;
                default:
                    unitPowerString = baseUnit.unit->getName();
                    break;
            }
            return unitPowerString;
        }

        std::string DerivedPhysicalUnit::buildBaseUnitPluralName(PhysicalUnitPower baseUnit) const
        {
            std::string unitPowerString = "";
            switch (baseUnit.power)
            {
                case -1:
                    unitPowerString = "per " + baseUnit.unit->getName();
                    break;
                case -2:
                    unitPowerString = "per " + baseUnit.unit->getName() + " squared";
                    break;
                case -3:
                    unitPowerString = "per cubic " + baseUnit.unit->getName();
                    break;
                case 1:
                    unitPowerString = baseUnit.unit->getPluralName();
                    break;
                case 2:
                    unitPowerString = " square " + baseUnit.unit->getPluralName();
                    break;
                case 3:
                    unitPowerString = "cubic " + baseUnit.unit->getPluralName();
                    break;
                case 4:
                    unitPowerString = "quartic " + baseUnit.unit->getPluralName();
                    break;
                default:
                    unitPowerString = baseUnit.unit->getPluralName();
                    break;
            }
            return unitPowerString;
        }

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
