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
 * @file material.h
 * @brief Declaration of the Material abstract class.
 *
 * @date 14, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_MATERIAL_H
#define INERTIAFX_CORE_ENGINE_MATERIAL_H

#include "decimal_prefix.h"
#include "density.h"
#include "imaterial.h"
#include "mass.h"
#include "pressure.h"
#include "temperature.h"
#include "volume.h"

#include <array>

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class Material
         * @brief Abstract class that implements IMaterial for storing and managing physical
         * properties.
         *
         * Material provides a concrete implementation of the IMaterial interface,
         * but remains abstract so it can be further specialized for specific types
         * of physical materials (e.g., fluids, solids, etc.).
         */
        class Material : public IMaterial
        {
          public:
            /**
             * @brief Default virtual destructor.
             */
            virtual ~Material() = default;

            /**
             * @copydoc IMaterial::getVolume
             */
            const Volume &getVolume() const override
            {
                return _volume;
            }

            /**
             * @copydoc IMaterial::setVolume(const Volume&)
             */
            void setVolume(const Volume &volume) override
            {
                _volume = volume;
            }

            /**
             * @copydoc IMaterial::setVolume(double, DecimalPrefix::Name)
             */
            void setVolume(double volume, DecimalPrefix::Name prefix) override
            {
                _volume = Volume(volume, prefix);
            }

            /**
             * @copydoc IMaterial::setVolume(double, DecimalPrefix::Symbol)
             */
            void setVolume(double volume, DecimalPrefix::Symbol prefix) override
            {
                _volume = Volume(volume, prefix);
            }

            /**
             * @copydoc IMaterial::getMass
             */
            const Mass &getMass() const override
            {
                return _mass;
            }

            /**
             * @copydoc IMaterial::setMass(const Mass&)
             */
            void setMass(const Mass &mass) override
            {
                _mass = mass;
            }

            /**
             * @copydoc IMaterial::setMass(double, DecimalPrefix::Name)
             */
            void setMass(double mass, DecimalPrefix::Name prefix) override
            {
                _mass = Mass(mass, prefix);
            }

            /**
             * @copydoc IMaterial::setMass(double, DecimalPrefix::Symbol)
             */
            void setMass(double mass, DecimalPrefix::Symbol prefix) override
            {
                _mass = Mass(mass, prefix);
            }

            /**
             * @copydoc IMaterial::getDensity
             */
            const Density &getDensity() const override
            {
                return _density;
            }

            /**
             * @copydoc IMaterial::setDensity(const Density&)
             */
            void setDensity(const Density &density) override
            {
                _density = density;
            }

            /**
             * @copydoc IMaterial::setDensity(double, DecimalPrefix::Name)
             */
            void setDensity(double density, DecimalPrefix::Name prefix) override
            {
                _density = Density(density, prefix);
            }

            /**
             * @copydoc IMaterial::setDensity(double, DecimalPrefix::Symbol)
             */
            void setDensity(double density, DecimalPrefix::Symbol prefix) override
            {
                _density = Density(density, prefix);
            }

            /**
             * @copydoc IMaterial::getTemperature
             */
            const Temperature &getTemperature() const override
            {
                return _temperature;
            }

            /**
             * @copydoc IMaterial::setTemperature(const Temperature&)
             */
            void setTemperature(const Temperature &temperature) override
            {
                _temperature = temperature;
            }

            /**
             * @copydoc IMaterial::setTemperature(double, DecimalPrefix::Name)
             */
            void setTemperature(double temperature, DecimalPrefix::Name prefix) override
            {
                _temperature = Temperature(temperature, prefix);
            }

            /**
             * @copydoc IMaterial::setTemperature(double, DecimalPrefix::Symbol)
             */
            void setTemperature(double temperature, DecimalPrefix::Symbol prefix) override
            {
                _temperature = Temperature(temperature, prefix);
            }

            /**
             * @copydoc IMaterial::getPressure
             */
            const Pressure &getPressure() const override
            {
                return _pressure;
            }

            /**
             * @copydoc IMaterial::setPressure(const Pressure&)
             */
            void setPressure(const Pressure &pressure) override
            {
                _pressure = pressure;
            }

            /**
             * @copydoc IMaterial::setPressure(std::array<double, 3>, DecimalPrefix::Name)
             */
            void setPressure(std::array<double, 3> pressure, DecimalPrefix::Name prefix) override
            {
                _pressure = Pressure(pressure, prefix);
            }

            /**
             * @copydoc IMaterial::setPressure(std::array<double, 3>, DecimalPrefix::Symbol)
             */
            void setPressure(std::array<double, 3> pressure, DecimalPrefix::Symbol prefix) override
            {
                _pressure = Pressure(pressure, prefix);
            }

          protected:
            /**
             * @brief Protected default constructor to prevent direct instantiation.
             */
            Material() :
                _volume(0.0, DecimalPrefix::Name::base), _mass(0.0, DecimalPrefix::Name::base),
                _density(0.0, DecimalPrefix::Name::base),
                _temperature(0.0, DecimalPrefix::Name::base),
                _pressure({0.0, 0.0, 0.0}, DecimalPrefix::Name::base)
            {
            }

            /**
             * @brief Protected copy constructor to allow derived classes to copy members.
             */
            Material(const Material &) = default;

            /**
             * @brief Protected move constructor to allow derived classes to move members.
             */
            Material(Material &&) = default;

            /**
             * @brief Protected copy assignment operator.
             */
            Material &operator=(const Material &) = default;

            /**
             * @brief Protected move assignment operator.
             */
            Material &operator=(Material &&) = default;

            Volume _volume;            ///< Internal storage for material volume
            Mass _mass;                ///< Internal storage for material mass
            Density _density;          ///< Internal storage for material density
            Temperature _temperature;  ///< Internal storage for material temperature
            Pressure _pressure;        ///< Internal storage for material pressure
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_MATERIAL_H