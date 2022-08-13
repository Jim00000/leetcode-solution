add_executable(UnitTest test.cpp)
target_link_libraries(UnitTest Powxn gtest_main)

add_test(NAME RunTest COMMAND UnitTest)