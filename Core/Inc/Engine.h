/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Engine.h                                                             *
 * \brief Engine instance.                                                    *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#ifndef _IFX_CORE_ENGINE_H
#define _IFX_CORE_ENGINE_H

#include <cstdint>

#include "GenericTypes.h"
#include "IWorld.h"

namespace InertiaFX
{
    namespace Core
    {
        class Engine
        {
        public:
            Engine();
            Engine(IWorld *world);
            Engine(IWorld *world, WorldShape world_shape, RefDimensions dimensions);
            ~Engine();

            void addWorld(IWorld *world);
            void run();
            void run(uint32_t run_time);
            void stop();
            void setDimensions(RefDimensions dimensions);

        private:
            IWorld *world;
            bool is_running;
            RefDimensions dimensions;
            uint32_t total_run_time;

            void timeStep(uint32_t t);
        };
    }
}
namespace ifx = InertiaFX;
#endif /* _IFX_CORE_ENGINE_H */