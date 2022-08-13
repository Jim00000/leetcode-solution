add_executable(UnitTest test.cpp)
target_link_libraries(UnitTest ContainerWithMostWater gtest_main)

add_test(NAME RunTest COMMAND UnitTest)