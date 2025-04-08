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
 * @file kilogram.h
 * @brief Declaration of the Kilogram unit class.
 *
 * @date 18, Mar 2025
 */

#ifndef INERTIAFX_CORE_SI_KILOGRAM_H
#define INERTIAFX_CORE_SI_KILOGRAM_H

#include "physical_unit.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Kilogram
         * @brief Represents the SI base unit of mass.
         */
        class Kilogram : public PhysicalUnit
        {
          private:
            static const std::string DESCRIPTION; /**< Detailed description of this unit. */

          public:
            using PhysicalUnit::toString;

            /**
             * @brief Default constructor initializing Kilogram unit properties.
             */
            Kilogram();

            /**
             * @brief Default destructor.
             */
            ~Kilogram() = default;

            /**
             *  @copydoc IPhysicalUnit::clone()
             */
            std::unique_ptr<IPhysicalUnit> clone() const override
            {
                return std::make_unique<Kilogram>(*this);
            };

            /**
             * @copydoc IPhysicalUnit::toString(DecimalPrefix::Name) const
             */
            std::string toString(DecimalPrefix::Name prefixName) const override;

            /**
             * @copydoc IPhysicalUnit::toString(DecimalPrefix::Symbol) const
             */
            std::string toString(DecimalPrefix::Symbol prefixSymbol) const override;
        };
    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_KILOGRAM_H
