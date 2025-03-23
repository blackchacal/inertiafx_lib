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
 * @file iscalar_qty.h
 * @brief Declaration of the IScalarQty interface.
 *
 * @date 23, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_ISCALARQTY_H
#define INERTIAFX_CORE_SI_ISCALARQTY_H

#include "decimal_prefix.h"
#include "iphysical_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @interface IScalarQty
         * @brief Interface defining the required operations for scalar physical quantities.
         */
        class IScalarQty : IPhysicalQty
        {
          public:
            /**
             * @brief Virtual destructor for interface cleanup.
             */
            virtual ~IScalarQty() = default;

            /**
             * @brief Retrieves the current value of the physical quantity in its base unit.
             * @return The value of the quantity in its base unit.
             */
            virtual double getValue() const = 0;

            /**
             * @brief Retrieves the current value of the physical quantity in the specified prefix
             * of its base unit.
             * @param prefix The decimal prefix by name (e.g., "kilo", "milli").
             * @return The value of the quantity converted to the requested prefix.
             */
            virtual double getValueIn(DecimalPrefix::Name prefix) const = 0;

            /**
             * @brief Retrieves the current value of the physical quantity in the specified prefix
             * of its base unit.
             * @param prefix The decimal prefix by symbol (e.g., "k", "m").
             * @return The value of the quantity converted to the requested prefix.
             */
            virtual double getValueIn(DecimalPrefix::Symbol prefix) const = 0;

            /**
             * @brief Sets the value of this physical quantity.
             * @param newValue The new value to assign in base unit.
             */
            virtual void setValue(double newValue) = 0;

            /**
             * @brief Sets the value of this physical quantity (in a specific prefix of its base
             * unit).
             * @param newValue The new value to assign.
             * @param prefix The decimal prefix by name (e.g., "kilo", "milli").
             */
            virtual void setValueFrom(double newValue, DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the value of this physical quantity (in a specific prefix of its base
             * unit).
             * @param newValue The new value to assign.
             * @param prefix The decimal prefix by symbol (e.g., "k", "m").
             */
            virtual void setValueFrom(double newValue, DecimalPrefix::Symbol prefix) = 0;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_ISCALARQTY_H
