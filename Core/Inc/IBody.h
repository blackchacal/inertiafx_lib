/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file IBody.h                                                              *
 * \brief Body Interface.                                                     *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_IBODY_H
#define _IFX_CORE_IBODY_H

#include <Eigen/Core>

namespace InertiaFX
{
    namespace Core
    {
        class IBody
        {
        public:
            virtual ~IBody() = 0;
            virtual void applyForce(Eigen::Vector3d force) = 0;
            virtual void setPosition(Eigen::Vector3d position) = 0;
            virtual Eigen::Vector3d getPosition() = 0;
            virtual Eigen::Vector3d getVelocity() = 0;
            virtual Eigen::Vector3d getAcceleration() = 0;
            virtual double getMass() = 0;
            virtual bool isPointMass() = 0;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_IBODY_H */