#include "metre_per_second_sq.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class MetrePerSecondSqTest : public ::testing::Test
{
  protected:
    MetrePerSecondSq mps2;
};

TEST_F(MetrePerSecondSqTest, Constructor)
{
    EXPECT_EQ(mps2.getName(), "metre per second squared");
    EXPECT_EQ(mps2.getPluralName(), "metres per second squared");
    EXPECT_EQ(mps2.getSymbol(), "m s^-2");
    EXPECT_EQ(mps2.getDescription(), "The metre per second squared, symbol m s^-2 or m/s^2, is a "
                                     "derived SI unit of acceleration.");
}

TEST_F(MetrePerSecondSqTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::quetta), "Qm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::ronna), "Rm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::yotta), "Ym s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::zetta), "Zm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::exa), "Em s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::peta), "Pm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::tera), "Tm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::giga), "Gm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::mega), "Mm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::kilo), "km s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::hecto), "hm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::deca), "dam s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::base), "m s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::deci), "dm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::centi), "cm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::milli), "mm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::micro), "μm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::nano), "nm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::pico), "pm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::femto), "fm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::atto), "am s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::zepto), "zm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::yocto), "ym s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::ronto), "rm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Name::quecto), "qm s^-2");
}

TEST_F(MetrePerSecondSqTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::Q), "Qm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::R), "Rm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::Y), "Ym s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::Z), "Zm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::E), "Em s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::P), "Pm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::T), "Tm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::G), "Gm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::M), "Mm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::k), "km s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::h), "hm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::da), "dam s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::base), "m s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::d), "dm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::c), "cm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::m), "mm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::mu), "μm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::n), "nm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::p), "pm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::f), "fm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::a), "am s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::z), "zm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::y), "ym s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::r), "rm s^-2");
    EXPECT_EQ(mps2.toString(DecimalPrefix::Symbol::q), "qm s^-2");
}

TEST_F(MetrePerSecondSqTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(mps2.toString(), "m s^-2");
}