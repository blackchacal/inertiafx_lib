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
 * @file world.h
 * @brief Declaration of the World abstract class.
 *
 * @date 18, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_WORLD_H
#define INERTIAFX_CORE_ENGINE_WORLD_H

#include "iworld.h"
#include <vector>

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @class World
         * @brief Abstract class implementing the IWorld interface.
         */
        class World : public IWorld
        {
          public:
            /**
             * @brief Default destructor.
             */
            virtual ~World() = default;

            /**
             * @copydoc IWorld::getEntities()
             */
            const std::vector<std::unique_ptr<IEntity>> &getEntities() const override
            {
                return _entities;
            }

            /**
             * @copydoc IWorld::getTotalNumberOfEntities()
             */
            unsigned int getTotalNumberOfEntities() const override
            {
                return _entities.size();
            }

            /**
             * @copydoc IWorld::getMediums()
             */
            const std::vector<std::unique_ptr<IMedium>> &getMediums() const override
            {
                return _mediums;
            }

            /**
             * @copydoc IWorld::getTotalNumberOfMediums()
             */
            unsigned int getTotalNumberOfMediums() const override
            {
                return _mediums.size();
            }

            /**
             * @copydoc IMedium::getVolume()
             */
            const Volume &getVolume() const override
            {
                return _volume;
            }

            /**
             * @copydoc IWorld::getVolumeDimensions()
             */
            std::tuple<double, double, double> getVolumeDimensions() const override
            {
                return _volume.getBoxDimensions();
            }

            /**
             * @copydoc IWorld::addEntity(std::unique_ptr<IEntity>)
             */
            void addEntity(std::unique_ptr<IEntity> entity) override
            {
                _entities.push_back(std::move(entity));
            }

            /**
             * @copydoc IWorld::addMedium(std::unique_ptr<IMedium>)
             */
            void addMedium(std::unique_ptr<IMedium> medium) override
            {
                _mediums.push_back(std::move(medium));
            }

            /**
             * @copydoc IWorld::getGravity()
             */
            const Force &getGravity() const override
            {
                return _gravity;
            }

          protected:
            /**
             * @brief Default constructor.
             */
            World() :
                _volume(Volume(1000.0, 1000.0, 1000.0, DecimalPrefix::Name::base)),
                _gravity(Force(std::array<double, 3>({0.0, 0.0, -9.81}), DecimalPrefix::Name::base))
            {
            }

            /**
             * @brief Constructor with volume and gravity parameters.
             * @param volume Volume of the world.
             * @param gravity Gravity force acting on the world.
             */
            World(const Volume &volume, const Force &gravity) : _volume(volume), _gravity(gravity)
            {
            }

            std::vector<std::unique_ptr<IEntity>>
                _entities; /**< Vector of unique pointers to entities in the world. */
            std::vector<std::unique_ptr<IMedium>>
                _mediums;   /**< Vector of unique pointers to mediums in the world. */
            Volume _volume; /**< Volume of the world. */
            Force _gravity; /**< Gravity Force acting on the world. */
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_WORLD_H