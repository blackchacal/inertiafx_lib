cmake_minimum_required(VERSION 3.22)
project(Tools)

add_library(Tools STATIC)
target_sources(Tools PRIVATE
    src/logger.cpp
    src/file_logger.cpp
)

add_subdirectory(tests)

target_include_directories(Tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

install(TARGETS Tools DESTINATION lib)
install(DIRECTORY inc/ DESTINATION include)