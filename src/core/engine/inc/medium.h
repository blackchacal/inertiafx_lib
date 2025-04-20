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
 * @file medium.h
 * @brief Declaration of the Medium abstract class.
 *
 * @date 18, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_MEDIUM_H
#define INERTIAFX_CORE_ENGINE_MEDIUM_H

#include "imedium.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class Medium
         * @brief Abstract class implementing the IMedium interface.
         *
         * This class provides a base implementation for the IMedium interface.
         */
        class Medium : public IMedium
        {
          public:
            /**
             * @brief Virtual destructor for cleanup.
             */
            virtual ~Medium() = default;

            /**
             * @copydoc IMedium::getMaterial() const
             */
            std::unique_ptr<IMaterial> getMaterial() const override
            {
                if (_material == nullptr)
                {
                    return nullptr;
                }
                // Clone the material to return a unique pointer
                return std::unique_ptr<IMaterial>(_material->clone());
            }

            /**
             * @copydoc IMedium::getVolume()
             */
            const Volume &getVolume() const override
            {
                return _volume;
            }

            /**
             * @copydoc IMedium::setVolume(const Volume &volume)
             */
            void setVolume(const Volume &volume) override
            {
                _volume = volume;
            }

            /**
             * @copydoc IMedium::setVolume(double volume)
             */
            void setVolume(double volume) override
            {
                _volume.setValue(volume);
            }

            /**
             * @brief Sets the medium's spherical volume by radius value and prefix name.
             * @param radius Radius of spherical volume.
             * @param prefix A named decimal prefix (e.g., DecimalPrefix::Name::Kilo).
             */
            virtual void setVolume(double radius, DecimalPrefix::Name prefix)
            {
                _volume = Volume(radius, prefix);
            }

            /**
             * @copydoc IMedium::setVolume(double radius, DecimalPrefix::Symbol prefix)
             */
            virtual void setVolume(double radius, DecimalPrefix::Symbol prefix)
            {
                _volume = Volume(radius, prefix);
            }

            /**
             * @copydoc IMedium::setVolume(double length, double width, double height,
                                   DecimalPrefix::Name prefix)
             */
            virtual void setVolume(double length, double width, double height,
                                   DecimalPrefix::Name prefix)
            {
                _volume = Volume(length, width, height, prefix);
            }

            /**
             * @copydoc IMedium::setVolume(double length, double width, double height,
                                   DecimalPrefix::Symbol prefix)
             */
            void setVolume(double length, double width, double height, DecimalPrefix::Symbol prefix)
            {
                _volume = Volume(length, width, height, prefix);
            }

            /**
             * @brief Retrieves the medium's center position.
             * @return The current center position of the medium.
             */
            const Position &getPosition() const override
            {
                return _position;
            }

            /**
             * @brief Sets the medium's center position using a Position object.
             * @param position Reference to a Position object representing the new position.
             */
            void setPosition(const Position &position) override
            {
                _position = position;
            }

            /**
             * @copydoc IMedium::setPosition(std::array<double, 3> position,
                                   DecimalPrefix::Name prefix)
             */
            virtual void setPosition(std::array<double, 3> position, DecimalPrefix::Name prefix)

            {
                _position = Position(position, prefix);
            }

            /**
             * @copydoc IMedium::setPosition(std::array<double, 3> position,
                                   DecimalPrefix::Symbol prefix)
             */
            virtual void setPosition(std::array<double, 3> position, DecimalPrefix::Symbol prefix)
            {
                _position = Position(position, prefix);
            }

          protected:
            /**
             * @brief Default constructor.
             */
            Medium() :
                _material(nullptr), _volume(1.0, 1.0, 1.0, DecimalPrefix::Name::base),
                _position({0.0, 0.0, 0.0}, DecimalPrefix::Name::base)
            {
            }

            /**
             * @brief Protected constructor to initialize the medium with a material.
             * @param position Position of the medium.
             * @param volume Volume of the medium.
             * @param material Pointer to the material of the medium.
             */
            Medium(const Position &position, const Volume &volume,
                   std::unique_ptr<IMaterial> material) :
                _material(std::move(material)), _volume(volume), _position(position)
            {
                _material->setVolume(volume);
            }

            /**
             * @brief Protected copy constructor to allow derived classes to copy members.
             */
            Medium(const Medium &other) :
                _material(other._material ? std::unique_ptr<IMaterial>(other._material->clone()) :
                                            nullptr),
                _volume(other._volume), _position(other._position)

            {
                // Copy constructor
            }

            /**
             * @brief Protected copy assignment operator.
             */
            Medium &operator=(const Medium &other)
            {
                // Copy assignment operator
                if (this != &other)
                {
                    // If there's an existing owned object, remove it
                    _material.reset();

                    // Deep-copy from other
                    _material = other._material ?
                                    std::unique_ptr<IMaterial>(other._material->clone()) :
                                    nullptr;
                }
                return *this;
            }

            Volume _volume;                       /**< The volume of the medium. */
            Position _position;                   /**< The position of the medium. */
            std::unique_ptr<IMaterial> _material; /**< The material of the medium. */
        };

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_MEDIUM_H