cmake_minimum_required(VERSION 3.10)

# Project
project(Container_With_Most_Water VERSION 1.0 LANGUAGES CXX)

# Include CMake Modules
include(${CMAKE_HOME_DIRECTORY}/../../CMake/BuildType.cmake)

# Specify Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_custom_target(Count_And_Say DEPENDS googletest)

add_subdirectory(${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest/googletest
        ${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest/build
        EXCLUDE_FROM_ALL)

enable_testing()

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)