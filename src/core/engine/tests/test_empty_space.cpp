#include "empty_space.h"
#include "force.h"
#include "volume.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::Engine;
using namespace InertiaFX::Core::SI;

// Test fixture for EmptySpace
class EmptySpaceTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        defaultVolume = Volume(1000.0, 1000.0, 1000.0, DecimalPrefix::Name::base);
        zeroGravity   = Force({0.0, 0.0, 0.0}, DecimalPrefix::Name::base);
    }

    Volume defaultVolume;
    Force zeroGravity;
};

// Test default constructor
TEST_F(EmptySpaceTest, DefaultConstructor)
{
    EmptySpace emptySpace;
    EXPECT_EQ(emptySpace.getVolume(), defaultVolume);
    EXPECT_EQ(emptySpace.getGravity(), zeroGravity);
}

// Test parameterized constructor
TEST_F(EmptySpaceTest, ParameterizedConstructor)
{
    double length = 500.0, width = 300.0, height = 200.0;
    EmptySpace emptySpace(length, width, height);

    auto volumeDimensions = emptySpace.getVolume().getBoxDimensions();
    EXPECT_DOUBLE_EQ(std::get<0>(volumeDimensions), length);
    EXPECT_DOUBLE_EQ(std::get<1>(volumeDimensions), width);
    EXPECT_DOUBLE_EQ(std::get<2>(volumeDimensions), height);

    auto gravity = emptySpace.getGravity();
    EXPECT_DOUBLE_EQ(gravity.getValue()[0], 0.0);
    EXPECT_DOUBLE_EQ(gravity.getValue()[1], 0.0);
    EXPECT_DOUBLE_EQ(gravity.getValue()[2], 0.0);
}

// Test constructor with dimensions
TEST_F(EmptySpaceTest, ConstructorWithDimensions)
{
    double length = 500.0;
    double width  = 500.0;
    double height = 500.0;
    EmptySpace emptySpace(length, width, height);

    Volume expectedVolume(length, width, height, DecimalPrefix::Name::base);
    EXPECT_EQ(emptySpace.getVolume(), expectedVolume);
    EXPECT_EQ(emptySpace.getGravity(), zeroGravity);
}

// Test World class methods
TEST_F(EmptySpaceTest, WorldMethods)
{
    EmptySpace emptySpace(100.0, 200.0, 300.0);

    auto volumeDimensions = emptySpace.getVolume().getBoxDimensions();
    EXPECT_DOUBLE_EQ(std::get<0>(volumeDimensions), 100.0);
    EXPECT_DOUBLE_EQ(std::get<1>(volumeDimensions), 200.0);
    EXPECT_DOUBLE_EQ(std::get<2>(volumeDimensions), 300.0);

    auto gravity = emptySpace.getGravity();
    EXPECT_DOUBLE_EQ(gravity.getValue()[0], 0.0);
    EXPECT_DOUBLE_EQ(gravity.getValue()[1], 0.0);
    EXPECT_DOUBLE_EQ(gravity.getValue()[2], 0.0);

    EXPECT_EQ(emptySpace.getTotalNumberOfEntities(), 0);
    EXPECT_EQ(emptySpace.getTotalNumberOfMediums(), 0);
    EXPECT_EQ(emptySpace.getEntities().size(), 0);
    EXPECT_EQ(emptySpace.getMediums().size(), 0);
}