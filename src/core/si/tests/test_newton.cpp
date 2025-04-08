#include "newton.h"
#include <gtest/gtest.h>
#include <string>

using namespace InertiaFX::Core::SI;

class NewtonTest : public ::testing::Test
{
  protected:
    // Create a Newton instance for testing
    Newton newton;
};

TEST_F(NewtonTest, Constructor)
{
    EXPECT_EQ(newton.getName(), "newton");
    EXPECT_EQ(newton.getPluralName(), "newtons");
    EXPECT_EQ(newton.getSymbol(), "N");
    EXPECT_EQ(
        newton.getDescription(),
        "The newton, symbol N, is the SI unit of force."
        "It is expressed in term of base units as kg m s^–2."
        "It is defined as the force required to accelerate a mass of one kilogram at a rate of "
        "one metre per second squared.");
}

TEST_F(NewtonTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names (subset matching those in your DecimalPrefix implementation)
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::quetta), "QN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::ronna), "RN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::yotta), "YN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::zetta), "ZN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::exa), "EN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::peta), "PN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::tera), "TN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::giga), "GN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::mega), "MN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::kilo), "kN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::hecto), "hN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::deca), "daN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::base), "N");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::deci), "dN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::centi), "cN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::milli), "mN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::micro), "μN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::nano), "nN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::pico), "pN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::femto), "fN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::atto), "aN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::zepto), "zN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::yocto), "yN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::ronto), "rN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Name::quecto), "qN");
}

TEST_F(NewtonTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols (using same prefixes as above)
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::Q), "QN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::R), "RN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::Y), "YN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::Z), "ZN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::E), "EN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::P), "PN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::T), "TN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::G), "GN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::M), "MN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::k), "kN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::h), "hN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::da), "daN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::base), "N");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::d), "dN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::c), "cN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::m), "mN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::mu), "μN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::n), "nN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::p), "pN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::f), "fN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::a), "aN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::z), "zN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::y), "yN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::r), "rN");
    EXPECT_EQ(newton.toString(DecimalPrefix::Symbol::q), "qN");
}

TEST_F(NewtonTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(newton.toString(), "N");
}