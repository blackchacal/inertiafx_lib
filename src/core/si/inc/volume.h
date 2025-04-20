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
 * @file volume.h
 * @brief Declaration of the Volume class.
 *
 * @date 02, Apr 2025
 */

#ifndef INERTIAFX_CORE_SI_VOLUME_H
#define INERTIAFX_CORE_SI_VOLUME_H

#include "derived_scalar_qty.h"

namespace InertiaFX
{
namespace Core
{
    namespace SI
    {
        /**
         * @class Volume
         * @brief Concrete derived scalar quantity representing volume.
         */
        class Volume : public DerivedScalarQty
        {
          public:
            /**
             * @brief Enumeration for volume types.
             * @details This enum is used to differentiate between box and spherical volumes.
             */
            enum class Type
            {
                Box,
                Sphere,
            };

            /**
             * @brief Constructs a new Volume object.
             *
             * The volume is initialized to 1.0 and stored in base prefix value.
             */
            Volume();

            /**
             * @brief Constructs a new box Volume object.
             * @param length Numeric value for box length in the specified prefix.
             * @param width Numeric value for box width in the specified prefix.
             * @param height Numeric value for box height in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'length',
             * 'width' and 'height' are expressed. It defaults to base which is 10^0.
             *
             * Internally, the volume is stored in base prefix value.
             */
            Volume(double length, double width, double height,
                   DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            /**
             * @brief Constructs a new box Volume object.
             * @param length Numeric value for box length in the specified prefix.
             * @param width Numeric value for box width in the specified prefix.
             * @param height Numeric value for box height in the specified prefix.
             * @param prefix The decimal prefix symbol (e.g., "k", "m") in which 'length',
             * 'width' and 'height' are expressed. It defaults to base which is 10^0.
             *
             * Internally, the volume is stored in base prefix value.
             */
            Volume(double length, double width, double height,
                   DecimalPrefix::Symbol prefix = DecimalPrefix::Symbol::base);

            /**
             * @brief Constructs a new spherical Volume object.
             * @param radius Numeric value for sphere radius in the specified prefix.
             * @param prefix The decimal prefix name (e.g., "kilo", "milli") in which 'radius' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the volume is stored in base prefix value.
             */
            Volume(double radius, DecimalPrefix::Name prefix = DecimalPrefix::Name::base);

            /**
             * @brief Constructs a new spherical Volume object.
             * @param radius Numeric value for sphere radius in the specified prefix.
             * @param prefix The decimal prefix symbol (e.g., "k", "m") in which 'radius' is
             * expressed. It defaults to base which is 10^0.
             *
             * Internally, the volume is stored in base prefix value.
             */
            Volume(double radius, DecimalPrefix::Symbol prefix = DecimalPrefix::Symbol::base);

            /**
             * @brief Copy constructor.
             * @details Constructs a new Volume object from an existing one.
             *
             * @param other The other Volume object to copy from.
             */
            Volume(const Volume &other);

            /**
             * @brief Copy assignment operator.
             * @details Constructs a new Volume object from an existing one.
             *
             * @param other The other Volume object to copy from.
             * @return A reference to this object.
             *
             * @note This operator performs a deep copy of the object.
             */
            Volume &operator=(const Volume &other);

            /**
             * @brief Addition operator.
             * @details Adds two Volume objects together.
             *
             * @param other The other Volume object to add.
             * @return A new Volume object representing the sum.
             */
            Volume operator+(const Volume &other) const;

            /**
             * @brief Equality operator.
             * @details Compares two Volume objects for equality.
             *
             * @param other The other Volume object to compare.
             * @return True if the volumes are equal, false otherwise.
             */
            bool operator==(const Volume &other) const;

            /**
             * @brief Retrieves the length, width, and height of the volume.
             * @return A tuple containing the length, width, and height.
             */
            std::tuple<double, double, double> getBoxDimensions() const;

            /**
             * @brief Retrieves the radius of the volume.
             * @return The volume radius.
             */
            double getSphereDimensions() const;

            /**
             * @brief Retrieves the type of the volume.
             * @return The type of the volume (Box or Sphere).
             * @details This function is used to determine the type of volume being represented.
             */
            Type getType() const;

          private:
            double _length;  //!< Length of the volume in base units (metres).
            double _width;   //!< Width of the volume in base units (metres).
            double _height;  //!< Height of the volume in base units (metres).
            double _radius;  //!< Radius of the volume in base units (metres).
            Type _type;      //!< Type of the volume (Box or Sphere).
        };

    }  // namespace SI
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_SI_VOLUME_H
