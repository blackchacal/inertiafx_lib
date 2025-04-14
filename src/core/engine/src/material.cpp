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
 * @file material.cpp
 * @brief Definition of the Material abstract class.
 *
 * @date 14, Apr 2025
 */

#include "material.h"

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        const Volume &Material::getVolume() const
        {
            return _volume;
        }

        void Material::setVolume(Volume volume)
        {
            _volume = volume;
        }

        void Material::setVolume(double volume, DecimalPrefix::Name prefix)
        {
            _volume = Volume(volume, prefix);
        }

        void Material::setVolume(double volume, DecimalPrefix::Symbol prefix)
        {
            _volume = Volume(volume, prefix);
        }

        const Mass &Material::getMass() const
        {
            return _mass;
        }

        void Material::setMass(Mass mass)
        {
            _mass = mass;
        }

        void Material::setMass(double mass, DecimalPrefix::Name prefix)
        {
            _mass = Mass(mass, prefix);
        }

        void Material::setMass(double mass, DecimalPrefix::Symbol prefix)
        {
            _mass = Mass(mass, prefix);
        }

        const Density &Material::getDensity() const
        {
            return _density;
        }

        void Material::setDensity(Density density)
        {
            _density = density;
        }

        void Material::setDensity(double density, DecimalPrefix::Name prefix)
        {
            _density = Density(density, prefix);
        }

        void Material::setDensity(double density, DecimalPrefix::Symbol prefix)
        {
            _density = Density(density, prefix);
        }

        const Temperature &Material::getTemperature() const
        {
            return _temperature;
        }

        void Material::setTemperature(Temperature temperature)
        {
            _temperature = temperature;
        }

        void Material::setTemperature(double temperature, DecimalPrefix::Name prefix)
        {
            _temperature = Temperature(temperature, prefix);
        }

        void Material::setTemperature(double temperature, DecimalPrefix::Symbol prefix)
        {
            _temperature = Temperature(temperature, prefix);
        }

        const Pressure &Material::getPressure() const
        {
            return _pressure;
        }

        void Material::setPressure(Pressure pressure)
        {
            _pressure = pressure;
        }

        void Material::setPressure(std::array<double, 3> pressure, DecimalPrefix::Name prefix)
        {
            _pressure = Pressure(pressure, prefix);
        }

        void Material::setPressure(std::array<double, 3> pressure, DecimalPrefix::Symbol prefix)
        {
            _pressure = Pressure(pressure, prefix);
        }

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX
