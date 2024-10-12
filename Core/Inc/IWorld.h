/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file IWorld.h                                                             *
 * \brief World Interface.                                                    *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_IWORLD_H
#define _IFX_CORE_IWORLD_H

#include <array>
#include <Eigen/Core>

#include "IBody.h"
#include "IMedium.h"

namespace InertiaFX
{
    namespace Core
    {
        class IWorld
        {
        public:
            virtual ~IWorld() = 0;
            virtual unsigned int getTotalNumberOfBodies() = 0;
            virtual unsigned int getTotalNumberOfMediums() = 0;
            virtual std::vector<IBody *>& getBodies() = 0;
            virtual double getVolume() = 0;
            virtual std::array<double, 3> getMaxDimensions() = 0;
            virtual Eigen::Vector3d getGravityVector() = 0;
            virtual void setShape(WorldShape shape) = 0;
            virtual void addBody(IBody *body, Eigen::Vector3d position) = 0;
            virtual void addMedium(IMedium *medium, Eigen::Vector3d position) = 0;
            virtual void spawnRandomBodiesAtRandomPositions(unsigned int n_bodies) = 0;
            virtual void spawnBodiesAtRandomPositions(IBody *body, unsigned int n_bodies) = 0;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_IWORLD_H */