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
 * @file point_mass.cpp
 * @brief Definition of the PointMass class.
 *
 * @date 11, Apr 2025
 */

#include "point_mass.h"

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        unsigned int PointMass::nInstances = 0;

        PointMass::PointMass(const Mass &mass) :
            Entity(mass, Volume(0.0, DecimalPrefix::Name::base))
        {
            PointMass::nInstances++;
        }

        PointMass::PointMass(const Mass &mass, const Position &position) :
            Entity(mass, Volume(0.0, DecimalPrefix::Name::base), position)
        {
            PointMass::nInstances++;
        }

        PointMass::PointMass(const Mass &mass, const Position &position, const Velocity &velocity) :
            Entity(mass, Volume(0.0, DecimalPrefix::Name::base), position, velocity)
        {
            PointMass::nInstances++;
        }

        PointMass::PointMass(const Mass &mass, const Position &position, const Velocity &velocity,
                             const Acceleration &acceleration) :
            Entity(mass, Volume(0.0, DecimalPrefix::Name::base), position, velocity, acceleration)
        {
            PointMass::nInstances++;
        }

        PointMass::PointMass(const Mass &mass, const Position &position, const Velocity &velocity,
                             const Acceleration &acceleration, const Force &netForce) :
            Entity(mass, Volume(0.0, DecimalPrefix::Name::base), position, velocity, acceleration,
                   netForce)
        {
            PointMass::nInstances++;
        }

        PointMass::~PointMass()
        {
            PointMass::nInstances--;
        }
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX
