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
 * @file point_mass.h
 * @brief Declaration of the PointMass class.
 *
 * @date 11, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_POINT_MASS_H
#define INERTIAFX_CORE_ENGINE_POINT_MASS_H

#include "entity.h"

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {

        /**
         * @class PointMass
         * @brief A class representing point mass body in the simulation.
         */
        class PointMass : public Entity
        {
          public:
            /**
             * @brief The number of PointMass instances created.
             */
            static unsigned int nInstances;

            /**
             * @brief Constructs a PointMass with mass.
             * @param mass The mass of the body.
             *
             * Position, velocity, and acceleration are initialized to zero in Entity.
             * The body is considered non-fixed by default.
             */
            PointMass(const Mass &mass);

            /**
             * @brief Constructs a PointMass with mass, and an initial position.
             * @param mass The mass of the body.
             * @param position The initial position of the body.
             *
             * Velocity and acceleration are initialized to zero. The body is non-fixed by default.
             */
            PointMass(const Mass &mass, const Position &position);

            /**
             * @brief Constructs a PointMass with mass, position, and velocity.
             * @param mass The mass of the body.
             * @param position The initial position of the body.
             * @param velocity The initial velocity of the body.
             *
             * Acceleration is initialized to zero. The body is non-fixed by default.
             */
            PointMass(const Mass &mass, const Position &position, const Velocity &velocity);

            /**
             * @brief Constructs a PointMass with mass, position, velocity, and
             * acceleration.
             * @param mass The mass of the body.
             * @param position The initial position of the body.
             * @param velocity The initial velocity of the body.
             * @param acceleration The initial acceleration of the body.
             *
             * The body is non-fixed by default.
             */
            PointMass(const Mass &mass, const Position &position, const Velocity &velocity,
                      const Acceleration &acceleration);

            /**
             * @brief Constructs a PointMass with mass, position, velocity,
             * acceleration, and net force.
             * @param mass The mass of the body.
             * @param position The initial position of the body.
             * @param velocity The initial velocity of the body.
             * @param acceleration The initial acceleration of the body.
             * @param netForce The initial force acting on the body.
             *
             * The body is non-fixed by default.
             */
            PointMass(const Mass &mass, const Position &position, const Velocity &velocity,
                      const Acceleration &acceleration, const Force &netForce);

            /**
             * @brief Destructor.
             */
            ~PointMass();

            /**
             * @copydoc IEntity::clone() const
             */
            virtual std::unique_ptr<IEntity> clone() const override
            {
                return std::make_unique<PointMass>(*this);
            }
        };

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_POINT_MASS_H
