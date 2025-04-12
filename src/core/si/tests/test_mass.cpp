#include "decimal_prefix.h"
#include "kilogram.h"
#include "mass.h"
#include <gtest/gtest.h>
#include <memory>

using namespace InertiaFX::Core::SI;

class MassTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Default setup with 1 kilogram (base unit)
        defaultMass = std::make_unique<Mass>(1.0, DecimalPrefix::Name::base);
    }

    std::unique_ptr<Mass> defaultMass;
};

TEST_F(MassTest, Constructor)
{
    EXPECT_EQ(defaultMass->getName(), "Mass");
    EXPECT_EQ(defaultMass->getSymbol(), "m");
    EXPECT_EQ(defaultMass->getDescription(), "Represents the fundamental SI Mass quantity.");
    EXPECT_EQ(defaultMass->getValue(), 1.0);
}

TEST_F(MassTest, PrefixConversions)
{
    struct TestCase
    {
        DecimalPrefix::Name prefix;
        double inputValue;
        double expectedBaseValue;
    };

    std::vector<TestCase> testCases = {
        {DecimalPrefix::Name::quetta, 1.0, 1e30}, {DecimalPrefix::Name::ronna, 1.0, 1e27},
        {DecimalPrefix::Name::yotta, 1.0, 1e24},  {DecimalPrefix::Name::zetta, 1.0, 1e21},
        {DecimalPrefix::Name::exa, 1.0, 1e18},    {DecimalPrefix::Name::peta, 1.0, 1e15},
        {DecimalPrefix::Name::tera, 1.0, 1e12},   {DecimalPrefix::Name::giga, 1.0, 1e9},
        {DecimalPrefix::Name::mega, 1.0, 1e6},    {DecimalPrefix::Name::kilo, 1.0, 1e3},
        {DecimalPrefix::Name::hecto, 1.0, 1e2},   {DecimalPrefix::Name::deca, 1.0, 1e1},
        {DecimalPrefix::Name::base, 1.0, 1.0},    {DecimalPrefix::Name::deci, 1.0, 1e-1},
        {DecimalPrefix::Name::centi, 1.0, 1e-2},  {DecimalPrefix::Name::milli, 1.0, 1e-3},
        {DecimalPrefix::Name::micro, 1.0, 1e-6},  {DecimalPrefix::Name::nano, 1.0, 1e-9},
        {DecimalPrefix::Name::pico, 1.0, 1e-12},  {DecimalPrefix::Name::femto, 1.0, 1e-15},
        {DecimalPrefix::Name::atto, 1.0, 1e-18},  {DecimalPrefix::Name::zepto, 1.0, 1e-21},
        {DecimalPrefix::Name::yocto, 1.0, 1e-24}, {DecimalPrefix::Name::ronto, 1.0, 1e-27},
        {DecimalPrefix::Name::quecto, 1.0, 1e-30}};

    for (const auto &tc : testCases)
    {
        auto mass = std::make_unique<Mass>(tc.inputValue, tc.prefix);
        EXPECT_DOUBLE_EQ(mass->getValue(), tc.expectedBaseValue)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
    }
}

TEST_F(MassTest, CommonUseCases)
{
    // Test common mass values
    auto gram = std::make_unique<Mass>(1.0, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(gram->getValue(), 0.001);

    auto tonne = std::make_unique<Mass>(1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(tonne->getValue(), 1000.0);

    auto milligram = std::make_unique<Mass>(1.0, DecimalPrefix::Name::micro);
    EXPECT_DOUBLE_EQ(milligram->getValue(), 0.000001);
}

TEST_F(MassTest, NonUnitValues)
{
    // Test non-unit values with different prefixes
    auto mass1 = std::make_unique<Mass>(2.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(mass1->getValue(), 2500.0);

    auto mass2 = std::make_unique<Mass>(0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(mass2->getValue(), 0.0005);
}

TEST_F(MassTest, ZeroValue)
{
    auto mass = std::make_unique<Mass>(0.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(mass->getValue(), 0.0);
}

TEST_F(MassTest, NegativeValues)
{
    auto mass = std::make_unique<Mass>(-1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(mass->getValue(), -1000.0);
}

TEST_F(MassTest, LargeValues)
{
    auto mass = std::make_unique<Mass>(9.99999e99, DecimalPrefix::Name::yotta);
    EXPECT_GT(mass->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(mass->getValue()));
}

TEST_F(MassTest, SmallValues)
{
    auto mass = std::make_unique<Mass>(1.0e-99, DecimalPrefix::Name::yocto);
    EXPECT_GT(mass->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(mass->getValue()));
}

TEST_F(MassTest, DefaultConstructor)
{
    Mass defaultMass;
    EXPECT_EQ(defaultMass.getName(), "Mass");
    EXPECT_EQ(defaultMass.getSymbol(), "m");
    EXPECT_EQ(defaultMass.getDescription(), "Represents the fundamental SI Mass quantity.");
    EXPECT_DOUBLE_EQ(defaultMass.getValue(), 1.0);
}

TEST_F(MassTest, ParameterizedConstructor)
{
    Mass mass(10.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(mass.getValue(), 10.0 * 1e3);
}

TEST_F(MassTest, AdditionOperator)
{
    Mass mass1(1.0, DecimalPrefix::Name::base);
    Mass mass2(2.0, DecimalPrefix::Name::base);
    auto result = mass1 + mass2;

    EXPECT_DOUBLE_EQ(result.getValue(), 3.0);
}