#include "second.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class SecondTest : public ::testing::Test
{
  protected:
    Second second;
};

TEST_F(SecondTest, Constructor)
{
    EXPECT_EQ(second.getName(), "second");
    EXPECT_EQ(second.getPluralName(), "seconds");
    EXPECT_EQ(second.getSymbol(), "s");
    EXPECT_EQ(second.getDescription(),
              "The second, symbol s, is the SI unit of time. "
              "It is defined by taking the fixed numerical value of the caesium"
              "frequency ΔνCs, the unperturbed ground-state hyperfine transition "
              "frequency of the caesium-133 atom, to be 9 192 631 770 when expressed"
              " in the unit Hz, which is equal to s^–1.");
}

TEST_F(SecondTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(second.toString(DecimalPrefix::Name::quetta), "Qs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::ronna), "Rs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::yotta), "Ys");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::zetta), "Zs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::exa), "Es");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::peta), "Ps");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::tera), "Ts");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::giga), "Gs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::mega), "Ms");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::kilo), "ks");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::hecto), "hs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::deca), "das");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::base), "s");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::deci), "ds");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::centi), "cs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::milli), "ms");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::micro), "μs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::nano), "ns");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::pico), "ps");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::femto), "fs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::atto), "as");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::zepto), "zs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::yocto), "ys");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::ronto), "rs");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::quecto), "qs");
}

TEST_F(SecondTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::Q), "Qs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::R), "Rs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::Y), "Ys");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::Z), "Zs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::E), "Es");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::P), "Ps");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::T), "Ts");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::G), "Gs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::M), "Ms");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::k), "ks");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::h), "hs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::da), "das");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::base), "s");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::d), "ds");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::c), "cs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::m), "ms");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::mu), "μs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::n), "ns");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::p), "ps");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::f), "fs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::a), "as");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::z), "zs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::y), "ys");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::r), "rs");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::q), "qs");
}

TEST_F(SecondTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(second.toString(), "s");
}