#include "acceleration.h"
#include <array>
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class AccelerationTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        defaultValue = {1.0, 2.0, 3.0};
        defaultAcceleration =
            std::make_unique<Acceleration>(defaultValue, DecimalPrefix::Name::base);
    }

    std::array<double, 3> defaultValue;
    std::unique_ptr<Acceleration> defaultAcceleration;
};

TEST_F(AccelerationTest, Constructor)
{
    EXPECT_EQ(defaultAcceleration->getName(), "Acceleration");
    EXPECT_EQ(defaultAcceleration->getSymbol(), "a");
    EXPECT_EQ(defaultAcceleration->getDescription(),
              "Represents the derived SI Acceleration quantity.");

    EXPECT_DOUBLE_EQ(defaultAcceleration->getValue()[0], 1.0);
    EXPECT_DOUBLE_EQ(defaultAcceleration->getValue()[1], 2.0);
    EXPECT_DOUBLE_EQ(defaultAcceleration->getValue()[2], 3.0);
}

TEST_F(AccelerationTest, UnitNamesAndDescription)
{
    EXPECT_EQ(defaultAcceleration->getUnitName(), "metre per second squared");
    EXPECT_EQ(defaultAcceleration->getUnitPluralName(), "metres per second squared");
    EXPECT_EQ(defaultAcceleration->getUnitSymbol(), "m s^-2");
    EXPECT_EQ(defaultAcceleration->getUnitDescription(),
              "The metre per second squared, symbol m s^-2, is an SI coherent derived unit of "
              "acceleration.");
}

TEST_F(AccelerationTest, PrefixConversions)
{
    struct TestCase
    {
        DecimalPrefix::Name prefix;
        double multiplier;
    };

    std::vector<TestCase> testCases = {
        {DecimalPrefix::Name::quetta, 1e30}, {DecimalPrefix::Name::ronna, 1e27},
        {DecimalPrefix::Name::yotta, 1e24},  {DecimalPrefix::Name::zetta, 1e21},
        {DecimalPrefix::Name::exa, 1e18},    {DecimalPrefix::Name::peta, 1e15},
        {DecimalPrefix::Name::tera, 1e12},   {DecimalPrefix::Name::giga, 1e9},
        {DecimalPrefix::Name::mega, 1e6},    {DecimalPrefix::Name::kilo, 1e3},
        {DecimalPrefix::Name::hecto, 1e2},   {DecimalPrefix::Name::deca, 1e1},
        {DecimalPrefix::Name::base, 1.0},    {DecimalPrefix::Name::deci, 1e-1},
        {DecimalPrefix::Name::centi, 1e-2},  {DecimalPrefix::Name::milli, 1e-3},
        {DecimalPrefix::Name::micro, 1e-6},  {DecimalPrefix::Name::nano, 1e-9},
        {DecimalPrefix::Name::pico, 1e-12},  {DecimalPrefix::Name::femto, 1e-15},
        {DecimalPrefix::Name::atto, 1e-18},  {DecimalPrefix::Name::zepto, 1e-21},
        {DecimalPrefix::Name::yocto, 1e-24}, {DecimalPrefix::Name::ronto, 1e-27},
        {DecimalPrefix::Name::quecto, 1e-30}};

    for (const auto &tc : testCases)
    {
        auto acceleration = std::make_unique<Acceleration>(defaultValue, tc.prefix);
        EXPECT_DOUBLE_EQ(acceleration->getValue()[0], defaultValue[0] * tc.multiplier);
        EXPECT_DOUBLE_EQ(acceleration->getValue()[1], defaultValue[1] * tc.multiplier);
        EXPECT_DOUBLE_EQ(acceleration->getValue()[2], defaultValue[2] * tc.multiplier);
    }
}

TEST_F(AccelerationTest, ZeroVector)
{
    std::array<double, 3> zeroVector = {0.0, 0.0, 0.0};
    auto acceleration = std::make_unique<Acceleration>(zeroVector, DecimalPrefix::Name::base);

    EXPECT_DOUBLE_EQ(acceleration->getValue()[0], 0.0);
    EXPECT_DOUBLE_EQ(acceleration->getValue()[1], 0.0);
    EXPECT_DOUBLE_EQ(acceleration->getValue()[2], 0.0);
}

TEST_F(AccelerationTest, NegativeValues)
{
    std::array<double, 3> negativeVector = {-1.0, -2.0, -3.0};
    auto acceleration = std::make_unique<Acceleration>(negativeVector, DecimalPrefix::Name::kilo);

    EXPECT_DOUBLE_EQ(acceleration->getValue()[0], -1000.0);
    EXPECT_DOUBLE_EQ(acceleration->getValue()[1], -2000.0);
    EXPECT_DOUBLE_EQ(acceleration->getValue()[2], -3000.0);
}