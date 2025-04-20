#include "liquid.h"
#include "gtest/gtest.h"

using namespace InertiaFX::Core::Engine;

// Test fixture for the Liquid class
class LiquidTest : public ::testing::Test
{
  protected:
    Liquid liquid;

    void SetUp() override
    {
        // Initialize the liquid object if needed
        liquid.setViscosity(0.0);  // Default viscosity
    }
};

// Test default viscosity
TEST_F(LiquidTest, DefaultViscosity)
{
    EXPECT_EQ(liquid.getViscosity(), 0.0);
}

// Test setting and getting viscosity
TEST_F(LiquidTest, SetAndGetViscosity)
{
    double testViscosity = 1.5;
    liquid.setViscosity(testViscosity);
    EXPECT_EQ(liquid.getViscosity(), testViscosity);
}

// Test setting a negative viscosity
TEST_F(LiquidTest, NegativeViscosity)
{
    double negativeViscosity = -1.0;
    liquid.setViscosity(negativeViscosity);
    EXPECT_EQ(liquid.getViscosity(), negativeViscosity);
}

// Test setting a very large viscosity
TEST_F(LiquidTest, LargeViscosity)
{
    double largeViscosity = 1e6;
    liquid.setViscosity(largeViscosity);
    EXPECT_EQ(liquid.getViscosity(), largeViscosity);
}