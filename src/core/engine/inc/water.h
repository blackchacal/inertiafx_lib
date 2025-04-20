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
 * @file water.h
 * @brief Declaration of the Water class.
 *
 * @date 18, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_WATER_H
#define INERTIAFX_CORE_ENGINE_WATER_H

#include "liquid.h"
#include "medium.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {

        /**
         * @class Water
         * @brief Represents a specific type of Medium with Liquid as its material.
         */
        class Water : public Medium
        {
          public:
            /**
             * @brief Default constructor.
             */
            Water();

            /**
             * @brief Constructor to initialize Water with position, volume, and Liquid material.
             * @param position The position of the water medium.
             * @param volume The volume of the water medium.
             */
            Water(const Position &position, const Volume &volume);

            /**
             * @brief Copy constructor.
             * @param other The Water object to copy from.
             */
            Water(const Water &other);

            /**
             * @brief Copy assignment operator.
             * @param other The Water object to copy from.
             * @return A reference to this object.
             */
            Water &operator=(const Water &other);

            /**
             * @brief Default destructor.
             */
            ~Water() override = default;

            /**
             * @copydoc IMedium::clone() const
             */
            std::unique_ptr<IMedium> clone() const override
            {
                return std::make_unique<Water>(*this);
            }
        };

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_WATER_H