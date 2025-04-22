/**
 * InertiaFX_Lib - Physics Simulation Library.
 * Copyright (C) 2025  Ricardo Tonet <https://github.com/blackchacal>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file engine.h
 * @brief Declaration of the Engine class.
 *
 * @date 22, Apr 2025
 */

#ifndef INERTIAFX_CORE_ENGINE_ENGINE_H
#define INERTIAFX_CORE_ENGINE_ENGINE_H

#include "ilogger.h"
#include "iworld.h"
#include "si_time.h"

using namespace InertiaFX::Core::SI;
using namespace InertiaFX::Core::Tools;

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        /**
         * @brief Executes and controls the physics simulation loop.
         */
        class Engine
        {
          public:
            /**
             * @brief Constructs a new Engine object.
             *
             * The engine is initialized with a default logger and world.
             * The default logger is a console logger.
             */
            Engine();

            /**
             * @brief Constructs a new Engine object with a custom logger and world.
             *
             * @param logger A unique pointer to an ILogger object for logging.
             * @param world A unique pointer to an IWorld object representing the simulation world.
             *
             * @note The logger and world are owned by the engine.
             */
            Engine(std::unique_ptr<ILogger> logger, std::unique_ptr<IWorld> world);

            /**
             * @brief Destroys the Engine object.
             *
             * Cleans up the logger and world resources.
             */
            ~Engine() = default;

            /**
             * @brief Sets the logger to the engine.
             *
             * @param world A unique pointer to an ILogger object to add simulation logs.
             */
            void setLogger(std::unique_ptr<ILogger> logger);

            /**
             * @brief Sets the world for the engine.
             *
             * @param world A unique pointer to an IWorld object representing the simulation world.
             */
            void setWorld(std::unique_ptr<IWorld> world);

            /**
             * @brief Runs the simulation indefinitely until stop() is called.
             */
            void run();

            /**
             * @brief Run for a fixed duration given as Time.
             * @param runTime The duration to run the simulation.
             * @param timeStep The time step for the simulation.
             * @note The run_time is in the unit defined in Time type.
             */
            void run(Time runTime, Time timeStep = Time(1.0, DecimalPrefix::Name::base));

            /**
             * @brief Run for a fixed duration (seconds).
             * @param runTime The duration to run the simulation in seconds.
             * @param timeStep The time step for the simulation in seconds.
             */
            void run(unsigned int runTime, unsigned int timeStep = 1);

            /**
             * @brief Request the simulation to stop at the next step.
             * This is a non-blocking call.
             */
            void stop();

          private:
            /**
             * @brief Executes a single time step of the simulation.
             * @param timeStep The time step for the simulation.
             * @note This function is called internally by the run() method.
             */
            void timeStep(double timeStep);

            std::unique_ptr<ILogger> _logger; /**< Optional logger */
            std::unique_ptr<IWorld> _world;   /**< Physics world */
            bool _stop;                       /**< Stop flag */
        };
    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX

#endif  // INERTIAFX_CORE_ENGINE_ENGINE_H
