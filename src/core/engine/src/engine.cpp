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
 * @file engine.cpp
 * @brief Definition of the Engine class.
 *
 * @date 22, Apr 2025
 */

#include "Engine.h"
#include "empty_space.h"
#include "logger.h"

namespace InertiaFX
{
namespace Core
{
    namespace Engine
    {
        Engine::Engine()
        {
            // Initialize the default logger and world
            _logger = std::make_unique<Logger>();
            _world  = std::make_unique<EmptySpace>();
        }

        Engine::Engine(std::unique_ptr<ILogger> logger, std::unique_ptr<IWorld> world) :
            _logger(std::move(logger)), _world(std::move(world))
        {
        }

        void Engine::setLogger(std::unique_ptr<ILogger> logger)
        {
            _logger = std::move(logger);
        }

        void Engine::setWorld(std::unique_ptr<IWorld> world)
        {
            _world = std::move(world);
        }

        void Engine::run()
        {
            _logger->log(LogLevel::Info, "Engine started running.");
            _logger->log(LogLevel::Info, "Run Time: Inf, Time Step: 1 s.");

            unsigned int tInstant = 0;
            unsigned int tStep    = 1;  // 1 second time step

            while (!_stop)
            {
                // Perform a time step in the simulation
                timeStep(static_cast<double>(tStep));
                tInstant += tStep;
            }
            _logger->log(LogLevel::Info, "Engine stopped running.");
        }

        void Engine::run(Time runTime, Time timeStep)
        {
            _logger->log(LogLevel::Info, "Engine started running.");
            _logger->log(LogLevel::Info, "Run Time: %d %s, Time Step: %d %s.", runTime.getValue(),
                         runTime.getUnitSymbol().c_str(), timeStep.getValue(),
                         timeStep.getUnitSymbol().c_str());

            double tInstant = 0;
            double tStep    = timeStep.getValue();

            while (!_stop && (tInstant <= runTime.getValue()))
            {
                // Perform a time step in the simulation
                this->timeStep(tInstant);
                tInstant += tStep;
            }
            _logger->log(LogLevel::Info, "Engine stopped running.");
        }

        void Engine::run(unsigned int runTime, unsigned int timeStep)
        {
            _logger->log(LogLevel::Info, "Engine started running.");
            _logger->log(LogLevel::Info, "Run Time: %d s, Time Step: %d s.", runTime, timeStep);

            unsigned int tInstant = 0;
            unsigned int tStep    = 1;

            while (!_stop && (tInstant <= runTime))
            {
                // Perform a time step in the simulation
                this->timeStep(static_cast<double>(tStep));
                tInstant += tStep;
            }
            _logger->log(LogLevel::Info, "Engine stopped running.");
        }

        void Engine::stop()
        {
            _stop = true;
        }

        void Engine::timeStep(double timeStep)
        {
        }

    }  // namespace Engine
}  // namespace Core
}  // namespace InertiaFX
