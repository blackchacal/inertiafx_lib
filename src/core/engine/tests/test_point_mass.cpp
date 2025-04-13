#include "acceleration.h"
#include "force.h"
#include "mass.h"
#include "point_mass.h"
#include "position.h"
#include "velocity.h"
#include <array>
#include <gtest/gtest.h>
#include <memory>

using namespace InertiaFX::Core::Engine;
using namespace InertiaFX::Core::SI;

class PointMassTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        mass         = Mass(10.0);  // 10 kg
        position     = Position({1.0, 2.0, 3.0});
        velocity     = Velocity({0.5, 0.5, 0.5});
        acceleration = Acceleration({0.1, 0.2, 0.3});
        force        = Force({5.0, 5.0, 5.0}, DecimalPrefix::Name::base);
    }

    Mass mass;
    Position position;
    Velocity velocity;
    Acceleration acceleration;
    Force force;
};

TEST_F(PointMassTest, ConstructorWithMass)
{
    PointMass pointMass(mass);
    EXPECT_DOUBLE_EQ(pointMass.getMass().getValue(), 10.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[0], 0.0);
    EXPECT_EQ(pointMass.getVelocity().getValue()[0], 0.0);
    EXPECT_EQ(pointMass.getAcceleration().getValue()[0], 0.0);
    EXPECT_EQ(pointMass.getForce().getValue()[0], 0.0);
}

TEST_F(PointMassTest, ConstructorWithMassAndPosition)
{
    PointMass pointMass(mass, position);
    EXPECT_DOUBLE_EQ(pointMass.getMass().getValue(), 10.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[0], 1.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[1], 2.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[2], 3.0);
}

TEST_F(PointMassTest, ConstructorWithMassPositionAndVelocity)
{
    PointMass pointMass(mass, position, velocity);
    EXPECT_DOUBLE_EQ(pointMass.getMass().getValue(), 10.0);
    EXPECT_EQ(pointMass.getVelocity().getValue()[0], 0.5);
    EXPECT_EQ(pointMass.getVelocity().getValue()[1], 0.5);
    EXPECT_EQ(pointMass.getVelocity().getValue()[2], 0.5);
}

TEST_F(PointMassTest, ConstructorWithAllParameters)
{
    PointMass pointMass(mass, position, velocity, acceleration, force);
    EXPECT_DOUBLE_EQ(pointMass.getMass().getValue(), 10.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[0], 1.0);
    EXPECT_EQ(pointMass.getVelocity().getValue()[0], 0.5);
    EXPECT_EQ(pointMass.getAcceleration().getValue()[0], 0.1);
    EXPECT_EQ(pointMass.getForce().getValue()[0], 5.0);
}

TEST_F(PointMassTest, AddForce)
{
    PointMass pointMass(mass, position, velocity, acceleration, force);
    Force additionalForce({2.0, 3.0, 4.0}, DecimalPrefix::Name::base);
    pointMass.addForce(additionalForce);

    EXPECT_DOUBLE_EQ(pointMass.getForce().getValue()[0], 7.0);
    EXPECT_DOUBLE_EQ(pointMass.getForce().getValue()[1], 8.0);
    EXPECT_DOUBLE_EQ(pointMass.getForce().getValue()[2], 9.0);
}

TEST_F(PointMassTest, SetAndGetPosition)
{
    PointMass pointMass(mass);
    pointMass.setPosition(position);

    EXPECT_EQ(pointMass.getPosition().getValue()[0], 1.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[1], 2.0);
    EXPECT_EQ(pointMass.getPosition().getValue()[2], 3.0);
}

TEST_F(PointMassTest, SetAndGetVelocity)
{
    PointMass pointMass(mass);
    pointMass.setVelocity(velocity);

    EXPECT_EQ(pointMass.getVelocity().getValue()[0], 0.5);
    EXPECT_EQ(pointMass.getVelocity().getValue()[1], 0.5);
    EXPECT_EQ(pointMass.getVelocity().getValue()[2], 0.5);
}

TEST_F(PointMassTest, SetAndGetAcceleration)
{
    PointMass pointMass(mass);
    pointMass.setAcceleration(acceleration);

    EXPECT_EQ(pointMass.getAcceleration().getValue()[0], 0.1);
    EXPECT_EQ(pointMass.getAcceleration().getValue()[1], 0.2);
    EXPECT_EQ(pointMass.getAcceleration().getValue()[2], 0.3);
}

TEST_F(PointMassTest, SetAndGetForce)
{
    PointMass pointMass(mass);
    pointMass.setForce(force);

    EXPECT_EQ(pointMass.getForce().getValue()[0], 5.0);
    EXPECT_EQ(pointMass.getForce().getValue()[1], 5.0);
    EXPECT_EQ(pointMass.getForce().getValue()[2], 5.0);
}

TEST_F(PointMassTest, FixEntity)
{
    PointMass pointMass(mass);
    EXPECT_FALSE(pointMass.isFixed());

    pointMass.fixEntity();
    EXPECT_TRUE(pointMass.isFixed());
}

TEST_F(PointMassTest, InstanceCountSingle)
{
    EXPECT_EQ(PointMass::nInstances, 0);

    {
        PointMass pointMass(mass);
        EXPECT_EQ(PointMass::nInstances, 1);
    }

    EXPECT_EQ(PointMass::nInstances, 0);
}

TEST_F(PointMassTest, InstanceCountMultiple)
{
    EXPECT_EQ(PointMass::nInstances, 0);

    {
        PointMass pointMass1(mass);
        PointMass pointMass2(mass, position);
        PointMass pointMass3(mass, position, velocity);
        EXPECT_EQ(PointMass::nInstances, 3);
    }

    EXPECT_EQ(PointMass::nInstances, 0);
}

TEST_F(PointMassTest, InstanceCountWithDestruction)
{
    EXPECT_EQ(PointMass::nInstances, 0);

    PointMass *pointMass1 = new PointMass(mass);
    EXPECT_EQ(PointMass::nInstances, 1);

    PointMass *pointMass2 = new PointMass(mass, position);
    EXPECT_EQ(PointMass::nInstances, 2);

    delete pointMass1;
    EXPECT_EQ(PointMass::nInstances, 1);

    delete pointMass2;
    EXPECT_EQ(PointMass::nInstances, 0);
}
