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
 * @file density.h
 * @brief Declaration of the Density class.
 *
 * @date 09, Apr 2025
 */

#ifndef INERTIAFX_CORE_SI_DENSITY_H
#define INERTIAFX_CORE_SI_DENSITY_H

#include "derived_scalar_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Density
         * @brief Concrete derived scalar quantity representing density.
         */
        class Density : public DerivedScalarQty
        {
          public:
            /**
             * @brief Constructs a new Density object.
             *
             * The density is initialized to 1.0 and stored in base prefix value.
             */
            Density();

            /**
             * @brief Constructs a new Density object.
             * @param value The numeric value of density in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the density is stored in base prefix value.
             */
            Density(double value, DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            /**
             * @brief Constructs a new Density object.
             * @param value The numeric value of density in the specified prefix.
             * @param prefix The decimal prefix symbol (e.g., "k", "m") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the density is stored in base prefix value.
             */
            Density(double value, DecimalPrefix::Symbol prefix = DecimalPrefix::Symbol::base);

            /**
             * @brief Copy constructor.
             * @details Constructs a new Density object from an existing one.
             *
             * @param other The other Density object to copy from.
             */
            Density(const Density &other);

            /**
             * @brief Copy assignment operator.
             * @details Constructs a new Density object from an existing one.
             *
             * @param other The other Density object to copy from.
             * @return A reference to this object.
             *
             * @note This operator performs a deep copy of the object.
             */
            Density &operator=(const Density &other);

            /**
             * @brief Addition operator.
             * @details Adds two Density objects together.
             *
             * @param other The other Density object to add.
             * @return A new Density object representing the sum.
             */
            Density operator+(const Density &other) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_DENSITY_H
