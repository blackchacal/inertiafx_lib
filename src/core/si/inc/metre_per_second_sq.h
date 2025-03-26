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
 * @file metre_per_second_sq.h
 * @brief Declaration of the MetrePerSecondSq unit class.
 *
 * @date 25, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_METRE_PER_SECOND_SQ_H
#define INERTIAFX_CORE_SI_METRE_PER_SECOND_SQ_H

#include "physical_unit.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class MetrePerSecondSq
         * @brief Represents the SI base unit of length.
         */
        class MetrePerSecondSq : public PhysicalUnit
        {
          private:
            static const std::string DESCRIPTION; /**< Detailed description of this unit. */

          public:
            /**
             * @brief Default constructor initializing MetrePerSecondSq unit properties.
             */
            MetrePerSecondSq();

            /**
             * @brief Default destructor.
             */
            ~MetrePerSecondSq() = default;
        };
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_METRE_PER_SECOND_SQ_H
