/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file VacuumWorld.h                                                        *
 * \brief Vacuum World class.                                                 *
 *                                                                            *
 * \details This class represents an empty vacuum world. It just empty space. *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 8th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_VACUUMWORLD_H
#define _IFX_CORE_VACUUMWORLD_H

#include <vector>
#include "World.h"

namespace InertiaFX
{
    namespace Core
    {
        class VacuumWorld : public World
        {
        public:
            VacuumWorld();
            ~VacuumWorld();
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_VACUUMWORLD_H */