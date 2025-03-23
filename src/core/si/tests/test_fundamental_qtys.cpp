#include <fundamental_qty.h>
#include <gtest/gtest.h>
#include <kilogram.h>
#include <length.h>
#include <mass.h>
#include <metre.h>
#include <second.h>
#include <si_time.h>

using namespace InertiaFX::Core::SI;

TEST(FundamentalQtyTests, GetNameReturnsCorrectName)
{
    Length L(2.0);  // 2 m
    Time t(1);      // 1 s
    Mass m(1);      // 1 kg
    EXPECT_EQ(L.getName(), "Length");
    EXPECT_EQ(t.getName(), "Time");
    EXPECT_EQ(m.getName(), "Mass");
}

TEST(FundamentalQtyTests, GetSymbolReturnsCorrectSymbol)
{
    Length L(2.0);  // 2 m
    Time t(1);      // 1 s
    Mass m(1);      // 1 kg
    EXPECT_EQ(L.getSymbol(), "l");
    EXPECT_EQ(t.getSymbol(), "t");
    EXPECT_EQ(m.getSymbol(), "m");
}

TEST(FundamentalQtyTests, GetDescriptionReturnsCorrectText)
{
    Length L(2.0);  // 2 m
    Time t(1);      // 1 s
    Mass m(1);      // 1 kg
    EXPECT_EQ(L.getDescription(), "Represents the fundamental SI Length quantity.");
    EXPECT_EQ(t.getDescription(), "Represents the fundamental SI Time quantity.");
    EXPECT_EQ(m.getDescription(), "Represents the fundamental SI Mass quantity.");
}

TEST(FundamentalQtyTests, GetUnitNameReturnsCorrectName)
{
    Metre metre;
    Second s;
    Kilogram k;
    Length L(2.0);  // 2 m
    Time t(1);      // 1 s
    Mass m(1);      // 1 kg
    EXPECT_EQ(L.getUnitName(), metre.getName());
    EXPECT_EQ(t.getUnitName(), s.getName());
    EXPECT_EQ(m.getUnitName(), k.getName());
}

TEST(FundamentalQtyTests, GetUnitSymbolReturnsCorrectSymbol)
{
    Metre metre;
    Second s;
    Kilogram k;
    Length L(2.0);  // 2 m
    Time t(1);      // 1 s
    Mass m(1);      // 1 kg
    EXPECT_EQ(L.getUnitSymbol(), metre.getSymbol());
    EXPECT_EQ(t.getUnitSymbol(), s.getSymbol());
    EXPECT_EQ(m.getUnitSymbol(), k.getSymbol());
}

TEST(FundamentalQtyTests, GetUnitDescriptionReturnsCorrectText)
{
    Metre metre;
    Second s;
    Kilogram k;
    Length L(2.0);  // 2 m
    Time t(1);      // 1 s
    Mass m(1);      // 1 kg
    EXPECT_EQ(L.getUnitDescription(), metre.getDescription());
    EXPECT_EQ(t.getUnitDescription(), s.getDescription());
    EXPECT_EQ(m.getUnitDescription(), k.getDescription());
}

TEST(FundamentalQtyTests, GetValueReturnsCorrectBaseValue)
{
    Length L1(2.0);                              // 2 m
    Length L2(3.0, DecimalPrefix::Name::milli);  // 3 mm
    Length L3(5, DecimalPrefix::Name::kilo);     // 5 km
    EXPECT_DOUBLE_EQ(L1.getValue(), 2.0);
    EXPECT_DOUBLE_EQ(L2.getValue(), 0.003);
    EXPECT_DOUBLE_EQ(L3.getValue(), 5000);

    Time t1(1);                              // 1 s
    Time t2(6, DecimalPrefix::Name::centi);  // 6 cs
    Time t3(9, DecimalPrefix::Name::nano);   // 9 ns
    EXPECT_DOUBLE_EQ(t1.getValue(), 1.0);
    EXPECT_DOUBLE_EQ(t2.getValue(), 0.06);
    EXPECT_DOUBLE_EQ(t3.getValue(), 9e-9);

    Mass m1(1);                              // 1 kg
    Mass m2(6, DecimalPrefix::Name::milli);  // 6 g
    Mass m3(9, DecimalPrefix::Name::micro);  // 9 mg
    EXPECT_DOUBLE_EQ(m1.getValue(), 1.0);
    EXPECT_DOUBLE_EQ(m2.getValue(), 0.006);
    EXPECT_DOUBLE_EQ(m3.getValue(), 9e-6);
}

