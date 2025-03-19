cmake_minimum_required(VERSION 3.22)
project(SI_Tests)

add_executable(SI_Tests
    test_decimal_prefix.cpp
    test_physical_units.cpp
)

target_link_libraries(SI_Tests PRIVATE
    gtest gtest_main
    Core
)

add_test(NAME SI_Tests COMMAND SI_Tests)