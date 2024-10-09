/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file IMedium.h                                                            *
 * \brief Medium Interface.                                                   *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_IMEDIUM_H
#define _IFX_CORE_IMEDIUM_H

#include <Eigen/Core>

namespace InertiaFX
{
    namespace Core
    {
        class IMedium
        {
        public:
            virtual ~IMedium();
            virtual void setPosition(Eigen::Vector3d position) = 0;
            virtual Eigen::Vector3d getPosition() = 0;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_IMEDIUM_H */