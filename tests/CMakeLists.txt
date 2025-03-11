cmake_minimum_required(VERSION 3.22)
project(InertiaFXTests)

include(FetchContent)

# Fetch GoogleTest if not installed
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add subdirectories for each module's tests
add_subdirectory(core)
add_subdirectory(newtonian_mechanics)

# Register test executables
add_test(NAME InertiaFXTests COMMAND InertiaFXTests)

