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
 * @file imaterial.h
 * @brief Declaration of the IMaterial interface.
 *
 * @date 14, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_IMATERIAL_H
#define INERTIAFX_CORE_ENGINE_IMATERIAL_H

#include "decimal_prefix.h"
#include "density.h"
#include "mass.h"
#include "pressure.h"
#include "temperature.h"
#include "volume.h"

#include <array>

using namespace InertiaFX::Core::SI;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class IMaterial
         * @brief Interface representing a physical material (liquid, gas, solid) for use in physics
         * simulation.
         *
         * This interface provides methods to manage fundamental physical properties
         * of materials, such as volume, mass, density, temperature, and pressure.
         * These methods use unit-aware types as well as overloads that accept
         * scalar values combined with a specified decimal prefix.
         */
        class IMaterial
        {
          public:
            /**
             * @brief Virtual destructor for interface cleanup.
             */
            virtual ~IMaterial() = default;

            /**
             * @brief Add a clone() that creates a new IMaterial of the same dynamic type.
             */
            virtual std::unique_ptr<IMaterial> clone() const = 0;

            /**
             * @brief Retrieves the material's volume.
             * @return The current volume of the material.
             */
            virtual const Volume &getVolume() const = 0;

            /**
             * @brief Sets the material's volume using a Volume object.
             * @param volume Reference to a Volume object representing the new volume.
             */
            virtual void setVolume(const Volume &volume) = 0;

            /**
             * @brief Sets the material's volume by numeric value and prefix name.
             * @param volume Numeric value for volume.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::Kilo).
             */
            virtual void setVolume(double volume, DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the material's volume by numeric value and prefix symbol.
             * @param volume Numeric value for volume.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setVolume(double volume, DecimalPrefix::Symbol prefix) = 0;

            /**
             * @brief Retrieves the material's mass.
             * @return The current mass of the material.
             */
            virtual const Mass &getMass() const = 0;

            /**
             * @brief Sets the material's mass using a Mass object.
             * @param mass Reference to a Mass object representing the new mass.
             */
            virtual void setMass(const Mass &mass) = 0;

            /**
             * @brief Sets the material's mass by numeric value and prefix name.
             * @param mass Numeric value for mass.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::Kilo).
             */
            virtual void setMass(double mass, DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the material's mass by numeric value and prefix symbol.
             * @param mass Numeric value for mass.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setMass(double mass, DecimalPrefix::Symbol prefix) = 0;

            /**
             * @brief Retrieves the material's density.
             * @return The current density of the material.
             */
            virtual const Density &getDensity() const = 0;

            /**
             * @brief Sets the material's density using a Density object.
             * @param density Reference to a Density object representing the new density.
             */
            virtual void setDensity(const Density &density) = 0;

            /**
             * @brief Sets the material's density by numeric value and prefix name.
             * @param density Numeric value for density.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::KILO).
             */
            virtual void setDensity(double density, DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the material's density by numeric value and prefix symbol.
             * @param density Numeric value for density.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setDensity(double density, DecimalPrefix::Symbol prefix) = 0;

            /**
             * @brief Retrieves the material's temperature.
             * @return The current temperature of the material.
             */
            virtual const Temperature &getTemperature() const = 0;

            /**
             * @brief Sets the material's temperature using a Temperature object.
             * @param temperature Reference to a Temperature object representing the new
             * temperature.
             */
            virtual void setTemperature(const Temperature &temperature) = 0;

            /**
             * @brief Sets the material's temperature by numeric value and prefix name.
             * @param temperature Numeric value for temperature.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::KILO).
             */
            virtual void setTemperature(double temperature, DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the material's temperature by numeric value and prefix symbol.
             * @param temperature Numeric value for temperature.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setTemperature(double temperature, DecimalPrefix::Symbol prefix) = 0;

            /**
             * @brief Retrieves the material's pressure.
             * @return The current pressure of the material.
             */
            virtual const Pressure &getPressure() const = 0;

            /**
             * @brief Sets the material's pressure using a Pressure object.
             * @param pressure Reference to a Pressure object representing the new pressure.
             */
            virtual void setPressure(const Pressure &pressure) = 0;

            /**
             * @brief Sets the material's pressure from an array of numeric values and a prefix
             * name.
             * @param pressure An array of 3 doubles (e.g., partial or vector components).
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::KILO).
             */
            virtual void setPressure(std::array<double, 3> pressure,
                                     DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the material's pressure from an array of numeric values and a prefix
             * symbol.
             * @param pressure An array of 3 doubles (e.g., partial or vector components).
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setPressure(std::array<double, 3> pressure,
                                     DecimalPrefix::Symbol prefix) = 0;
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_IMATERIAL_H
