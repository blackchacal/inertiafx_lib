#include "decimal_prefix.h"
#include "volume.h"
#include <cmath>
#include <gtest/gtest.h>
#include <memory>
#include <numbers>
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
    EXPECT_DOUBLE_EQ(defaultVolume->getValue(), 4.0 / 3.0 * std::numbers::pi * std::pow(1.0, 3));
}

TEST_F(VolumeTest, ConstructorWithDimensions)
{
    Volume vol1(2.0, 3.0, 4.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(vol1.getValue(), 24.0);

    Volume vol2(1.0, 1.0, 1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(vol2.getValue(), 1.0 * 1.0 * 1.0 * 1e9);

    Volume vol3(0.5, 0.5, 0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(vol3.getValue(), 0.5 * 0.5 * 0.5 * 1e-9);
}

TEST_F(VolumeTest, ConstructorWithSphereRadius)
{
    Volume sphereVol1(1.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(sphereVol1.getValue(), (4.0 / 3.0) * std::numbers::pi * std::pow(1.0, 3));

    Volume sphereVol2(0.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(sphereVol2.getValue(),
                     (4.0 / 3.0) * std::numbers::pi * std::pow(0.5 * 1e3, 3));

    Volume sphereVol3(2.0, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(sphereVol3.getValue(),
                     (4.0 / 3.0) * std::numbers::pi * std::pow(2.0 * 1e-3, 3));
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
        {DecimalPrefix::Name::quetta, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e30, 3)},
        {DecimalPrefix::Name::ronna, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e27, 3)},
        {DecimalPrefix::Name::yotta, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e24, 3)},
        {DecimalPrefix::Name::zetta, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e21, 3)},
        {DecimalPrefix::Name::exa, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e18, 3)},
        {DecimalPrefix::Name::peta, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e15, 3)},
        {DecimalPrefix::Name::tera, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e12, 3)},
        {DecimalPrefix::Name::giga, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e9, 3)},
        {DecimalPrefix::Name::mega, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e6, 3)},
        {DecimalPrefix::Name::kilo, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e3, 3)},
        {DecimalPrefix::Name::hecto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e2, 3)},
        {DecimalPrefix::Name::deca, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e1, 3)},
        {DecimalPrefix::Name::base, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1.0, 3)},
        {DecimalPrefix::Name::deci, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-1, 3)},
        {DecimalPrefix::Name::centi, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-2, 3)},
        {DecimalPrefix::Name::milli, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-3, 3)},
        {DecimalPrefix::Name::micro, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-6, 3)},
        {DecimalPrefix::Name::nano, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-9, 3)},
        {DecimalPrefix::Name::pico, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-12, 3)},
        {DecimalPrefix::Name::femto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-15, 3)},
        {DecimalPrefix::Name::atto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-18, 3)},
        {DecimalPrefix::Name::zepto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-21, 3)},
        {DecimalPrefix::Name::yocto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-24, 3)},
        {DecimalPrefix::Name::ronto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-27, 3)},
        {DecimalPrefix::Name::quecto, 1.0, (4.0 / 3.0) * std::numbers::pi * std::pow(1e-30, 3)},
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
    EXPECT_DOUBLE_EQ(liter->getValue(), (4.0 / 3.0) * std::numbers::pi * std::pow(1e-3, 3));

    // 1 kiloliter is 1e3 milliliters -> 1e-0 cubic metres.
    auto kiloliter = std::make_unique<Volume>(1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(kiloliter->getValue(), (4.0 / 3.0) * std::numbers::pi * std::pow(1e3, 3));
}

TEST_F(VolumeTest, NonUnitValues)
{
    // Test with values other than 1.0
    auto vol1 = std::make_unique<Volume>(2.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(vol1->getValue(), (4.0 / 3.0) * std::numbers::pi * std::pow(2.5e3, 3));

    auto vol2 = std::make_unique<Volume>(0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(vol2->getValue(), (4.0 / 3.0) * std::numbers::pi * std::pow(0.5e-3, 3));
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
    EXPECT_DOUBLE_EQ(volume->getValue(), (4.0 / 3.0) * std::numbers::pi * std::pow(-1e3, 3));
}

TEST_F(VolumeTest, LargeValues)
{
    auto volume = std::make_unique<Volume>(9.99999e99, DecimalPrefix::Name::yotta);
    EXPECT_GT(volume->getValue(), 0.0);
    EXPECT_TRUE(std::isinf(volume->getValue()));
}

TEST_F(VolumeTest, SmallValues)
{
    auto volume = std::make_unique<Volume>(1.0e-99, DecimalPrefix::Name::yocto);
    EXPECT_EQ(volume->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(volume->getValue()));
}

TEST_F(VolumeTest, AdditionOperator)
{
    Volume vol1(1.0, DecimalPrefix::Name::base);
    Volume vol2(2.0, DecimalPrefix::Name::base);
    auto result = vol1 + vol2;

    EXPECT_DOUBLE_EQ(result.getValue(), vol1.getValue() + vol2.getValue());
}

TEST_F(VolumeTest, GetBoxDimensions)
{
    Volume boxVolume(2.0, 3.0, 4.0, DecimalPrefix::Name::base);
    auto [length, width, height] = boxVolume.getBoxDimensions();
    EXPECT_DOUBLE_EQ(length, 2.0);
    EXPECT_DOUBLE_EQ(width, 3.0);
    EXPECT_DOUBLE_EQ(height, 4.0);
}

TEST_F(VolumeTest, GetSphereDimensions)
{
    Volume sphereVolume(1.0, DecimalPrefix::Name::base);
    double radius = sphereVolume.getSphereDimensions();
    EXPECT_DOUBLE_EQ(radius, 1.0);
}

TEST_F(VolumeTest, GetType)
{
    Volume boxVolume(2.0, 3.0, 4.0, DecimalPrefix::Name::base);
    EXPECT_EQ(boxVolume.getType(), Volume::Type::Box);

    Volume sphereVolume(1.0, DecimalPrefix::Name::base);
    EXPECT_EQ(sphereVolume.getType(), Volume::Type::Sphere);
}