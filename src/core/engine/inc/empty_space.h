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
 * @file empty_space.h
 * @brief Declaration of the Empty space class.
 *
 * @date 18, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_EMPTY_SPACE_H
#define INERTIAFX_CORE_ENGINE_EMPTY_SPACE_H

#include "world.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class EmptySpace
         * @brief A concrete class inheriting from World, representing an empty simulation space.
         *
         * @details This class is used to create a simulation world that is like empty space with
         * specified dimensions. There is no gravity on this world.
         */
        class EmptySpace : public World
        {
          public:
            /**
             * @brief Default constructor.
             */
            EmptySpace();

            /**
             * @brief Constructor with volume dimensions.
             * @param length Length of the empty space.
             * @param width Width of the empty space.
             * @param height Height of the empty space.
             */
            EmptySpace(double length, double width, double height);

            /**
             * @brief Destructor.
             */
            virtual ~EmptySpace() = default;
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_EMPTY_SPACE_H