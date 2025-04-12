#include "decimal_prefix.h"
#include "volume.h"
#include <cmath>
#include <gtest/gtest.h>
#include <memory>
#include <vector>

using namespace InertiaFX::Core::SI;

class VolumeTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Default volume with 1.0 in base units (cubic metre)
        defaultVolume = std::make_unique<Volume>(1.0, DecimalPrefix::Name::base);
    }

    std::unique_ptr<Volume> defaultVolume;
};

TEST_F(VolumeTest, Constructor)
{
    EXPECT_EQ(defaultVolume->getName(), "Volume");
    EXPECT_EQ(defaultVolume->getSymbol(), "V");
    EXPECT_EQ(defaultVolume->getDescription(), "Represents the derived SI Volume quantity.");
    // With no prefix, the stored value must be exactly 1.0 (in cubic metres)
    EXPECT_DOUBLE_EQ(defaultVolume->getValue(), 1.0);
}

TEST_F(VolumeTest, UnitNamesAndDescription)
{
    EXPECT_EQ(defaultVolume->getUnitName(), "cubic metre");
    EXPECT_EQ(defaultVolume->getUnitPluralName(), "cubic metres");
    EXPECT_EQ(defaultVolume->getUnitSymbol(), "m^3");
    EXPECT_EQ(defaultVolume->getUnitDescription(),
              "The cubic metre, symbol m^3, is an SI coherent derived unit of volume.");
}

TEST_F(VolumeTest, PrefixConversions)
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
        auto volume = std::make_unique<Volume>(tc.inputValue, tc.prefix);
        EXPECT_DOUBLE_EQ(volume->getValue(), tc.expectedBaseValue)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
    }
}

TEST_F(VolumeTest, CommonUseCases)
{
    // Test some typical volume values.
    // For example: 1 liter is 1e-3 cubic metres.
    auto liter = std::make_unique<Volume>(1.0, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(liter->getValue(), 1e-3);

    // 1 kiloliter is 1e3 milliliters -> 1e-0 cubic metres.
    auto kiloliter = std::make_unique<Volume>(1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(kiloliter->getValue(), 1e3);
}

TEST_F(VolumeTest, NonUnitValues)
{
    // Test with values other than 1.0
    auto vol1 = std::make_unique<Volume>(2.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(vol1->getValue(), 2.5 * 1e3);

    auto vol2 = std::make_unique<Volume>(0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(vol2->getValue(), 0.5 * 1e-3);
}

TEST_F(VolumeTest, ZeroValue)
{
    auto volume = std::make_unique<Volume>(0.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(volume->getValue(), 0.0);
}

TEST_F(VolumeTest, NegativeValues)
{
    // Although negative volume may not be physical, the implementation should handle it
    // mathematically.
    auto volume = std::make_unique<Volume>(-1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(volume->getValue(), -1.0 * 1e3);
}

TEST_F(VolumeTest, LargeValues)
{
    auto volume = std::make_unique<Volume>(9.99999e99, DecimalPrefix::Name::yotta);
    EXPECT_GT(volume->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(volume->getValue()));
}

TEST_F(VolumeTest, SmallValues)
{
    auto volume = std::make_unique<Volume>(1.0e-99, DecimalPrefix::Name::yocto);
    EXPECT_GT(volume->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(volume->getValue()));
}

TEST_F(VolumeTest, AdditionOperator)
{
    Volume vol1(1.0, DecimalPrefix::Name::base);
    Volume vol2(2.0, DecimalPrefix::Name::base);
    auto result = vol1 + vol2;

    EXPECT_DOUBLE_EQ(result.getValue(), 3.0);
}