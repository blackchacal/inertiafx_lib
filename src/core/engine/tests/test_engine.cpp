#include "Engine.h"
#include "empty_space.h"
#include "file_logger.h"
#include "logger.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::Engine;

TEST(EngineTest, CustomConstructorSetsLoggerAndWorld)
{
    auto logger = std::make_unique<FileLogger>("test_engine.log", LogLevel::Info, true);
    auto world  = std::make_unique<EmptySpace>();
    Engine engine(std::move(logger), std::move(world));
}

TEST(EngineTest, SetWorldReplacesWorld)
{
    Engine engine;
    auto world = std::make_unique<EmptySpace>();
    engine.setWorld(std::move(world));
}

TEST(EngineTest, RunWithoutTimeAndStopDoesNotThrow)
{
    auto logger = std::make_unique<FileLogger>("test_engine_run1.log", LogLevel::Info, true);
    auto world  = std::make_unique<EmptySpace>();
    Engine engine(std::move(logger), std::move(world));
    engine.run();
    engine.stop();
}

TEST(EngineTest, RunWithTimeAndStepDoesNotThrow)
{
    auto logger = std::make_unique<FileLogger>("test_engine_run2.log", LogLevel::Info, true);
    auto world  = std::make_unique<EmptySpace>();
    Engine engine(std::move(logger), std::move(world));
    Time runTime(10, DecimalPrefix::Name::base);
    Time timeStep(1, DecimalPrefix::Name::base);
    EXPECT_NO_THROW(engine.run(runTime, timeStep));
}

TEST(EngineTest, RunWithUnsignedIntDoesNotThrow)
{
    auto logger = std::make_unique<FileLogger>("test_engine_run3.log", LogLevel::Info, true);
    auto world  = std::make_unique<EmptySpace>();
    Engine engine(std::move(logger), std::move(world));
    EXPECT_NO_THROW(engine.run(10, 1));
}
