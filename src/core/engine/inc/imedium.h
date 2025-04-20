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
 * @file imedium.h
 * @brief Declaration of the IMedium interface.
 *
 * @date 17, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_IMEDIUM_H
#define INERTIAFX_CORE_ENGINE_IMEDIUM_H

#include "decimal_prefix.h"
#include "imaterial.h"
#include "mass.h"
#include "position.h"
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
         * @class IMedium
         * @brief Interface representing a physical medium of a certain medium.
         *
         * This interface provides methods to manage a physical medium's properties,
         * such as volume and mass. It allows for unit-aware types as well as overloads
         * that accept scalar values combined with a specified decimal prefix.
         */
        class IMedium
        {
          public:
            /**
             * @brief Virtual destructor for interface cleanup.
             */
            virtual ~IMedium() = default;

            /**
             * @brief Add a clone() that creates a new IMedium of the same dynamic type.
             */
            virtual std::unique_ptr<IMedium> clone() const = 0;

            /**
             * @brief Retrieves the medium's medium.
             * @return Pointer to medium's medium.
             */
            virtual std::unique_ptr<IMaterial> getMaterial() const = 0;

            /**
             * @brief Retrieves the medium's volume.
             * @return The current volume of the medium.
             */
            virtual const Volume &getVolume() const = 0;

            /**
             * @brief Sets the medium's volume using a Volume object.
             * @param volume Reference to a Volume object representing the new volume.
             */
            virtual void setVolume(const Volume &volume) = 0;

            /**
             * @brief Sets the medium's box volume by numeric value in base prefix.
             * @param volume Numeric value for volume.
             */
            virtual void setVolume(double volume) = 0;

            /**
             * @brief Sets the medium's spherical volume by radius value and prefix name.
             * @param radius Radius of spherical volume.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::Kilo).
             */
            virtual void setVolume(double radius, DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the medium's spherical volume by radius value and prefix symbol.
             * @param radius Radius of spherical volume.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setVolume(double radius, DecimalPrefix::Symbol prefix) = 0;

            /**
             * @brief Sets the medium's box volume by 'length x width x height'  and prefix name.
             * @param length Numeric value for volume length.
             * @param width Numeric value for volume width.
             * @param height Numeric value for volume height.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::Kilo).
             */
            virtual void setVolume(double length, double width, double height,
                                   DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the medium's box volume by 'length x width x height'  and prefix name.
             * @param length Numeric value for volume length.
             * @param width Numeric value for volume width.
             * @param height Numeric value for volume height.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setVolume(double length, double width, double height,
                                   DecimalPrefix::Symbol prefix) = 0;

            /**
             * @brief Retrieves the medium's center position.
             * @return The current center position of the medium.
             */
            virtual const Position &getPosition() const = 0;

            /**
             * @brief Sets the medium's center position using a Position object.
             * @param position Reference to a Position object representing the new position.
             */
            virtual void setPosition(const Position &position) = 0;

            /**
             * @brief Sets the medium's center position by numeric value and prefix name.
             * @param position Numeric value for position.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::Kilo).
             */
            virtual void setPosition(std::array<double, 3> position,
                                     DecimalPrefix::Name prefix) = 0;

            /**
             * @brief Sets the medium's center position by numeric value and prefix symbol.
             * @param position Numeric value for position.
             * @param prefix A symbolic decimal prefix (e.g., DecimalPrefix::Symbol::k).
             */
            virtual void setPosition(std::array<double, 3> position,
                                     DecimalPrefix::Symbol prefix) = 0;
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_IMEDIUM_H