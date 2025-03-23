#include "decimal_prefix.h"
#include "length.h"
#include "metre.h"
#include <gtest/gtest.h>
#include <memory>

using namespace InertiaFX::Core::SI;

class LengthTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Default setup with 1 metre (base unit)
        defaultLength = std::make_unique<Length>(1.0, DecimalPrefix::Name::base);
    }

    std::unique_ptr<Length> defaultLength;
};

TEST_F(LengthTest, Constructor)
{
    EXPECT_EQ(defaultLength->getName(), "Length");
    EXPECT_EQ(defaultLength->getSymbol(), "l");
    EXPECT_EQ(defaultLength->getDescription(), "Represents the fundamental SI Length quantity.");
    EXPECT_EQ(defaultLength->getValue(), 1.0);
}

TEST_F(LengthTest, PrefixConversions)
{
    // Test all prefix multipliers
    struct TestCase
    {
        DecimalPrefix::Name prefix;
        double inputValue;
        double expectedBaseValue;
    };

    std::vector<TestCase> testCases = {
        {DecimalPrefix::Name::yotta, 1.0, 1e24}, {DecimalPrefix::Name::zetta, 1.0, 1e21},
        {DecimalPrefix::Name::exa, 1.0, 1e18},   {DecimalPrefix::Name::peta, 1.0, 1e15},
        {DecimalPrefix::Name::tera, 1.0, 1e12},  {DecimalPrefix::Name::giga, 1.0, 1e9},
        {DecimalPrefix::Name::mega, 1.0, 1e6},   {DecimalPrefix::Name::kilo, 1.0, 1e3},
        {DecimalPrefix::Name::hecto, 1.0, 1e2},  {DecimalPrefix::Name::deca, 1.0, 1e1},
        {DecimalPrefix::Name::base, 1.0, 1.0},   {DecimalPrefix::Name::deci, 1.0, 1e-1},
        {DecimalPrefix::Name::centi, 1.0, 1e-2}, {DecimalPrefix::Name::milli, 1.0, 1e-3},
        {DecimalPrefix::Name::micro, 1.0, 1e-6}, {DecimalPrefix::Name::nano, 1.0, 1e-9},
        {DecimalPrefix::Name::pico, 1.0, 1e-12}, {DecimalPrefix::Name::femto, 1.0, 1e-15},
        {DecimalPrefix::Name::atto, 1.0, 1e-18}, {DecimalPrefix::Name::zepto, 1.0, 1e-21},
        {DecimalPrefix::Name::yocto, 1.0, 1e-24}};

    for (const auto &tc : testCases)
    {
        auto length = std::make_unique<Length>(tc.inputValue, tc.prefix);
        EXPECT_DOUBLE_EQ(length->getValue(), tc.expectedBaseValue)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
    }
}

TEST_F(LengthTest, NonUnitValues)
{
    // Test non-unit values with different prefixes
    auto length1 = std::make_unique<Length>(2.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(length1->getValue(), 2500.0);

    auto length2 = std::make_unique<Length>(0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(length2->getValue(), 0.0005);
}

TEST_F(LengthTest, ZeroValue)
{
    auto length = std::make_unique<Length>(0.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(length->getValue(), 0.0);
}

TEST_F(LengthTest, NegativeValues)
{
    auto length = std::make_unique<Length>(-1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(length->getValue(), -1000.0);
}

TEST_F(LengthTest, LargeValues)
{
    auto length = std::make_unique<Length>(9.99999e99, DecimalPrefix::Name::yotta);
    EXPECT_GT(length->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(length->getValue()));
}

TEST_F(LengthTest, SmallValues)
{
    auto length = std::make_unique<Length>(1.0e-99, DecimalPrefix::Name::yocto);
    EXPECT_GT(length->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(length->getValue()));
}