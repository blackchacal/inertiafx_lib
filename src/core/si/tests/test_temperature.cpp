#include "decimal_prefix.h"
#include "temperature.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>

using namespace InertiaFX::Core::SI;

class TemperatureTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        defaultValue       = 300.0;
        defaultTemperature = std::make_unique<Temperature>(defaultValue, DecimalPrefix::Name::base);
    }
    double defaultValue;
    std::unique_ptr<Temperature> defaultTemperature;
};

TEST_F(TemperatureTest, Constructor)
{
    EXPECT_EQ(defaultTemperature->getName(), "Temperature");
    EXPECT_EQ(defaultTemperature->getSymbol(), "T");
    EXPECT_EQ(defaultTemperature->getDescription(),
              "Represents the fundamental SI Temperature quantity.");
    EXPECT_DOUBLE_EQ(defaultTemperature->getValue(), 300.0);
}

TEST_F(TemperatureTest, DefaultConstructor)
{
    Temperature defaultTemperature;
    EXPECT_EQ(defaultTemperature.getName(), "Temperature");
    EXPECT_EQ(defaultTemperature.getSymbol(), "T");
    EXPECT_EQ(defaultTemperature.getDescription(),
              "Represents the fundamental SI Temperature quantity.");
    EXPECT_DOUBLE_EQ(defaultTemperature.getValue(), 273.15);
}

TEST_F(TemperatureTest, PrefixConversions)
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
        auto temperature = std::make_unique<Temperature>(defaultValue, tc.prefix);
        EXPECT_DOUBLE_EQ(temperature->getValue(), defaultValue * tc.multiplier);
    }
}

TEST_F(TemperatureTest, ZeroValue)
{
    auto temperature = std::make_unique<Temperature>(0.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(temperature->getValue(), 0.0);
}

TEST_F(TemperatureTest, NegativeValue)
{
    auto temperature = std::make_unique<Temperature>(-100.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(temperature->getValue(), 0.0);  // Should not allow negative values
}

TEST_F(TemperatureTest, CopyConstructor)
{
    Temperature t1(defaultValue, DecimalPrefix::Name::base);
    Temperature t2(t1);
    EXPECT_DOUBLE_EQ(t2.getValue(), 300.0);
}

TEST_F(TemperatureTest, AssignmentOperator)
{
    Temperature t1(defaultValue, DecimalPrefix::Name::base);
    Temperature t2;
    t2 = t1;
    EXPECT_DOUBLE_EQ(t2.getValue(), 300.0);
}

TEST_F(TemperatureTest, AdditionOperator)
{
    Temperature t1(100.0, DecimalPrefix::Name::base);
    Temperature t2(200.0, DecimalPrefix::Name::base);
    Temperature result = t1 + t2;
    EXPECT_DOUBLE_EQ(result.getValue(), 300.0);
}
