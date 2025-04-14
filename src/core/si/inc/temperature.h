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
 * @file temperature.h
 * @brief Declaration of the Temperature class.
 *
 * @date 14, Apr 2025
 */

#ifndef INERTIAFX_CORE_SI_TEMPERATURE_H
#define INERTIAFX_CORE_SI_TEMPERATURE_H

#include "fundamental_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Temperature
         * @brief Concrete fundamental quantity representing temperature.
         */
        class Temperature : public FundamentalQty
        {
          public:
            /**
             * @brief Constructs a new Temperature object.
             *
             * The temperature is initialized to 273.15 and stored in base prefix value.
             */
            Temperature();

            /**
             * @brief Constructs a new Temperature object.
             * @param value The numeric value of temperature in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the temperature is stored in base prefix value.
             */
            Temperature(double value, DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            /**
             * @brief Constructs a new Temperature object.
             * @param value The numeric value of temperature in the specified prefix.
             * @param prefix The decimal prefix symbol (e.g., "k", "m") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the temperature is stored in base prefix value.
             */
            Temperature(double value, DecimalPrefix::Symbol prefix = DecimalPrefix::Symbol::base);

            /**
             * @brief Copy constructor.
             * @details Constructs a new Temperature object from an existing one.
             *
             * @param other The other Temperature object to copy from.
             */
            Temperature(const Temperature &other);

            /**
             * @brief Copy assignment operator.
             * @details Constructs a new Temperature object from an existing one.
             *
             * @param other The other Temperature object to copy from.
             * @return A reference to this object.
             *
             * @note This operator performs a deep copy of the object.
             */
            Temperature &operator=(const Temperature &other);

            /**
             * @brief Addition operator.
             * @details Adds two Temperature objects together.
             *
             * @param other The other Temperature object to add.
             * @return A new Temperature object representing the sum.
             */
            Temperature operator+(const Temperature &other) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_TEMPERATURE_H
