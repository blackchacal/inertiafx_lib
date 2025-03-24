#include "metre.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class MetreTest : public ::testing::Test
{
  protected:
    Metre metre;
};

TEST_F(MetreTest, Constructor)
{
    EXPECT_EQ(metre.getName(), "metre");
    EXPECT_EQ(metre.getPluralName(), "metres");
    EXPECT_EQ(metre.getSymbol(), "m");
    EXPECT_EQ(metre.getDescription(),
              "The metre, symbol m, is the SI unit of length."
              "It is defined by taking the fixed numerical value of the speed of light"
              " in vacuum c to be 299 792 458 when expressed in the unit m s^–1, where the "
              "second is defined in terms of the caesium frequency ΔνCs.");
}

TEST_F(MetreTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::quetta), "Qm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::ronna), "Rm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::yotta), "Ym");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::zetta), "Zm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::exa), "Em");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::peta), "Pm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::tera), "Tm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::giga), "Gm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::mega), "Mm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::kilo), "km");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::hecto), "hm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::deca), "dam");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::base), "m");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::deci), "dm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::centi), "cm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::milli), "mm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::micro), "μm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::nano), "nm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::pico), "pm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::femto), "fm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::atto), "am");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::zepto), "zm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::yocto), "ym");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::ronto), "rm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::quecto), "qm");
}

TEST_F(MetreTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::Q), "Qm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::R), "Rm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::Y), "Ym");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::Z), "Zm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::E), "Em");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::P), "Pm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::T), "Tm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::G), "Gm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::M), "Mm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::k), "km");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::h), "hm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::da), "dam");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::base), "m");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::d), "dm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::c), "cm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::m), "mm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::mu), "μm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::n), "nm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::p), "pm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::f), "fm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::a), "am");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::z), "zm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::y), "ym");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::r), "rm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::q), "qm");
}

TEST_F(MetreTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(metre.toString(), "m");
}