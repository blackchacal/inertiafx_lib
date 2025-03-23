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
 * @file iphysical_qty.h
 * @brief Declaration of the IPhysicalQty interface.
 *
 * @date 19, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_IPHYSICALQTY_H
#define INERTIAFX_CORE_SI_IPHYSICALQTY_H

#include "decimal_prefix.h"
#include <string>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @interface IPhysicalQty
         * @brief Interface defining the required operations for physical quantities
         *        such as temperature, speed, force, etc.
         */
        class IPhysicalQty
        {
          public:
            /**
             * @brief Virtual destructor for interface cleanup.
             */
            virtual ~IPhysicalQty() = default;

            /**
             * @brief Retrieves the name of the physical quantity.
             * @return A string representing the name (e.g., "Temperature", "Speed").
             */
            virtual std::string getName() const = 0;

            /**
             * @brief Retrieves the symbol of the physical quantity.
             * @return A string representing the symbol (e.g., "T", "v").
             */
            virtual std::string getSymbol() const = 0;

            /**
             * @brief Retrieves the description of the physical quantity.
             * @return A string detailing the quantity's meaning or usage.
             */
            virtual std::string getDescription() const = 0;

            /**
             * @brief Indicates if this quantity is fundamental.
             * @return true if fundamental, false otherwise.
             */
            virtual bool isFundamental() const = 0;

            /**
             * @brief Retrieves the name of the base unit associated with this quantity.
             * @return A string representing the base unit name (e.g., "Kelvin", "Meter/Second").
             */
            virtual std::string getUnitName() const = 0;

            /**
             * @brief Retrieves the symbol of the base unit associated with this quantity.
             * @return A string representing the base unit symbol (e.g., "K", "m/s").
             */
            virtual std::string getUnitSymbol() const = 0;

            /**
             * @brief Retrieves a description of the base unit for this quantity.
             * @return A string describing the unit's context or usage.
             */
            virtual std::string getUnitDescription() const = 0;

            /**
             * @brief Builds a string representation of the quantity and its current value in the
             * base unit.
             * @return A string with both the value and unit symbol (e.g., "25.0 K").
             */
            virtual std::string toString() const = 0;

            /**
             * @brief Builds a string representation of the quantity's value in a specified decimal
             * prefix of its base unit.
             * @param prefix The decimal prefix by name (e.g., "kilo", "milli").
             * @return A string with the value (converted to the specified prefix) and the
             * appropriate unit symbol.
             */
            virtual std::string toString(DecimalPrefix::Name prefix) const = 0;

            /**
             * @brief Builds a string representation of the quantity's value in a specified decimal
             * prefix of its base unit.
             * @param prefix The decimal prefix by symbol (e.g., "k", "m").
             * @return A string with the value (converted to the specified prefix) and the
             * appropriate unit symbol.
             */
            virtual std::string toString(DecimalPrefix::Symbol prefix) const = 0;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_IPHYSICALQTY_H
