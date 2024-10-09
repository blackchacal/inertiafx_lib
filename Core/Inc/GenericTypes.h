/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file GenericTypes.h                                                       *
 * \brief Generic types used by the Engine.                                   *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_GENERIC_TYPES_H
#define _IFX_CORE_GENERIC_TYPES_H

namespace InertiaFX
{
    namespace Core
    {
        enum class RefDimensions
        {
            DIM_1D,
            DIM_2D,
            DIM_3D
        };

        enum class WorldShape
        {
            DIM_1D_Line,
            DIM_2D_Circle,
            DIM_2D_Rectangle,
            DIM_3D_Sphere,
            DIM_3D_Box,
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_GENERIC_TYPES_H */