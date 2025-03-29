cmake_minimum_required(VERSION 3.22)
project(Tools_UnitTests)

add_executable(Tools_UnitTests
    # Test general classes
    test_logger.cpp
    test_file_logger.cpp
)

target_link_libraries(Tools_UnitTests PRIVATE
    gtest gtest_main
    Core
)

add_test(NAME Tools_UnitTests COMMAND Tools_UnitTests)