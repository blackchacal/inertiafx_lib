#include "pascal.h"
#include <gtest/gtest.h>
#include <memory>

using namespace InertiaFX::Core::SI;

class PascalTest : public ::testing::Test
{
  protected:
    Pascal pascal;
};

TEST_F(PascalTest, Constructor)
{
    EXPECT_EQ(pascal.getName(), "pascal");
    EXPECT_EQ(pascal.getPluralName(), "pascals");
    EXPECT_EQ(pascal.getSymbol(), "Pa");
    EXPECT_FALSE(pascal.getDescription().empty());
}

TEST_F(PascalTest, Clone)
{
    std::unique_ptr<IPhysicalUnit> clone = pascal.clone();
    EXPECT_EQ(clone->getName(), pascal.getName());
    EXPECT_EQ(clone->getPluralName(), pascal.getPluralName());
    EXPECT_EQ(clone->getSymbol(), pascal.getSymbol());
    EXPECT_EQ(clone->getDescription(), pascal.getDescription());
}

TEST_F(PascalTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::quetta), "QPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::ronna), "RPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::yotta), "YPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::zetta), "ZPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::exa), "EPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::peta), "PPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::tera), "TPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::giga), "GPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::mega), "MPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::kilo), "kPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::hecto), "hPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::deca), "daPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::base), "Pa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::deci), "dPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::centi), "cPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::milli), "mPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::micro), "μPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::nano), "nPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::pico), "pPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::femto), "fPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::atto), "aPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::zepto), "zPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::yocto), "yPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::ronto), "rPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Name::quecto), "qPa");
}

TEST_F(PascalTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::Q), "QPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::R), "RPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::Y), "YPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::Z), "ZPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::E), "EPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::P), "PPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::T), "TPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::G), "GPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::M), "MPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::k), "kPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::h), "hPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::da), "daPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::base), "Pa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::d), "dPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::c), "cPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::m), "mPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::mu), "μPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::n), "nPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::p), "pPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::f), "fPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::a), "aPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::z), "zPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::y), "yPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::r), "rPa");
    EXPECT_EQ(pascal.toString(DecimalPrefix::Symbol::q), "qPa");
}
