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
 * @file entity.h
 * @brief Declaration of the Entity abstract class.
 *
 * @date 02, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_ENTITY_H
#define INERTIAFX_CORE_ENGINE_ENTITY_H

#include "ientity.h"

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {

        /**
         * @class Entity
         * @brief An abstract class that implements the base functionality of IEntity.
         *
         * This class provides default handling of position, velocity, acceleration,
         * mass, volume, and shape by storing the data internally. The default
         * constructor initializes position, velocity, acceleration, and mass
         * to zero.
         */
        class Entity : public IEntity
        {
          public:
            /**
             * @brief Default constructor.
             *
             * Initializes position, velocity, acceleration, net force, mass, and volume to zero.
             */
            Entity();

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, and volume to the provided values.
             * Position, velocity, acceleration, and net force are set to zero.
             */
            Entity(const Mass &mass, const Volume &volume);

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, and position to the
             * provided values. Set velocity, acceleration and net force to zero.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position);

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, position, and velocity to the
             * provided values. Set acceleration and net force to zero.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position,
                   const Velocity &velocity);

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, position, velocity, and acceleration to the
             * provided values. Set net force to zero.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position,
                   const Velocity &velocity, const Acceleration &acceleration);

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, position, velocity, acceleration, and net force to the
             * provided values.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position,
                   const Velocity &velocity, const Acceleration &acceleration,
                   const Force &netForce);

            /**
             * @brief Virtual destructor for polymorphic cleanup.
             */
            virtual ~Entity() = 0;

            /**
             * @copydoc IEntity::getPosition
             */
            const Position &getPosition() const override;

            /**
             * @copydoc IEntity::setPosition(const Position &position)
             */
            void setPosition(const Position &position) override;

            /**
             * @copydoc IEntity::setPosition(const std::array<double, 3> position)
             */
            void setPosition(const std::array<double, 3> position) override;

            /**
             * @copydoc IEntity::getVelocity
             */
            const Velocity &getVelocity() const override;

            /**
             * @copydoc IEntity::setVelocity(const Velocity &velocity)
             */
            void setVelocity(const Velocity &velocity) override;

            /**
             * @copydoc IEntity::setVelocity(const std::array<double, 3> velocity)
             */
            void setVelocity(const std::array<double, 3> velocity) override;

            /**
             * @copydoc IEntity::getAcceleration
             */
            const Acceleration &getAcceleration() const override;

            /**
             * @copydoc IEntity::setAcceleration(const Acceleration &acceleration)
             */
            void setAcceleration(const Acceleration &acceleration) override;

            /**
             * @copydoc IEntity::setAcceleration(const std::array<double, 3> acceleration)
             */
            void setAcceleration(const std::array<double, 3> acceleration) override;

            /**
             * @copydoc IEntity::getForce
             */
            const Force &getForce() const override;

            /**
             * @copydoc IEntity::setForce(const Force &force)
             */
            void setForce(const Force &force) override;

            /**
             * @copydoc IEntity::setForce(const std::array<double, 3> force)
             */
            void setForce(const std::array<double, 3> force) override;

            /**
             * @copydoc IEntity::addForce(const Force &force)
             */
            void addForce(const Force &force) override;

            /**
             * @copydoc IEntity::addForce(const std::array<double, 3> force)
             */
            void addForce(const std::array<double, 3> force) override;

            /**
             * @copydoc IEntity::getMass
             */
            const Mass &getMass() const override;

            /**
             * @copydoc IEntity::getVolume
             */
            const Volume &getVolume() const override;

            /**
             * @copydoc IEntity::isFixed
             */
            bool isFixed() const override;

            /**
             * @copydoc IEntity::fixEntity
             */
            void fixEntity() override;

          protected:
            Position _position;         /** Position of the entity. */
            Velocity _velocity;         /** Velocity of the entity. */
            Acceleration _acceleration; /** Acceleration of the entity. */
            Force _netForce;            /** Net Force actin on the entity. */
            Mass _mass;                 /** Mass of the entity. */
            Volume _volume;             /** Volume of the entity. */
            bool _isFixed; /** Flag indicating if this entity is fixed (immovable) in space. */
        };

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_ENTITY_H
