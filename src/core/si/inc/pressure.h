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
 * @file pressure.h
 * @brief Declaration of the Pressure class.
 *
 * @date 14, Apr 2025
 */

#ifndef INERTIAFX_CORE_SI_PRESSURE_H
#define INERTIAFX_CORE_SI_PRESSURE_H

#include "derived_vector_qty.h"
#include <array>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Pressure
         * @brief Concrete derived quantity representing pressure.
         */
        class Pressure : public DerivedVectorQty
        {
          public:
            /**
             * @brief Constructs a new Pressure object.
             *
             * The pressure is initialized as (0.0, 0.0, 0.0) and is stored in base prefix
             * value.
             */
            Pressure();

            /**
             * @brief Constructs a new Pressure object.
             * @param value The numeric value of pressure vector in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the pressure is stored in base prefix value.
             */
            Pressure(std::array<double, 3> value,
                     DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            /**
             * @brief Constructs a new Pressure object.
             * @param value The numeric value of pressure vector in the specified prefix.
             * @param prefix The decimal prefix symbol (e.g., "k", "m") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the pressure is stored in base prefix value.
             */
            Pressure(std::array<double, 3> value,
                     DecimalPrefix::Symbol prefix = DecimalPrefix::Symbol::base);

            /**
             * @brief Copy constructor.
             * @details Constructs a new Pressure object from an existing one.
             *
             * @param other The other Pressure object to copy from.
             */
            Pressure(const Pressure &other);

            /**
             * @brief Copy assignment operator.
             * @details Constructs a new Pressure object from an existing one.
             *
             * @param other The other Pressure object to copy from.
             * @return A reference to this object.
             *
             * @note This operator performs a deep copy of the object.
             */
            Pressure &operator=(const Pressure &other);

            /**
             * @brief Addition operator.
             * @details Adds two Pressure objects together.
             *
             * @param other The other Pressure object to add.
             * @return A new Pressure object representing the sum.
             */
            Pressure operator+(const Pressure &other) const;

            /**
             * @brief Equality operator.
             * @details Compares two Pressure objects for equality.
             *
             * @param other The other Pressure object to compare.
             * @return True if the objects are equal, false otherwise.
             */
            bool operator==(const Pressure &other) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_PRESSURE_H
