#include "decimal_prefix.h"
#include "pressure.h"
#include <array>
#include <gtest/gtest.h>
#include <memory>
#include <vector>

using namespace InertiaFX::Core::SI;

class PressureTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        defaultValue    = {1.0, 2.0, 3.0};
        defaultPressure = std::make_unique<Pressure>(defaultValue, DecimalPrefix::Name::base);
    }
    std::array<double, 3> defaultValue;
    std::unique_ptr<Pressure> defaultPressure;
};

TEST_F(PressureTest, Constructor)
{
    EXPECT_EQ(defaultPressure->getName(), "Pressure");
    EXPECT_EQ(defaultPressure->getSymbol(), "p");
    EXPECT_EQ(defaultPressure->getDescription(), "Represents the derived SI Pressure quantity.");
    EXPECT_DOUBLE_EQ(defaultPressure->getValue()[0], 1.0);
    EXPECT_DOUBLE_EQ(defaultPressure->getValue()[1], 2.0);
    EXPECT_DOUBLE_EQ(defaultPressure->getValue()[2], 3.0);
}

TEST_F(PressureTest, DefaultConstructor)
{
    Pressure defaultPressure;
    EXPECT_EQ(defaultPressure.getName(), "Pressure");
    EXPECT_EQ(defaultPressure.getSymbol(), "p");
    EXPECT_EQ(defaultPressure.getDescription(), "Represents the derived SI Pressure quantity.");
    EXPECT_DOUBLE_EQ(defaultPressure.getValue()[0], 0.0);
    EXPECT_DOUBLE_EQ(defaultPressure.getValue()[1], 0.0);
    EXPECT_DOUBLE_EQ(defaultPressure.getValue()[2], 0.0);
}

TEST_F(PressureTest, PrefixConversions)
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
        auto pressure = std::make_unique<Pressure>(defaultValue, tc.prefix);
        EXPECT_DOUBLE_EQ(pressure->getValue()[0], defaultValue[0] * tc.multiplier);
        EXPECT_DOUBLE_EQ(pressure->getValue()[1], defaultValue[1] * tc.multiplier);
        EXPECT_DOUBLE_EQ(pressure->getValue()[2], defaultValue[2] * tc.multiplier);
    }
}

TEST_F(PressureTest, ZeroVector)
{
    std::array<double, 3> zeroVec = {0.0, 0.0, 0.0};
    auto pressure                 = std::make_unique<Pressure>(zeroVec, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(pressure->getValue()[0], 0.0);
    EXPECT_DOUBLE_EQ(pressure->getValue()[1], 0.0);
    EXPECT_DOUBLE_EQ(pressure->getValue()[2], 0.0);
}

TEST_F(PressureTest, NegativeValues)
{
    std::array<double, 3> negVec = {-1.0, -2.0, -3.0};
    auto pressure                = std::make_unique<Pressure>(negVec, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(pressure->getValue()[0], -1.0 * 1e3);
    EXPECT_DOUBLE_EQ(pressure->getValue()[1], -2.0 * 1e3);
    EXPECT_DOUBLE_EQ(pressure->getValue()[2], -3.0 * 1e3);
}

TEST_F(PressureTest, CopyConstructor)
{
    Pressure p1(defaultValue, DecimalPrefix::Name::base);
    Pressure p2(p1);
    EXPECT_DOUBLE_EQ(p2.getValue()[0], 1.0);
    EXPECT_DOUBLE_EQ(p2.getValue()[1], 2.0);
    EXPECT_DOUBLE_EQ(p2.getValue()[2], 3.0);
}

TEST_F(PressureTest, AssignmentOperator)
{
    Pressure p1(defaultValue, DecimalPrefix::Name::base);
    Pressure p2;
    p2 = p1;
    EXPECT_DOUBLE_EQ(p2.getValue()[0], 1.0);
    EXPECT_DOUBLE_EQ(p2.getValue()[1], 2.0);
    EXPECT_DOUBLE_EQ(p2.getValue()[2], 3.0);
}

TEST_F(PressureTest, AdditionOperator)
{
    std::array<double, 3> value1 = {1.0, 2.0, 3.0};
    std::array<double, 3> value2 = {4.0, 5.0, 6.0};
    Pressure p1(value1, DecimalPrefix::Name::base);
    Pressure p2(value2, DecimalPrefix::Name::base);
    Pressure result = p1 + p2;
    EXPECT_DOUBLE_EQ(result.getValue()[0], 5.0);
    EXPECT_DOUBLE_EQ(result.getValue()[1], 7.0);
    EXPECT_DOUBLE_EQ(result.getValue()[2], 9.0);
}
