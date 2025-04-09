#include "decimal_prefix.h"
#include "density.h"
#include <cmath>
#include <gtest/gtest.h>
#include <memory>
#include <vector>

using namespace InertiaFX::Core::SI;

class DensityTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Default volume with 1.0 in base units (kilogram per cubic metre)
        defaultDensity = std::make_unique<Density>(1.0, DecimalPrefix::Name::base);
    }

    std::unique_ptr<Density> defaultDensity;
};

TEST_F(DensityTest, Constructor)
{
    EXPECT_EQ(defaultDensity->getName(), "Density");
    EXPECT_EQ(defaultDensity->getSymbol(), "ρ");
    EXPECT_EQ(defaultDensity->getDescription(), "Represents the derived SI Density quantity.");
    // With no prefix, the stored value must be exactly 1.0 (in kilogram per cubic metre)
    EXPECT_DOUBLE_EQ(defaultDensity->getValue(), 1.0);
}

TEST_F(DensityTest, UnitNamesAndDescription)
{
    EXPECT_EQ(defaultDensity->getUnitName(), "kilogram per cubic metre");
    EXPECT_EQ(defaultDensity->getUnitPluralName(), "kilograms per cubic metre");
    EXPECT_EQ(defaultDensity->getUnitSymbol(), "kg m^-3");
    EXPECT_EQ(defaultDensity->getUnitDescription(),
              "The kilogram per cubic metre, symbol kg m^-3, is an SI coherent "
              "derived unit of density.");
}

TEST_F(DensityTest, PrefixConversions)
{
    struct TestCase
    {
        DecimalPrefix::Name prefix;
        double inputValue;
        double expectedBaseValue;
    };

    // Note: The multipliers here assume that DecimalPrefix::getMultiplier returns:
    // quetta: 1e30, ronna: 1e27, yotta: 1e24, ..., base: 1.0, ..., yocto: 1e-24, ronto: 1e-27,
    // quecto: 1e-30
    std::vector<TestCase> testCases = {
        {DecimalPrefix::Name::quetta, 1.0, 1e30},  {DecimalPrefix::Name::ronna, 1.0, 1e27},
        {DecimalPrefix::Name::yotta, 1.0, 1e24},   {DecimalPrefix::Name::zetta, 1.0, 1e21},
        {DecimalPrefix::Name::exa, 1.0, 1e18},     {DecimalPrefix::Name::peta, 1.0, 1e15},
        {DecimalPrefix::Name::tera, 1.0, 1e12},    {DecimalPrefix::Name::giga, 1.0, 1e9},
        {DecimalPrefix::Name::mega, 1.0, 1e6},     {DecimalPrefix::Name::kilo, 1.0, 1e3},
        {DecimalPrefix::Name::hecto, 1.0, 1e2},    {DecimalPrefix::Name::deca, 1.0, 1e1},
        {DecimalPrefix::Name::base, 1.0, 1.0},     {DecimalPrefix::Name::deci, 1.0, 1e-1},
        {DecimalPrefix::Name::centi, 1.0, 1e-2},   {DecimalPrefix::Name::milli, 1.0, 1e-3},
        {DecimalPrefix::Name::micro, 1.0, 1e-6},   {DecimalPrefix::Name::nano, 1.0, 1e-9},
        {DecimalPrefix::Name::pico, 1.0, 1e-12},   {DecimalPrefix::Name::femto, 1.0, 1e-15},
        {DecimalPrefix::Name::atto, 1.0, 1e-18},   {DecimalPrefix::Name::zepto, 1.0, 1e-21},
        {DecimalPrefix::Name::yocto, 1.0, 1e-24},  {DecimalPrefix::Name::ronto, 1.0, 1e-27},
        {DecimalPrefix::Name::quecto, 1.0, 1e-30},
    };

    for (const auto &tc : testCases)
    {
        auto volume = std::make_unique<Density>(tc.inputValue, tc.prefix);
        EXPECT_DOUBLE_EQ(volume->getValue(), tc.expectedBaseValue)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
    }
}

TEST_F(DensityTest, CommonUseCases)
{
    // Test some typical volume values.
    auto liter = std::make_unique<Density>(1.0, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(liter->getValue(), 1e-3);

    auto kiloliter = std::make_unique<Density>(1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(kiloliter->getValue(), 1e3);
}

TEST_F(DensityTest, NonUnitValues)
{
    // Test with values other than 1.0
    auto vol1 = std::make_unique<Density>(2.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(vol1->getValue(), 2.5 * 1e3);

    auto vol2 = std::make_unique<Density>(0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(vol2->getValue(), 0.5 * 1e-3);
}

TEST_F(DensityTest, ZeroValue)
{
    auto volume = std::make_unique<Density>(0.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(volume->getValue(), 0.0);
}

TEST_F(DensityTest, NegativeValues)
{
    // Although negative volume may not be physical, the implementation should handle it
    // mathematically.
    auto volume = std::make_unique<Density>(-1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(volume->getValue(), -1.0 * 1e3);
}

TEST_F(DensityTest, LargeValues)
{
    auto volume = std::make_unique<Density>(9.99999e99, DecimalPrefix::Name::yotta);
    EXPECT_GT(volume->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(volume->getValue()));
}

TEST_F(DensityTest, SmallValues)
{
    auto volume = std::make_unique<Density>(1.0e-99, DecimalPrefix::Name::yocto);
    EXPECT_GT(volume->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(volume->getValue()));
}