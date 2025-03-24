#include "ampere.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class AmpereTest : public ::testing::Test
{
  protected:
    Ampere ampere;
};

TEST_F(AmpereTest, Constructor)
{
    EXPECT_EQ(ampere.getName(), "ampere");
    EXPECT_EQ(ampere.getPluralName(), "amperes");
    EXPECT_EQ(ampere.getSymbol(), "A");
    EXPECT_EQ(ampere.getDescription(),
              "The ampere, symbol A, is the SI unit of electric current. It is "
              "defined by taking the fixed numerical value of the elementary "
              "charge e to be 1.602 176 634 x 10^–19 when expressed in the unit C, "
              "which is equal to A s, where the second is defined in terms of ΔνCs.");
}

TEST_F(AmpereTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::quetta), "QA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::ronna), "RA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::yotta), "YA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::zetta), "ZA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::exa), "EA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::peta), "PA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::tera), "TA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::giga), "GA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::mega), "MA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::kilo), "kA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::hecto), "hA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::deca), "daA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::base), "A");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::deci), "dA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::centi), "cA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::milli), "mA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::micro), "μA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::nano), "nA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::pico), "pA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::femto), "fA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::atto), "aA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::zepto), "zA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::yocto), "yA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::ronto), "rA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Name::quecto), "qA");
}

TEST_F(AmpereTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::Q), "QA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::R), "RA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::Y), "YA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::Z), "ZA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::E), "EA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::P), "PA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::T), "TA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::G), "GA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::M), "MA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::k), "kA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::h), "hA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::da), "daA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::base), "A");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::d), "dA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::c), "cA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::m), "mA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::mu), "μA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::n), "nA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::p), "pA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::f), "fA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::a), "aA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::z), "zA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::y), "yA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::r), "rA");
    EXPECT_EQ(ampere.toString(DecimalPrefix::Symbol::q), "qA");
}

TEST_F(AmpereTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(ampere.toString(), "A");
}