TEST(FundamentalQtyTests, GetValueInReturnsCorrectPrefixedValue)
{
    Length L1(2.0);  // 2 m
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::kilo), 0.002);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Symbol::k), 0.002);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::milli), 2000);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::micro), 2000000);

    Time t1(2.0);  // 2 s
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::kilo), 0.002);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Symbol::k), 0.002);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::milli), 2000);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::micro), 2000000);

    Mass m1(2.0);  // 2 kg
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::kilo), 0.002);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Symbol::k), 0.002);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::milli), 2000);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::micro), 2000000);
}

TEST(FundamentalQtyTests, SetValueUpdatesToCorrectBaseValue)
{
    Length L1(2.0);  // 2 m
    L1.setValue(5);  // 5 m
    EXPECT_DOUBLE_EQ(L1.getValue(), 5);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::kilo), 0.005);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Symbol::k), 0.005);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::milli), 5000);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::micro), 5000000);

    Time t1(2.0);    // 2 s
    t1.setValue(5);  // 5 s
    EXPECT_DOUBLE_EQ(t1.getValue(), 5);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::kilo), 0.005);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Symbol::k), 0.005);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::milli), 5000);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::micro), 5000000);

    Mass m1(2.0);    // 2 kg
    m1.setValue(5);  // 5 kg
    EXPECT_DOUBLE_EQ(m1.getValue(), 5);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::kilo), 0.005);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Symbol::k), 0.005);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::milli), 5000);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::micro), 5000000);
}

TEST(FundamentalQtyTests, SetValueFromUpdatesToCorrectPrefixedValue)
{
    Length L1(2.0);                                 // 2 m
    L1.setValueFrom(8, DecimalPrefix::Name::kilo);  // 8 km
    EXPECT_DOUBLE_EQ(L1.getValue(), 8000);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::kilo), 8);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Symbol::k), 8);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::milli), 8000000);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::micro), 8000000000);

    L1.setValueFrom(22.4, DecimalPrefix::Symbol::n);  // 22.4 nm
    EXPECT_DOUBLE_EQ(L1.getValue(), 22.4e-9);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::kilo), 22.4e-12);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Symbol::k), 22.4e-12);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::milli), 0.0000224);
    EXPECT_DOUBLE_EQ(L1.getValueIn(DecimalPrefix::Name::micro), 0.0224);

    Time t1(2.0);                                   // 2 s
    t1.setValueFrom(8, DecimalPrefix::Name::kilo);  // 8 ks
    EXPECT_DOUBLE_EQ(t1.getValue(), 8000);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::kilo), 8);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Symbol::k), 8);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::milli), 8000000);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::micro), 8000000000);

    t1.setValueFrom(22.4, DecimalPrefix::Symbol::n);  // 22.4 ns
    EXPECT_DOUBLE_EQ(t1.getValue(), 22.4e-9);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::kilo), 22.4e-12);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Symbol::k), 22.4e-12);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::milli), 0.0000224);
    EXPECT_DOUBLE_EQ(t1.getValueIn(DecimalPrefix::Name::micro), 0.0224);

    Mass m1(2.0);                                   // 2 kg
    m1.setValueFrom(8, DecimalPrefix::Name::kilo);  // 8 ton
    EXPECT_DOUBLE_EQ(m1.getValue(), 8000);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::kilo), 8);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Symbol::k), 8);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::milli), 8000000);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::micro), 8000000000);

    m1.setValueFrom(22.4, DecimalPrefix::Symbol::n);  // 22.4 ns
    EXPECT_DOUBLE_EQ(m1.getValue(), 22.4e-9);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::kilo), 22.4e-12);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Symbol::k), 22.4e-12);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::milli), 0.0000224);
    EXPECT_DOUBLE_EQ(m1.getValueIn(DecimalPrefix::Name::micro), 0.0224);
}