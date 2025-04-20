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
 * @file liquid.h
 * @brief Definition of the Liquid class.
 *
 * @date 18, Apr 2025
 */

#include "liquid.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        Liquid::Liquid() : Material(), _viscosity(0.0)
        {
        }

        void Liquid::setViscosity(double viscosity)
        {
            _viscosity = viscosity;
        }

        double Liquid::getViscosity() const
        {
            return _viscosity;
        }
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX