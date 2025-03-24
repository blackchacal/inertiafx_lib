#include "candela.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class CandelaTest : public ::testing::Test
{
  protected:
    Candela candela;
};

TEST_F(CandelaTest, Constructor)
{
    EXPECT_EQ(candela.getName(), "candela");
    EXPECT_EQ(candela.getPluralName(), "candelas");
    EXPECT_EQ(candela.getSymbol(), "cd");
    EXPECT_EQ(candela.getDescription(),
              "The candela, symbol cd, is the SI unit of luminous intensity "
              "in a given direction. It is defined by taking the fixed numerical "
              "value of the luminous efficacy of monochromatic radiation of "
              "frequency 540 x 1012 Hz, Kcd, to be 683 when expressed in the unit "
              "lm W^–1, which is equal to cd sr W^–1, or cd sr kg^–1 m^–2 s^3, where "
              "the kilogram, metre and second are defined in terms of h, c and ΔνCs.");
}

TEST_F(CandelaTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::quetta), "Qcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::ronna), "Rcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::yotta), "Ycd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::zetta), "Zcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::exa), "Ecd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::peta), "Pcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::tera), "Tcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::giga), "Gcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::mega), "Mcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::kilo), "kcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::hecto), "hcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::deca), "dacd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::base), "cd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::deci), "dcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::centi), "ccd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::milli), "mcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::micro), "μcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::nano), "ncd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::pico), "pcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::femto), "fcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::atto), "acd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::zepto), "zcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::yocto), "ycd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::ronto), "rcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Name::quecto), "qcd");
}

TEST_F(CandelaTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::Q), "Qcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::R), "Rcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::Y), "Ycd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::Z), "Zcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::E), "Ecd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::P), "Pcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::T), "Tcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::G), "Gcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::M), "Mcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::k), "kcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::h), "hcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::da), "dacd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::base), "cd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::d), "dcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::c), "ccd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::m), "mcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::mu), "μcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::n), "ncd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::p), "pcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::f), "fcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::a), "acd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::z), "zcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::y), "ycd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::r), "rcd");
    EXPECT_EQ(candela.toString(DecimalPrefix::Symbol::q), "qcd");
}

TEST_F(CandelaTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(candela.toString(), "cd");
}