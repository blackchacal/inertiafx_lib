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
            Entity() :
                _mass(0.0, DecimalPrefix::Name::base),    // Assumed to default to zero
                _volume(0.0, DecimalPrefix::Name::base),  // Assumed to default to zero
                _position(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _velocity(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _acceleration(std::array<double, 3>({0.0, 0.0, 0.0}),
                              DecimalPrefix::Name::base),  // Assumed to default to zero
                _netForce(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _isFixed(false)                        // Assumed to default to not fixed
            {
            }

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, and volume to the provided values.
             * Position, velocity, acceleration, and net force are set to zero.
             */
            Entity(const Mass &mass, const Volume &volume) :
                _mass(mass),      // Initialize mass with provided value
                _volume(volume),  // Initialize volume with provided value
                _position(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _velocity(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _acceleration(std::array<double, 3>({0.0, 0.0, 0.0}),
                              DecimalPrefix::Name::base),  // Assumed to default to zero
                _netForce(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _isFixed(false)                        // Assumed to default to not fixed
            {
            }

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, and position to the
             * provided values. Set velocity, acceleration and net force to zero.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position) :
                _mass(mass),          // Initialize mass with provided value
                _volume(volume),      // Initialize volume with provided value
                _position(position),  // Initialize position with provided value
                _velocity(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _acceleration(std::array<double, 3>({0.0, 0.0, 0.0}),
                              DecimalPrefix::Name::base),  // Assumed to default to zero
                _netForce(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _isFixed(false)                        // Assumed to default to not fixed
            {
            }

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, position, and velocity to the
             * provided values. Set acceleration and net force to zero.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position,
                   const Velocity &velocity) :
                _mass(mass),          // Initialize mass with provided value
                _volume(volume),      // Initialize volume with provided value
                _position(position),  // Initialize position with provided value
                _velocity(velocity),  // Initialize velocity with provided value
                _acceleration(std::array<double, 3>({0.0, 0.0, 0.0}),
                              DecimalPrefix::Name::base),  // Assumed to default to zero
                _netForce(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _isFixed(false)                        // Assumed to default to not fixed
            {
            }

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, position, velocity, and acceleration to the
             * provided values. Set net force to zero.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position,
                   const Velocity &velocity, const Acceleration &acceleration) :
                _mass(mass),                  // Initialize mass with provided value
                _volume(volume),              // Initialize volume with provided value
                _position(position),          // Initialize position with provided value
                _velocity(velocity),          // Initialize velocity with provided value
                _acceleration(acceleration),  // Initialize acceleration with provided value
                _netForce(std::array<double, 3>({0.0, 0.0, 0.0}),
                          DecimalPrefix::Name::base),  // Assumed to default to zero
                _isFixed(false)                        // Assumed to default to not fixed
            {
            }

            /**
             * @brief Parameterized constructor.
             *
             * Initializes mass, volume, position, velocity, acceleration, and net force to the
             * provided values.
             */
            Entity(const Mass &mass, const Volume &volume, const Position &position,
                   const Velocity &velocity, const Acceleration &acceleration,
                   const Force &netForce) :
                _mass(mass),                  // Initialize mass with provided value
                _volume(volume),              // Initialize volume with provided value
                _position(position),          // Initialize position with provided value
                _velocity(velocity),          // Initialize velocity with provided value
                _acceleration(acceleration),  // Initialize acceleration with provided value
                _netForce(netForce),          // Initialize net force with provided value
                _isFixed(false)               // Assumed to default to not fixed
            {
            }

            /**
             * @brief Virtual destructor for polymorphic cleanup.
             */
            virtual ~Entity() = default;

            /**
             * @copydoc IEntity::getPosition
             */
            const Position &getPosition() const override
            {
                return _position;
            }

            /**
             * @copydoc IEntity::setPosition(const Position &position)
             */
            void setPosition(const Position &position) override
            {
                _position = position;
            }

            /**
             * @copydoc IEntity::setPosition(const std::array<double, 3> position)
             */
            void setPosition(const std::array<double, 3> position) override
            {
                _position.setValue(position);
            }

            /**
             * @copydoc IEntity::getVelocity
             */
            const Velocity &getVelocity() const override
            {
                return _velocity;
            }

            /**
             * @copydoc IEntity::setVelocity(const Velocity &velocity)
             */
            void setVelocity(const Velocity &velocity) override
            {
                _velocity = velocity;
            }

            /**
             * @copydoc IEntity::setVelocity(const std::array<double, 3> velocity)
             */
            void setVelocity(const std::array<double, 3> velocity) override
            {
                _velocity.setValue(velocity);
            }

            /**
             * @copydoc IEntity::getAcceleration
             */
            const Acceleration &getAcceleration() const override
            {
                return _acceleration;
            }

            /**
             * @copydoc IEntity::setAcceleration(const Acceleration &acceleration)
             */
            void setAcceleration(const Acceleration &acceleration) override
            {
                _acceleration = acceleration;
            }

            /**
             * @copydoc IEntity::setAcceleration(const std::array<double, 3> acceleration)
             */
            void setAcceleration(const std::array<double, 3> acceleration) override
            {
                _acceleration.setValue(acceleration);
            }

            /**
             * @copydoc IEntity::getForce
             */
            const Force &getForce() const override
            {
                return _netForce;
            }

            /**
             * @copydoc IEntity::setForce(const Force &force)
             */
            void setForce(const Force &force) override
            {
                _netForce = force;
            }

            /**
             * @copydoc IEntity::setForce(const std::array<double, 3> force)
             */
            void setForce(const std::array<double, 3> force) override
            {
                _netForce.setValue(force);
            }

            /**
             * @copydoc IEntity::addForce(const Force &force)
             */
            void addForce(const Force &force) override
            {
                _netForce = _netForce + force;
            }

            /**
             * @copydoc IEntity::addForce(const std::array<double, 3> force)
             */
            void addForce(const std::array<double, 3> force) override
            {
                _netForce = _netForce + Force(force, DecimalPrefix::Name::base);
            }

            /**
             * @copydoc IEntity::getMass
             */
            const Mass &getMass() const override
            {
                return _mass;
            }

            /**
             * @copydoc IEntity::getVolume
             */
            const Volume &getVolume() const override
            {
                return _volume;
            }

            /**
             * @copydoc IEntity::isFixed
             */
            bool isFixed() const override
            {
                return _isFixed;
            }

            /**
             * @copydoc IEntity::fixEntity
             */
            void fixEntity() override
            {
                _isFixed = true;
            }

          protected:
            /** Position of the entity. */
            Position _position;
            /** Velocity of the entity. */
            Velocity _velocity;
            /** Acceleration of the entity. */
            Acceleration _acceleration;
            /** Net Force acting on the entity. */
            Force _netForce;
            /** Mass of the entity. */
            Mass _mass;
            /** Volume of the entity. */
            Volume _volume;
            /** Flag indicating if this entity is fixed (immovable) in space. */
            bool _isFixed;
        };

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_ENTITY_H
