set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_library(Powxn Solution.cpp Simulator.cpp f2xm1.cpp)
add_executable(app main.cpp)
target_link_libraries(app Powxn)
