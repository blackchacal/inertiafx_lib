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
 * @file iphysical_unit.h
 * @brief Declaration of the IPhysicalUnit interface.
 *
 * @date 16, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_IPHYSICALUNIT_H
#define INERTIAFX_CORE_SI_IPHYSICALUNIT_H

#include "decimal_prefix.h"
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class IPhysicalUnit
         * @brief Interface representing the behavior and attributes of a physical unit.
         *
         * This interface defines the core methods any physical unit should implement,
         * including retrieving the unit's name, symbol, description, and string representations
         * with optional decimal prefixes.
         */
        class IPhysicalUnit
        {
          public:
            /**
             * @brief Virtual destructor for safe polymorphic destruction.
             */
            virtual ~IPhysicalUnit() = default;

            /**
             * @brief Get the full name of the unit.
             * @return A std::string containing the unit name.
             */
            virtual std::string getName() const = 0;

            /**
             * @brief Get the full name of the unit in plural form.
             * @return A std::string containing the unit name.
             */
            virtual std::string getNamePlural() const = 0;

            /**
             * @brief Get the symbol of the unit.
             * @return A std::string containing the unit symbol.
             */
            virtual std::string getSymbol() const = 0;

            /**
             * @brief Get a brief description of the unit.
             * @return A std::string containing the unit description.
             */
            virtual std::string getDescription() const = 0;

            /**
             * @brief Get a string representation of the unit without any prefix.
             * @return A std::string representing the unit in its standard form.
             */
            virtual std::string toString() const = 0;

            /**
             * @brief Get a string representation of the unit using a specified decimal prefix name.
             * @param prefixName The decimal prefix name to prepend to the unit.
             * @return A std::string representing the prefixed unit.
             */
            virtual std::string toString(DecimalPrefix::Name prefixName) const = 0;

            /**
             * @brief Get a string representation of the unit using a specified decimal prefix
             * symbol.
             * @param prefixSymbol The decimal prefix symbol to prepend to the unit.
             * @return A std::string representing the prefixed unit.
             */
            virtual std::string toString(DecimalPrefix::Symbol prefixSymbol) const = 0;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_IPHYSICALUNIT_H
