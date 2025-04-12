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
 * @file velocity.h
 * @brief Declaration of the Velocity class.
 *
 * @date 25, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_VELOCITY_H
#define INERTIAFX_CORE_SI_VELOCITY_H

#include "derived_vector_qty.h"
#include <array>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Velocity
         * @brief Concrete derived quantity representing velocity.
         */
        class Velocity : public DerivedVectorQty
        {
          public:
            /**
             * @brief Constructs a new Velocity object.
             *
             * The velocity is initialized to (0.0, 0.0, 0.0) and is stored in base prefix value.
             */
            Velocity();

            /**
             * @brief Constructs a new Velocity object.
             * @param value The numeric value of velocity vector in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the velocity is stored in base prefix value.
             */
            Velocity(std::array<double, 3> value,
                     DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            Velocity(const Velocity &);             // Copy constructor
            Velocity &operator=(const Velocity &);  // Copy assignment operator
            Velocity operator+(const Velocity &other) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_VELOCITY_H
