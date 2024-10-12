/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file World.h                                                              *
 * \brief Generic World abstract class.                                       *
 *                                                                            *
 * \details This class represents a generic world.                            *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_WORLD_H
#define _IFX_CORE_WORLD_H

#include <vector>

#include "GenericTypes.h"
#include "IWorld.h"
#include "Body.h"

namespace InertiaFX
{
    namespace Core
    {
        class World : public IWorld
        {
        public:
            World();
            ~World();

            unsigned int getTotalNumberOfBodies();
            unsigned int getTotalNumberOfMediums();
            double getVolume();
            std::array<double, 3> getMaxDimensions();
            Eigen::Vector3d getGravityVector();
            void setShape(WorldShape shape);
            void addBody(IBody *body, Eigen::Vector3d position);
            void addMedium(IMedium *medium, Eigen::Vector3d position);
            void spawnRandomBodiesAtRandomPositions(unsigned int n_bodies);
            void spawnBodiesAtRandomPositions(IBody *body, unsigned int n_bodies);

        protected:
            Eigen::Vector3d gravity_vect;
            std::array<double, 3> min_dim;
            std::array<double, 3> max_dim;
            std::vector<IMedium *> mediums_list;
            std::vector<IBody *> bodies_list;
            WorldShape shape;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_WORLD_H */