#include <gtest/gtest.h>
#include <kilogram.h>
#include <metre.h>
#include <second.h>

using namespace InertiaFX::Core::SI;

TEST(PhysicalUnitsTests, GetNameReturnsCorrectName)
{
    Metre metre;
    Second second;
    Kilogram kilogram;
    EXPECT_EQ(metre.getName(), "metre");
    EXPECT_EQ(second.getName(), "second");
    EXPECT_EQ(kilogram.getName(), "kilogram");
}

TEST(PhysicalUnitsTests, GetNamePluralReturnsCorrectName)
{
    Metre metre;
    Second second;
    Kilogram kilogram;
    EXPECT_EQ(metre.getNamePlural(), "metres");
    EXPECT_EQ(second.getNamePlural(), "seconds");
    EXPECT_EQ(kilogram.getNamePlural(), "kilograms");
}

TEST(PhysicalUnitsTests, GetSymbolReturnsCorrectSymbol)
{
    Metre metre;
    Second second;
    Kilogram kilogram;
    EXPECT_EQ(metre.getSymbol(), "m");
    EXPECT_EQ(second.getSymbol(), "s");
    EXPECT_EQ(kilogram.getSymbol(), "kg");
}

TEST(PhysicalUnitsTests, GetDescriptionReturnsCorrectDescription)
{
    Metre metre;
    EXPECT_EQ(metre.getDescription(),
              "The metre, symbol m, is the SI unit of length."
              "It is defined by taking the fixed numerical value of the speed of light"
              " in vacuum c to be 299 792 458 when expressed in the unit m s^(–1), where the "
              "second is defined in terms of the caesium frequency ΔνCs.");

    Second second;
    EXPECT_EQ(second.getDescription(),
              "The second, symbol s, is the SI unit of time. "
              "It is defined by taking the fixed numerical value of the caesium"
              "frequency ΔνCs, the unperturbed ground-state hyperfine transition "
              "frequency of the caesium-133 atom, to be 9 192 631 770 when expressed"
              " in the unit Hz, which is equal to s–1.");

    Kilogram kilogram;
    EXPECT_EQ(kilogram.getDescription(),
              "The kilogram, symbol kg, is the SI unit of mass. "
              "It is defined by taking the fixed numerical value of the"
              " Planck constant h to be 6.626 070 15 x 10–34 when expressed"
              " in the unit J s, which is equal to kg m2 s–1, where the metre"
              " and the second are defined in terms of c and ΔνCs.");
}

TEST(PhysicalUnitsTests, ToStringNoParamsReturnsUnitSymbol)
{
    Metre metre;
    Second second;
    Kilogram kilogram;
    EXPECT_EQ(metre.toString(), "m");
    EXPECT_EQ(second.toString(), "s");
    EXPECT_EQ(kilogram.toString(), "kg");
}

TEST(PhysicalUnitsTests, ToStringPrefixNameReturnsCorrectUnitSymbolWithPrefix)
{
    Metre metre;
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::nano), "nm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::milli), "mm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::kilo), "km");
    EXPECT_EQ(metre.toString(DecimalPrefix::Name::base), "m");

    Second second;
    EXPECT_EQ(second.toString(DecimalPrefix::Name::milli), "ms");
    EXPECT_EQ(second.toString(DecimalPrefix::Name::base), "s");

    Kilogram kilogram;
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::kilo), "ton");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::milli), "g");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::micro), "mg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::nano), "\u03BCg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Name::base), "kg");
}

TEST(PhysicalUnitsTests, ToStringPrefixSymbolReturnsCorrectUnitSymbolWithPrefix)
{
    Metre metre;
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::n), "nm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::m), "mm");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::k), "km");
    EXPECT_EQ(metre.toString(DecimalPrefix::Symbol::base), "m");

    Second second;
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::m), "ms");
    EXPECT_EQ(second.toString(DecimalPrefix::Symbol::base), "s");

    Kilogram kilogram;
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::k), "ton");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::m), "g");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::mu), "mg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::n), "\u03BCg");
    EXPECT_EQ(kilogram.toString(DecimalPrefix::Symbol::base), "kg");
}