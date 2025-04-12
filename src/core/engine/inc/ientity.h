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
 * @file ientity.h
 * @brief Declaration of the IEntity interface.
 *
 * @date 02, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_IENTITY_H
#define INERTIAFX_CORE_ENGINE_IENTITY_H

#include "acceleration.h"
#include "force.h"
#include "mass.h"
#include "position.h"
#include "velocity.h"
#include "volume.h"

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @interface IEntity
         * @brief Represents a generic physical entity in the simulation world.
         *
         * The IEntity interface declares the core functionality required for all
         * physical objects. These include position, velocity, acceleration, force, mass,
         * and volume.
         */
        class IEntity
        {
          public:
            /**
             * @brief Virtual destructor for safe polymorphic cleanup.
             */
            virtual ~IEntity() = default;

            /**
             * @brief Retrieves the current position of the entity.
             * @return A Position object reference representing the entity’s position.
             */
            virtual const Position &getPosition() const = 0;

            /**
             * @brief Sets the new position of the entity.
             * @param position New position of the entity.
             * @return void.
             */
            virtual void setPosition(const Position &position) = 0;

            /**
             * @brief Sets the new position of the entity.
             *
             * @details This overload allows setting the position using a 3D vector. It assumes
             * the vector is given in the SI base unit system (meters).
             *
             * @param position New position vector of the entity.
             * @return void.
             */
            virtual void setPosition(const std::array<double, 3> position) = 0;

            /**
             * @brief Retrieves the current velocity of the entity.
             * @return A Velocity object reference representing the entity’s velocity.
             */
            virtual const Velocity &getVelocity() const = 0;

            /**
             * @brief Sets the new velocity of the entity.
             * @param velocity New velocity of the entity.
             * @return void.
             */
            virtual void setVelocity(const Velocity &velocity) = 0;

            /**
             * @brief Sets the new velocity of the entity.
             *
             * @details This overload allows setting the velocity using a 3D vector. It assumes
             * the vector is given in the SI base unit system (meters per second).
             *
             * @param velocity New velocity vector of the entity.
             * @return void.
             */
            virtual void setVelocity(const std::array<double, 3> velocity) = 0;

            /**
             * @brief Retrieves the current acceleration of the entity.
             * @return An Acceleration object reference representing the entity’s acceleration.
             */
            virtual const Acceleration &getAcceleration() const = 0;

            /**
             * @brief Sets the new acceleration of the entity.
             * @param acceleration New acceleration of the entity.
             * @return void.
             */
            virtual void setAcceleration(const Acceleration &acceleration) = 0;

            /**
             * @brief Sets the new acceleration of the entity.
             *
             * @details This overload allows setting the acceleration using a 3D vector. It assumes
             * the vector is given in the SI base unit system (meters per second squared).
             *
             * @param acceleration New acceleration vector of the entity.
             * @return void.
             */
            virtual void setAcceleration(const std::array<double, 3> acceleration) = 0;

            /**
             * @brief Retrieves the current force actin on the entity.
             * @return A Force object reference representing the entity’s net force.
             */
            virtual const Force &getForce() const = 0;

            /**
             * @brief Sets the new force actin on the entity.
             * @param force New net force acting on the entity.
             * @return void.
             */
            virtual void setForce(const Force &force) = 0;

            /**
             * @brief Sets the new force actin on the entity.
             *
             * @details This overload allows setting the force using a 3D vector. It assumes
             * the vector is given in the SI base unit system (newtons).
             *
             * @param force New net force vector acting on the entity.
             * @return void.
             */
            virtual void setForce(const std::array<double, 3> force) = 0;

            /**
             * @brief Adds a new force actin on the entity.
             * @details This method adds a force to the existing net force acting on the entity.
             * @param force New force acting on the entity.
             * @return void.
             */
            virtual void addForce(const Force &force) = 0;

            /**
             * @brief Sets the new force actin on the entity.
             *
             * @details This overload allows adding a force to the existing net force, using a 3D
             * vector. It assumes the vector is given in the SI base unit system (newtons).
             *
             * @param force New force vector acting on the entity.
             * @return void.
             */
            virtual void addForce(const std::array<double, 3> force) = 0;

            /**
             * @brief Retrieves the mass of the entity.
             * @return A Mass object reference representing the entity’s mass.
             */
            virtual const Mass &getMass() const = 0;

            /**
             * @brief Retrieves the volume of the entity.
             * @return A Volume object reference representing the entity’s volume.
             */
            virtual const Volume &getVolume() const = 0;

            /**
             * @brief Checks whether this entity is fixed in position.
             * @return True if the entity is immovable, false otherwise.
             */
            virtual bool isFixed() const = 0;

            /**
             * @brief Sets this entity as fixed in position.
             * @return void.
             */
            virtual void fixEntity() = 0;
        };

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_IENTITY_H
