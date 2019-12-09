add_executable(UnitTest test.cpp)
target_link_libraries(UnitTest ATN gtest_main)

add_test(NAME RunTest COMMAND UnitTest)