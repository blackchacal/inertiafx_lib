#include "decimal_prefix.h"
#include "force.h"
#include <array>
#include <gtest/gtest.h>
#include <memory>
#include <vector>

using namespace InertiaFX::Core::SI;

class ForceTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Set a default force vector (in base units if prefix is "base")
        defaultValue = {1.0, 2.0, 3.0};
        defaultForce = std::make_unique<Force>(defaultValue, DecimalPrefix::Name::base);
    }

    std::array<double, 3> defaultValue;
    std::unique_ptr<Force> defaultForce;
};

TEST_F(ForceTest, Constructor)
{
    EXPECT_EQ(defaultForce->getName(), "Force");
    EXPECT_EQ(defaultForce->getSymbol(), "F");
    EXPECT_EQ(defaultForce->getDescription(), "Represents the derived SI Force quantity.");
    EXPECT_DOUBLE_EQ(defaultForce->getValue()[0], 1.0);
    EXPECT_DOUBLE_EQ(defaultForce->getValue()[1], 2.0);
    EXPECT_DOUBLE_EQ(defaultForce->getValue()[2], 3.0);
}

TEST_F(ForceTest, PrefixConversions)
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
        auto force = std::make_unique<Force>(defaultValue, tc.prefix);
        EXPECT_DOUBLE_EQ(force->getValue()[0], defaultValue[0] * tc.multiplier)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
        EXPECT_DOUBLE_EQ(force->getValue()[1], defaultValue[1] * tc.multiplier)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
        EXPECT_DOUBLE_EQ(force->getValue()[2], defaultValue[2] * tc.multiplier)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
    }
}

TEST_F(ForceTest, ZeroVector)
{
    std::array<double, 3> zeroVec = {0.0, 0.0, 0.0};
    auto force                    = std::make_unique<Force>(zeroVec, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(force->getValue()[0], 0.0);
    EXPECT_DOUBLE_EQ(force->getValue()[1], 0.0);
    EXPECT_DOUBLE_EQ(force->getValue()[2], 0.0);
}

TEST_F(ForceTest, NegativeValues)
{
    std::array<double, 3> negVec = {-1.0, -2.0, -3.0};
    auto force                   = std::make_unique<Force>(negVec, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(force->getValue()[0], -1.0 * 1e3);
    EXPECT_DOUBLE_EQ(force->getValue()[1], -2.0 * 1e3);
    EXPECT_DOUBLE_EQ(force->getValue()[2], -3.0 * 1e3);
}