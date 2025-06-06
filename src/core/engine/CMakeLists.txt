cmake_minimum_required(VERSION 3.22)
project(Engine)

add_library(Engine STATIC)
target_sources(Engine PRIVATE
    src/liquid.cpp
    src/water.cpp
    src/point_mass.cpp
    src/empty_space.cpp
    src/engine.cpp
    # src/solid_body.cpp
)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)

target_link_libraries(Engine PRIVATE SI Tools)

add_subdirectory(tests)

target_include_directories(Engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${PARENT_DIR}/tools/inc
    ${PARENT_DIR}/si/inc
)

install(TARGETS Engine DESTINATION lib)
install(DIRECTORY inc/ DESTINATION include)