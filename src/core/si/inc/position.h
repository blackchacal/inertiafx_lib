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
 * @file position.h
 * @brief Declaration of the Position class.
 *
 * @date 25, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_POSITION_H
#define INERTIAFX_CORE_SI_POSITION_H

#include "derived_vector_qty.h"
#include <array>

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Position
         * @brief Concrete derived quantity representing position in space.
         */
        class Position : public DerivedVectorQty
        {
          public:
            /**
             * @brief Constructs a new Position object.
             * @param value The numeric value of position vector in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'value' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the position is stored in base prefix value.
             */
            Position(std::array<double, 3> value,
                     DecimalPrefix::Name prefix = DecimalPrefix::Name::base);
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_POSITION_H
