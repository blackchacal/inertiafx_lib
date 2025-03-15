#include <decimal_prefix.h>
#include <gtest/gtest.h>

using namespace InertiaFX::Core::SI;

TEST(DecimalPrefixTests, GetCorrectPrefixNameFromSymbol)
{
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::Q), "quetta");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::R), "ronna");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::Y), "yotta");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::Z), "zetta");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::E), "exa");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::P), "peta");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::T), "tera");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::G), "giga");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::M), "mega");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::k), "kilo");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::h), "hecto");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::da), "deca");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::none), "");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::d), "deci");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::c), "centi");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::m), "milli");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::mu), "micro");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::n), "nano");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::p), "pico");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::f), "femto");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::a), "atto");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::z), "zepto");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::y), "yocto");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::r), "ronto");
    EXPECT_EQ(DecimalPrefix::getName(DecimalPrefix::Symbol::q), "quecto");
}

TEST(DecimalPrefixTests, GetCorrectPrefixSymbolFromName)
{
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::quetta), "Q");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::ronna), "R");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::yotta), "Y");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::zetta), "Z");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::exa), "E");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::peta), "P");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::tera), "T");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::giga), "G");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::mega), "M");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::kilo), "k");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::hecto), "h");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::deca), "da");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::none), "");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::deci), "d");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::centi), "c");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::milli), "m");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::micro), "\u03BC");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::nano), "n");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::pico), "p");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::femto), "f");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::atto), "a");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::zepto), "z");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::yocto), "y");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::ronto), "r");
    EXPECT_EQ(DecimalPrefix::getSymbol(DecimalPrefix::Name::quecto), "q");
}

TEST(DecimalPrefixTests, GetCorrectMultiplierFromPrefixName)
{
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::quetta), 1e30);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::ronna), 1e27);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::yotta), 1e24);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::zetta), 1e21);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::exa), 1e18);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::peta), 1e15);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::tera), 1e12);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::giga), 1e9);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::mega), 1e6);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::kilo), 1e3);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::hecto), 1e2);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::deca), 1e1);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::none), 1);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::deci), 1e-1);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::centi), 1e-2);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::milli), 1e-3);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::micro), 1e-6);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::nano), 1e-9);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::pico), 1e-12);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::femto), 1e-15);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::atto), 1e-18);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::zepto), 1e-21);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::yocto), 1e-24);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::ronto), 1e-27);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Name::quecto), 1e-30);
}

TEST(DecimalPrefixTests, GetCorrectMultiplierFromPrefixSymbol)
{
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::Q), 1e30);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::R), 1e27);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::Y), 1e24);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::Z), 1e21);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::E), 1e18);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::P), 1e15);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::T), 1e12);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::G), 1e9);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::M), 1e6);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::k), 1e3);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::h), 1e2);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::da), 1e1);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::none), 1);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::d), 1e-1);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::c), 1e-2);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::m), 1e-3);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::mu), 1e-6);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::n), 1e-9);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::p), 1e-12);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::f), 1e-15);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::a), 1e-18);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::z), 1e-21);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::y), 1e-24);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::r), 1e-27);
    EXPECT_DOUBLE_EQ(DecimalPrefix::getMultiplier(DecimalPrefix::Symbol::q), 1e-30);
}