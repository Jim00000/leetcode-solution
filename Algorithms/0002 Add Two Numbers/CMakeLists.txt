cmake_minimum_required(VERSION 3.10)

# Project
project("Add two numbers" VERSION 1.0 LANGUAGES CXX)

# Include CMake Modules
include(${CMAKE_HOME_DIRECTORY}/../../CMake/BuildType.cmake)

# Specify Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    ${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest
  GIT_TAG           release-1.10.0
  SOURCE_DIR        ${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest/googletest
  BINARY_DIR        ${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest/build
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

add_subdirectory(${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest/googletest
                 ${CMAKE_HOME_DIRECTORY}/../../Third_Party/googletest/build
                 EXCLUDE_FROM_ALL)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(include)

add_subdirectory(src)
add_subdirectory(test)