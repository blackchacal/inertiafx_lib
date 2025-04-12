#include "decimal_prefix.h"
#include "second.h"
#include "si_time.h"
#include <gtest/gtest.h>
#include <memory>

using namespace InertiaFX::Core::SI;

class TimeTest : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        // Default setup with 1 second (base unit)
        defaultTime = std::make_unique<Time>(1.0, DecimalPrefix::Name::base);
    }

    std::unique_ptr<Time> defaultTime;
};

TEST_F(TimeTest, Constructor)
{
    EXPECT_EQ(defaultTime->getName(), "Time");
    EXPECT_EQ(defaultTime->getSymbol(), "t");
    EXPECT_EQ(defaultTime->getDescription(), "Represents the fundamental SI Time quantity.");
    EXPECT_EQ(defaultTime->getValue(), 1.0);
}

TEST_F(TimeTest, PrefixConversions)
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
        auto time = std::make_unique<Time>(tc.inputValue, tc.prefix);
        EXPECT_DOUBLE_EQ(time->getValue(), tc.expectedBaseValue)
            << "Failed for prefix: " << static_cast<int>(tc.prefix);
    }
}

TEST_F(TimeTest, CommonTimeScales)
{
    // Test common time scales
    auto millisecond = std::make_unique<Time>(1.0, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(millisecond->getValue(), 0.001);

    auto microsecond = std::make_unique<Time>(1.0, DecimalPrefix::Name::micro);
    EXPECT_DOUBLE_EQ(microsecond->getValue(), 0.000001);

    auto nanosecond = std::make_unique<Time>(1.0, DecimalPrefix::Name::nano);
    EXPECT_DOUBLE_EQ(nanosecond->getValue(), 1e-9);
}

TEST_F(TimeTest, NonUnitValues)
{
    // Test non-unit values with different prefixes
    auto time1 = std::make_unique<Time>(2.5, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(time1->getValue(), 2500.0);

    auto time2 = std::make_unique<Time>(0.5, DecimalPrefix::Name::milli);
    EXPECT_DOUBLE_EQ(time2->getValue(), 0.0005);
}

TEST_F(TimeTest, ZeroValue)
{
    auto time = std::make_unique<Time>(0.0, DecimalPrefix::Name::base);
    EXPECT_DOUBLE_EQ(time->getValue(), 0.0);
}

TEST_F(TimeTest, NegativeValues)
{
    auto time = std::make_unique<Time>(-1.0, DecimalPrefix::Name::kilo);
    EXPECT_DOUBLE_EQ(time->getValue(), -1000.0);
}

TEST_F(TimeTest, LargeValues)
{
    auto time = std::make_unique<Time>(9.99999e99, DecimalPrefix::Name::yotta);
    EXPECT_GT(time->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(time->getValue()));
}

TEST_F(TimeTest, SmallValues)
{
    auto time = std::make_unique<Time>(1.0e-99, DecimalPrefix::Name::yocto);
    EXPECT_GT(time->getValue(), 0.0);
    EXPECT_FALSE(std::isinf(time->getValue()));
}

TEST_F(TimeTest, AdditionOperator)
{
    Time time1(1.0, DecimalPrefix::Name::base);
    Time time2(2.0, DecimalPrefix::Name::base);
    auto result = time1 + time2;

    EXPECT_DOUBLE_EQ(result.getValue(), 3.0);
}