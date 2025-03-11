cmake_minimum_required(VERSION 3.22)
project(SI)

add_library(SI STATIC)
target_sources(SI PRIVATE
    src/decimal_prefix.cpp
)

target_include_directories(SI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

install(TARGETS SI DESTINATION lib)
install(DIRECTORY inc/ DESTINATION include)