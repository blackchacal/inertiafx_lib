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
 * @file volume.h
 * @brief Declaration of the Volume class.
 *
 * @date 02, Apr 2025
 */

#ifndef INERTIAFX_CORE_SI_VOLUME_H
#define INERTIAFX_CORE_SI_VOLUME_H

#include "derived_scalar_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Volume
         * @brief Concrete derived scalar quantity representing volume.
         */
        class Volume : public DerivedScalarQty
        {
          public:
            /**
             * @brief Constructs a new Volume object.
             * @param value The numeric value of volume in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the volume is stored in base prefix value.
             */

            Volume(double value, DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            Volume(const Volume &)            = default;  // Copy constructor
            Volume &operator=(const Volume &) = default;  // Copy assignment operator
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_VOLUME_H
