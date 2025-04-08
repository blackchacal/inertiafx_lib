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
 * @file ampere.h
 * @brief Declaration of the Ampere unit class.
 *
 * @date 24, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_AMPERE_H
#define INERTIAFX_CORE_SI_AMPERE_H

#include "physical_unit.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Ampere
         * @brief Represents the SI base unit of electric current.
         */
        class Ampere : public PhysicalUnit
        {
          private:
            static const std::string DESCRIPTION; /**< Detailed description of this unit. */

          public:
            /**
             * @brief Default constructor initializing Ampere unit properties.
             */
            Ampere();

            /**
             * @brief Default destructor.
             */
            ~Ampere() = default;

            /**
             *  @copydoc IPhysicalUnit::clone()
             */
            std::unique_ptr<IPhysicalUnit> clone() const override
            {
                return std::make_unique<Ampere>(*this);
            };
        };
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_AMPERE_H
