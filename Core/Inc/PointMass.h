/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file PointMass.h                                                          *
 * \brief Point Mass class.                                                   *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 12th 2024                                                   *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_POINT_MASS_H
#define _IFX_CORE_POINT_MASS_H

#include "Body.h"

namespace InertiaFX
{
    namespace Core
    {
        class PointMass : public Body
        {
        public:
            PointMass();
            ~PointMass();
            std::string getName() override;
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_POINT_MASS_H */