/******************************************************************************
 * InertiaFX - Physics Engine                                                 *
 *                                                                            *
 * \file Engine.cpp                                                           *
 * \brief Engine class.                                                       *
 *                                                                            *
 * \author blackchacal <ribeiro.tonet@gmail.com>                              *
 * \date October, 7th 2024                                                    *
 *                                                                            *
 * \namespace InertiaFX::Core                                                 *
 *                                                                            *
 * \copyright 2024-NOW. Ricardo Tonet. All rights reserved.                   *
 *****************************************************************************/

#include <InertiaFX.h>
#include <Engine.h>
#include <PointMass.h>

using namespace InertiaFX::Core;

Engine::Engine() : logger()
{
    this->engineStartLogging();

#if LOGGER_EN == 0
    this->logger.disable();
#endif

    IWorld *world = NULL;
    this->is_running = false;
    this->dimensions = RefDimensions::DIM_1D;
    this->total_run_time = 0;
}

Engine::Engine(IWorld *world) : logger()
{
    this->engineStartLogging();

#if LOGGER_EN == 0
    this->logger.disable();
#endif

    this->world = world;
    this->is_running = false;
    this->dimensions = RefDimensions::DIM_1D;
    this->total_run_time = 0;
}

Engine::Engine(IWorld *world, WorldShape world_shape, RefDimensions dimensions) : logger()
{
    this->engineStartLogging();

#if LOGGER_EN == 0
    this->logger.disable();
#endif

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

    this->logger.log(LogLevel::INFO, "Engine", "Total number of bodies in world: %d", this->world->getTotalNumberOfBodies());

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
    this->logger.log(LogLevel::INFO, "Engine", "time step: %d", t);

    /* Get world bodies */
    std::vector<IBody *> bodies = this->world->getBodies();

    /* For each body, calculate the net force, acceleration, velocity and position */
    for (std::vector<IBody *>::iterator it = bodies.begin(); it < bodies.end(); it++)
    {
        PointMass *body = static_cast<PointMass *>(*it);

        /* NOTE: For now, lets assume constant force over time. */

        /* Calculate body net force */
        /* Apply forces to the object depending on the interactions with other bodies or
        the medium in which it is inserted. */
        Eigen::Vector3d net_force = body->getNetForce();

        this->logger.log(LogLevel::INFO, "Engine", "%s net force: (%f, %f, %f)", body->getName().c_str(),
                         net_force.x(),
                         net_force.y(),
                         net_force.z());

        /**
         * Calculate body acceleration
         * vec_a = vec_F / m;
         */
        Eigen::Vector3d new_acc = net_force / body->getMass();
        body->setAcceleration(new_acc);

        this->logger.log(LogLevel::INFO, "Engine", "%s acceleration: (%f, %f, %f)", body->getName().c_str(),
                         new_acc.x(),
                         new_acc.y(),
                         new_acc.z());

        /**
         * Calculate body velocity
         * vec_v = vec_a * t + vec_v0
         */
        Eigen::Vector3d new_vel = new_acc * t + Eigen::Vector3d(0, 0, 0);
        body->setVelocity(new_vel);

        this->logger.log(LogLevel::INFO, "Engine", "%s velocity: (%f, %f, %f)", body->getName().c_str(),
                         new_vel.x(),
                         new_vel.y(),
                         new_vel.z());

        /**
         * Calculate body position
         * vec_x = vec_x0 + vec_v0 * t + (1/2) * vec_a * t^2
         */
        Eigen::Vector3d new_pos = Eigen::Vector3d(0, 0, 0) + Eigen::Vector3d(0, 0, 0) * t + 0.5f * new_acc * t * t;
        body->setPosition(new_pos);

        this->logger.log(LogLevel::INFO, "Engine", "%s position: (%f, %f, %f)", body->getName().c_str(),
                         body->getPosition().x(),
                         body->getPosition().y(),
                         body->getPosition().z());
    }
}

void Engine::engineStartLogging(void)
{
#ifdef LOGGER_LOG_FILENAME
    this->logger.setLogFilename(LOGGER_LOG_FILENAME);
#endif

    this->logger.log(LogLevel::INFO, "Engine", "InertiaFX | Physics Engine");
    this->logger.log(LogLevel::INFO, "Engine", "Version: %d.%d.%d", InertiaFX_VERSION_MAJOR,
                     InertiaFX_VERSION_MINOR, InertiaFX_VERSION_PATCH);
    this->logger.log(LogLevel::INFO, "Engine", "Settings:");
#if LOGGER_EN == 1
    this->logger.log(LogLevel::INFO, "Engine", "> Logging: enable");
#else
    this->logger.log(LogLevel::INFO, "Engine", "> Logging: disable");
#endif
#if LOGGER_LOG_TO_CONSOLE == 1
    this->logger.log(LogLevel::INFO, "Engine", "> Logging to console: enable");
#else
    this->logger.log(LogLevel::INFO, "Engine", "> Logging to console: disable");
#endif
#if LOGGER_LOG_TO_FILE == 1
    this->logger.log(LogLevel::INFO, "Engine", "> Logging to file: enable");
#else
    this->logger.log(LogLevel::INFO, "Engine", "> Logging to file: disable");
#endif
    this->logger.log(LogLevel::INFO, "Engine", "Starting...\n");

#if LOGGER_LOG_TO_CONSOLE == 1
    this->logger.enableLogToConsole();
#else
    this->logger.disableLogToConsole();
#endif
#if LOGGER_LOG_TO_FILE == 1
    this->logger.enableLogToFile();
#else
    this->logger.disableLogToFile();
#endif
}