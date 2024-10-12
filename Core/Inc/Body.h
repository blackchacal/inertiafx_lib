/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Body.h                                                               *
 * \brief Generic Body abstract class.                                        *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 8th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_BODY_H
#define _IFX_CORE_BODY_H

#include "IBody.h"

namespace InertiaFX
{
    namespace Core
    {
        class Body : public IBody
        {
        public:
            Body();
            ~Body();
            void applyForce(Eigen::Vector3d force);
            void setPosition(Eigen::Vector3d position);
            void setVelocity(Eigen::Vector3d velocity);
            void setAcceleration(Eigen::Vector3d acceleration);
            Eigen::Vector3d getNetForce();
            Eigen::Vector3d getPosition();
            Eigen::Vector3d getVelocity();
            Eigen::Vector3d getAcceleration();
            double getMass();
            virtual std::string getName() = 0;
            bool isPointMass();
            std::string toString();

        protected:
            bool is_point_mass;
            double mass;
            Eigen::Vector3d position;
            Eigen::Vector3d velocity;
            Eigen::Vector3d acceleration;
            Eigen::Vector3d net_force;
            std::vector<Eigen::Vector3d> forces;
            std::string name;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_BODY_H */