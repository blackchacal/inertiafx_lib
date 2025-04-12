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
 * @file entity.cpp
 * @brief Definition of the Entity abstract class.
 *
 * @date 02, Apr 2025
 */

#include "entity.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        Entity::Entity() :
            _mass(0.0),                                             // Assumed to default to zero
            _volume(0.0),                                           // Assumed to default to zero
            _position(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _velocity(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _acceleration(std::array<double, 3>({0.0, 0.0, 0.0})),  // Assumed to default to zero
            _netForce(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _isFixed(false)  // Assumed to default to not fixed
        {
        }

        Entity::Entity(const Mass &mass, const Volume &volume) :
            _mass(mass),      // Initialize mass with provided value
            _volume(volume),  // Initialize volume with provided value
            _position(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _velocity(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _acceleration(std::array<double, 3>({0.0, 0.0, 0.0})),  // Assumed to default to zero
            _netForce(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _isFixed(false)  // Assumed to default to not fixed
        {
        }

        Entity::Entity(const Mass &mass, const Volume &volume, const Position &position) :
            _mass(mass),          // Initialize mass with provided value
            _volume(volume),      // Initialize volume with provided value
            _position(position),  // Initialize position with provided value
            _velocity(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _acceleration(std::array<double, 3>({0.0, 0.0, 0.0})),  // Assumed to default to zero
            _netForce(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _isFixed(false)  // Assumed to default to not fixed
        {
        }

        Entity::Entity(const Mass &mass, const Volume &volume, const Position &position,
                       const Velocity &velocity) :
            _mass(mass),          // Initialize mass with provided value
            _volume(volume),      // Initialize volume with provided value
            _position(position),  // Initialize position with provided value
            _velocity(velocity),  // Initialize velocity with provided value
            _acceleration(std::array<double, 3>({0.0, 0.0, 0.0})),  // Assumed to default to zero
            _netForce(std::array<double, 3>({0.0, 0.0, 0.0})),      // Assumed to default to zero
            _isFixed(false)  // Assumed to default to not fixed
        {
        }

        Entity::Entity(const Mass &mass, const Volume &volume, const Position &position,
                       const Velocity &velocity, const Acceleration &acceleration) :
            _mass(mass),                  // Initialize mass with provided value
            _volume(volume),              // Initialize volume with provided value
            _position(position),          // Initialize position with provided value
            _velocity(velocity),          // Initialize velocity with provided value
            _acceleration(acceleration),  // Initialize acceleration with provided value
            _netForce(std::array<double, 3>({0.0, 0.0, 0.0})),  // Assumed to default to zero
            _isFixed(false)                                     // Assumed to default to not fixed
        {
        }

        Entity::Entity(const Mass &mass, const Volume &volume, const Position &position,
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

        Entity::~Entity() {};

        const Position &Entity::getPosition() const
        {
            return _position;
        }

        void Entity::setPosition(const Position &position)
        {
            _position = position;
        }

        void Entity::setPosition(const std::array<double, 3> position)
        {
            _position.setValue(position);
        }

        const Velocity &Entity::getVelocity() const
        {
            return _velocity;
        }

        void Entity::setVelocity(const Velocity &velocity)
        {
            _velocity = velocity;
        }

        void Entity::setVelocity(const std::array<double, 3> velocity)
        {
            _velocity.setValue(velocity);
        }

        const Acceleration &Entity::getAcceleration() const
        {
            return _acceleration;
        }

        void Entity::setAcceleration(const Acceleration &acceleration)
        {
            _acceleration = acceleration;
        }

        void Entity::setAcceleration(const std::array<double, 3> acceleration)
        {
            _acceleration.setValue(acceleration);
        }

        const Force &Entity::getForce() const
        {
            return _netForce;
        }

        void Entity::setForce(const Force &force)
        {
            _netForce = force;
        }

        void Entity::setForce(const std::array<double, 3> force)
        {
            _netForce.setValue(force);
        }

        void Entity::addForce(const Force &force)
        {
            _netForce = _netForce + force;
        }

        void Entity::addForce(const std::array<double, 3> force)
        {
            _netForce = _netForce + Force(force);
        }

        const Mass &Entity::getMass() const
        {
            return _mass;
        }

        const Volume &Entity::getVolume() const
        {
            return _volume;
        }

        bool Entity::isFixed() const
        {
            return _isFixed;
        }

        void Entity::fixEntity()
        {
            _isFixed = true;
        }

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX
