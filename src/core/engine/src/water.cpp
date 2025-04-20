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
 * @file water.cpp
 * @brief Definition of the Water class.
 *
 * @date 18, Apr 2025
 */

#include "water.h"
#include "liquid.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        Water::Water() : Medium()
        {
            // Default constructor initializes the medium with a Liquid material
            _material = std::make_unique<Liquid>();
        }

        Water::Water(const Position &position, const Volume &volume) :
            Medium(position, volume, std::make_unique<Liquid>())
        {
        }

        /**
         * @brief Copy constructor.
         * @param other The Water object to copy from.
         */
        Water::Water(const Water &other) :
            Medium(other.getPosition(), other.getVolume(), std::make_unique<Liquid>())
        {
            _material =
                other._material ? std::unique_ptr<IMaterial>(other._material->clone()) : nullptr;
        }

        /**
         * @brief Copy assignment operator.
         * @param other The Water object to copy from.
         * @return A reference to this object.
         */
        Water &Water::operator=(const Water &other)
        {
            // Copy assignment operator
            if (this != &other)
            {
                // If there's an existing owned object, remove it
                _material.reset();

                // Deep-copy from other
                _material = other._material ? std::unique_ptr<IMaterial>(other._material->clone()) :
                                              nullptr;
            }
            return *this;
        }
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX