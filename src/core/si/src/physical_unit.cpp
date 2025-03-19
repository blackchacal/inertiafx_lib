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
 * @file physical_unit.cpp
 * @brief Definition of the PhysicalUnit class.
 *
 * @date 16, Mar 2025
 */

#include "physical_unit.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        PhysicalUnit::PhysicalUnit(const std::string &name, const std::string &namePlural,
                                   const std::string &symbol, const std::string &description) :
            _name(name), _namePlural(namePlural), _symbol(symbol), _description(description)
        {
        }

        PhysicalUnit::~PhysicalUnit()
        {
        }

        std::string PhysicalUnit::getName() const
        {
            return _name;
        }

        std::string PhysicalUnit::getNamePlural() const
        {
            return _namePlural;
        }

        std::string PhysicalUnit::getSymbol() const
        {
            return _symbol;
        }

        std::string PhysicalUnit::getDescription() const
        {
            return _description;
        }

        std::string PhysicalUnit::toString() const
        {
            // Example output for meters: "m"
            return _symbol;
        }

        std::string PhysicalUnit::toString(DecimalPrefix::Name prefixName) const
        {
            // Example output for millimeters: "mm"
            std::string pSymbol = DecimalPrefix::getSymbol(prefixName);
            return pSymbol + _symbol;
        }

        std::string PhysicalUnit::toString(DecimalPrefix::Symbol prefixSymbol) const
        {
            // Example output for centimeters: "cm"
            std::string pSymbol = DecimalPrefix::getSymbol(prefixSymbol);
            return pSymbol + _symbol;
        }

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX
