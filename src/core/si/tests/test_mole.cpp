#include "mole.h"
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

class MoleTest : public ::testing::Test
{
  protected:
    Mole mole;
};

TEST_F(MoleTest, Constructor)
{
    EXPECT_EQ(mole.getName(), "mole");
    EXPECT_EQ(mole.getPluralName(), "moles");
    EXPECT_EQ(mole.getSymbol(), "mol");
    EXPECT_EQ(mole.getDescription(),
              "The mole, symbol mol, is the SI unit of amount of substance. "
              "One mole contains exactly 6.022 140 76 x 1023 elementary "
              "entities. This number is the fixed numerical value of the "
              "Avogadro constant, NA, when expressed in the unit mol^–1 and "
              "is called the Avogadro number."
              "The amount of substance, symbol n, of a system is a measure "
              "of the number of specified elementary entities. An elementary "
              "entity may be an atom, a molecule, an ion, an electron, any "
              "other particle or specified group of particles.");
}

TEST_F(MoleTest, ToStringWithDecimalPrefixName)
{
    // Test all decimal prefix names
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::quetta), "Qmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::ronna), "Rmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::yotta), "Ymol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::zetta), "Zmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::exa), "Emol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::peta), "Pmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::tera), "Tmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::giga), "Gmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::mega), "Mmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::kilo), "kmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::hecto), "hmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::deca), "damol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::base), "mol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::deci), "dmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::centi), "cmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::milli), "mmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::micro), "μmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::nano), "nmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::pico), "pmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::femto), "fmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::atto), "amol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::zepto), "zmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::yocto), "ymol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::ronto), "rmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Name::quecto), "qmol");
}

TEST_F(MoleTest, ToStringWithDecimalPrefixSymbol)
{
    // Test all decimal prefix symbols
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::Q), "Qmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::R), "Rmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::Y), "Ymol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::Z), "Zmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::E), "Emol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::P), "Pmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::T), "Tmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::G), "Gmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::M), "Mmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::k), "kmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::h), "hmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::da), "damol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::base), "mol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::d), "dmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::c), "cmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::m), "mmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::mu), "μmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::n), "nmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::p), "pmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::f), "fmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::a), "amol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::z), "zmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::y), "ymol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::r), "rmol");
    EXPECT_EQ(mole.toString(DecimalPrefix::Symbol::q), "qmol");
}

TEST_F(MoleTest, ToStringWithoutPrefix)
{
    EXPECT_EQ(mole.toString(), "mol");
}