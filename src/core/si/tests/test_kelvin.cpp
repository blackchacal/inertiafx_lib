#include "kelvin.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class KelvinTest : public ::testing::Test
{
  protected:
    Kelvin kelvin;
};

TEST_F(KelvinTest, Constructor)
{
    EXPECT_EQ(kelvin.getName(), "kelvin");
    EXPECT_EQ(kelvin.getPluralName(), "kelvins");
    EXPECT_EQ(kelvin.getSymbol(), "K");
    EXPECT_EQ(kelvin.getDescription(), "The kelvin, symbol K, is the SI unit of thermodynamic "
                                       "temperature. It is defined by taking the fixed numerical "
                                       "value of the Boltzmann constant k to be 1.380 649 x 10^–23 "
                                       "when expressed in the unit J K^–1, which is equal to kg "
                                       "m^2 s^–2 K^–1, where the kilogram, metre and second are "
                                       "defined in terms of h, c and ΔνCs.");
}

TEST_F(KelvinTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::quetta), "QK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::ronna), "RK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::yotta), "YK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::zetta), "ZK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::exa), "EK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::peta), "PK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::tera), "TK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::giga), "GK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::mega), "MK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::kilo), "kK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::hecto), "hK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::deca), "daK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::base), "K");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::deci), "dK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::centi), "cK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::milli), "mK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::micro), "μK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::nano), "nK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::pico), "pK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::femto), "fK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::atto), "aK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::zepto), "zK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::yocto), "yK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::ronto), "rK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Name::quecto), "qK");
}

TEST_F(KelvinTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::Q), "QK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::R), "RK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::Y), "YK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::Z), "ZK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::E), "EK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::P), "PK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::T), "TK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::G), "GK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::M), "MK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::k), "kK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::h), "hK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::da), "daK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::base), "K");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::d), "dK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::c), "cK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::m), "mK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::mu), "μK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::n), "nK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::p), "pK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::f), "fK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::a), "aK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::z), "zK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::y), "yK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::r), "rK");
    EXPECT_EQ(kelvin.toString(DecimalPrefix::Symbol::q), "qK");
}

TEST_F(KelvinTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(kelvin.toString(), "K");
}