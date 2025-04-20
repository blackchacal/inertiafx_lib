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
 * @file iworld.h
 * @brief Declaration of the IWorld interface.
 *
 * @date 18, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_IWORLD_H
#define INERTIAFX_CORE_ENGINE_IWORLD_H

#include "force.h"
#include "ientity.h"
#include "imedium.h"
#include "volume.h"
#include <tuple>
#include <vector>

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class IWorld
         * @brief Interface representing a simulation world containing all simulation objects.
         *
         * The world is a 3D space with a 3D reference system.
         */
        class IWorld
        {
          public:
            /**
             * @brief Virtual destructor for interface cleanup.
             */
            virtual ~IWorld() = default;

            /**
             * @brief Retrieves all entities in the simulation world.
             * @return A vector of unique pointers to IEntity objects.
             */
            virtual const std::vector<std::unique_ptr<IEntity>> &getEntities() const = 0;

            /**
             * @brief Retrieves the total number of entities in the simulation world.
             * @return The total number of entities.
             */
            virtual unsigned int getTotalNumberOfEntities() const = 0;

            /**
             * @brief Retrieves all mediums in the simulation world.
             * @return A vector of unique pointers to IMedium objects.
             */
            virtual const std::vector<std::unique_ptr<IMedium>> &getMediums() const = 0;

            /**
             * @brief Retrieves the total number of mediums in the simulation world.
             * @return The total number of mediums.
             */
            virtual unsigned int getTotalNumberOfMediums() const = 0;

            /**
             * @brief Retrieves the volume of the simulation world.
             * @return A constant reference to the Volume object.
             */
            virtual const Volume &getVolume() const = 0;

            /**
             * @brief Retrieves the dimensions of the simulation world's volume.
             * @return A tuple containing the length, width, and height of the volume.
             */
            virtual std::tuple<double, double, double> getVolumeDimensions() const = 0;

            /**
             * @brief Adds an entity to the simulation world.
             * @param entity A unique pointer to the IEntity object to be added.
             */
            virtual void addEntity(std::unique_ptr<IEntity> entity) = 0;

            /**
             * @brief Adds a medium to the simulation world.
             * @param medium A unique pointer to the IMedium object to be added.
             */
            virtual void addMedium(std::unique_ptr<IMedium> medium) = 0;

            /**
             * @brief Retrieves the gravity force acting on the world.
             * @return A constant reference to the Force object representing gravity.
             */
            virtual const Force &getGravity() const = 0;
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_IWORLD_H