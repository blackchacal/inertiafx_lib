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
 * @file liquid.h
 * @brief Declaration of the Liquid class.
 *
 * @date 18, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_LIQUID_H
#define INERTIAFX_CORE_ENGINE_LIQUID_H

#include "material.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class Liquid
         * @brief Concrete class that represents a liquid material.
         *
         * Inherits from the abstract Material class and provides specific
         * implementations for liquid materials.
         */
        class Liquid : public Material
        {
          public:
            /**
             * @brief Default constructor.
             */
            Liquid();

            /**
             * @copydoc IMaterial::clone()
             * @brief Creates a new Liquid object that is a copy of this one.
             */
            std::unique_ptr<IMaterial> clone() const override
            {
                return std::make_unique<Liquid>(*this);
            }

            /**
             * @brief Sets the viscosity of the liquid.
             * @param viscosity The viscosity value.
             */
            void setViscosity(double viscosity);

            /**
             * @brief Gets the viscosity of the liquid.
             * @return The viscosity value.
             */
            double getViscosity() const;

          private:
            double _viscosity;  ///< Internal storage for liquid viscosity.
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_LIQUID_H