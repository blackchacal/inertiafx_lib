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
 * @file mass.h
 * @brief Declaration of the Mass class.
 *
 * @date 23, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_MASS_H
#define INERTIAFX_CORE_SI_MASS_H

#include "fundamental_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Mass
         * @brief Concrete fundamental quantity representing mass.
         */
        class Mass : public FundamentalQty
        {
          public:
            /**
             * @brief Constructs a new Mass object.
             *
             * The mass is initialized to 1.0 and stored in base prefix value.
             */
            Mass();

            /**
             * @brief Constructs a new Mass object.
             * @param value The numeric value of mass in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the mass is stored in base prefix value.
             */
            Mass(double value, DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            Mass(const Mass &other);             // Copy constructor
            Mass &operator=(const Mass &other);  // Copy assignment operator
            Mass operator+(const Mass &other) const;
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_MASS_H
