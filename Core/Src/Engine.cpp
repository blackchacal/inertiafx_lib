/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Engine.cpp                                                           *
 * \brief Engine instance.                                                    *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include <iostream>

#include <Engine.h>

namespace InertiaFX
{
    namespace Core
    {
        Engine::Engine()
        {
            IWorld *world = NULL;
            this->is_running = false;
            this->dimensions = RefDimensions::DIM_1D;
            this->total_run_time = 0;
        }

        Engine::Engine(IWorld *world)
        {
            this->world = world;
            this->is_running = false;
            this->dimensions = RefDimensions::DIM_1D;
            this->total_run_time = 0;
        }

        Engine::Engine(IWorld *world, WorldShape world_shape, RefDimensions dimensions)
        {
            /* TODO: Validate worl shape and dimensions */
            this->world = world;
            this->is_running = false;
            this->dimensions = dimensions;
            this->total_run_time = 0;
        }

        Engine::~Engine()
        {
        }

        void Engine::addWorld(IWorld *world)
        {
            this->world = world;
        }

        void Engine::run()
        {
            uint32_t t = 0;

            this->is_running = true;
            this->total_run_time = 0;

            while (this->is_running)
            {
                timeStep(t);
                t++;
            }
        }

        void Engine::run(uint32_t run_time)
        {
            this->is_running = true;
            this->total_run_time = run_time;

            std::cout << "Total number of bodies in world: " << this->world->getTotalNumberOfBodies() << "\n";

            for (uint32_t t = 0; t <= this->total_run_time; t++)
            {
                timeStep(t);
            }
        }

        void Engine::stop()
        {
            this->is_running = false;
            this->total_run_time = 0;
        }

        void Engine::setDimensions(RefDimensions dimensions)
        {
            this->dimensions = dimensions;
        }

        void Engine::timeStep(uint32_t t)
        {
            std::cout << "time step: " << t << "\n";
        }
    }
}