#include "kilogram.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class KilogramTest : public ::testing::Test
{
  protected:
    Kilogram kilogram;
};

TEST_F(KilogramTest, ConstructorInitializesBaseClassCorrectly)
{
    EXPECT_EQ(kilogram.getName(), "kilogram");
    EXPECT_EQ(kilogram.getPluralName(), "kilograms");
    EXPECT_EQ(kilogram.getSymbol(), "kg");
    EXPECT_EQ(kilogram.getDescription(),
              "The kilogram, symbol kg, is the SI unit of mass. "
              "It is defined by taking the fixed numerical value of the"
              " Planck constant h to be 6.626 070 15 x 10^–34 when expressed"
              " in the unit J s, which is equal to kg m^2 s^–1, where the metre"
              " and the second are defined in terms of c and ΔνCs.");
}

TEST_F(KilogramTest, ToStringNoParamsReturnsBaseSymbol)
{
    EXPECT_EQ(kilogram.toString(), "kg");
}

TEST_F(KilogramTest, ToStringWithPrefixNameHandlesAllCases)
{
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::kilo), "ton");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::deci), "hg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::centi), "dag");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::milli), "g");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::micro), "mg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::nano), "\u03BCg");

    // Test default case
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::quetta), "Qkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::ronna), "Rkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::yotta), "Ykg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::zetta), "Zkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::exa), "Ekg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::peta), "Pkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::tera), "Tkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::giga), "Gkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::mega), "Mkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::hecto), "hkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::deca), "dakg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::pico), "pkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::femto), "fkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::atto), "akg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::zepto), "zkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::yocto), "ykg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::ronto), "rkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::quecto), "qkg");
}

TEST_F(KilogramTest, ToStringWithPrefixSymbolHandlesAllCases)
{
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::k), "ton");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::d), "hg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::c), "dag");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::m), "g");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::mu), "mg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::n), "\u03BCg");

    // Test default case
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::Q), "Qkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::R), "Rkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::Y), "Ykg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::Z), "Zkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::E), "Ekg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::P), "Pkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::T), "Tkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::G), "Gkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::M), "Mkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::h), "hkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::da), "dakg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::p), "pkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::f), "fkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::a), "akg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::z), "zkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::y), "ykg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::r), "rkg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::q), "qkg");
}

TEST_F(KilogramTest, ToStringHandlesBaseCase)
{
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::base), "kg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::base), "kg");
}