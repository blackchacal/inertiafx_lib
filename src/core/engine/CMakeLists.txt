cmake_minimum_required(VERSION 3.22)
project(Engine)

add_library(Engine STATIC)
# target_sources(Engine PRIVATE
#     src/Utility.cpp
# )

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

install(TARGETS Engine DESTINATION lib)
install(DIRECTORY inc/ DESTINATION include)