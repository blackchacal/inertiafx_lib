#include "metre_per_second.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class MetrePerSecondTest : public ::testing::Test
{
  protected:
    MetrePerSecond mps;
};

TEST_F(MetrePerSecondTest, Constructor)
{
    EXPECT_EQ(mps.getName(), "metre per second");
    EXPECT_EQ(mps.getPluralName(), "metres per second");
    EXPECT_EQ(mps.getSymbol(), "m s^-1");
    EXPECT_EQ(mps.getDescription(),
              "The metre per second, symbol m s^-1 or m/s, is a derived SI unit of speed or "
              "velocity.");
}

TEST_F(MetrePerSecondTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::quetta), "Qm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::ronna), "Rm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::yotta), "Ym s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::zetta), "Zm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::exa), "Em s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::peta), "Pm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::tera), "Tm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::giga), "Gm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::mega), "Mm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::kilo), "km s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::hecto), "hm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::deca), "dam s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::base), "m s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::deci), "dm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::centi), "cm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::milli), "mm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::micro), "μm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::nano), "nm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::pico), "pm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::femto), "fm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::atto), "am s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::zepto), "zm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::yocto), "ym s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::ronto), "rm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Name::quecto), "qm s^-1");
}

TEST_F(MetrePerSecondTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::Q), "Qm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::R), "Rm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::Y), "Ym s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::Z), "Zm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::E), "Em s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::P), "Pm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::T), "Tm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::G), "Gm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::M), "Mm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::k), "km s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::h), "hm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::da), "dam s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::base), "m s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::d), "dm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::c), "cm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::m), "mm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::mu), "μm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::n), "nm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::p), "pm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::f), "fm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::a), "am s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::z), "zm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::y), "ym s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::r), "rm s^-1");
    EXPECT_EQ(mps.toString(DecimalPrefix::Symbol::q), "qm s^-1");
}

TEST_F(MetrePerSecondTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(mps.toString(), "m s^-1");
}