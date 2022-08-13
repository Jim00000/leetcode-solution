#include <gtest/gtest.h>
#include "Solution.hpp"

using namespace std::string_literals;

std::string solve(const int n)
{
    leetcode::Solution solver;
    return solver.countAndSay(n);
}

TEST(test_count_and_say, testsuit01) { EXPECT_STREQ(solve(1).c_str(), "1"); }

TEST(test_count_and_say, testsuit02) { EXPECT_STREQ(solve(2).c_str(), "11"); }

TEST(test_count_and_say, testsuit03) { EXPECT_STREQ(solve(3).c_str(), "21"); }

TEST(test_count_and_say, testsuit04) { EXPECT_STREQ(solve(4).c_str(), "1211"); }

TEST(test_count_and_say, testsuit05)
{
    EXPECT_STREQ(solve(5).c_str(), "111221");
}

TEST(test_count_and_say, testsuit06)
{
    EXPECT_STREQ(solve(6).c_str(), "312211");
}

TEST(test_count_and_say, testsuit07)
{
    EXPECT_STREQ(solve(7).c_str(), "13112221");
}

TEST(test_count_and_say, testsuit08)
{
    EXPECT_STREQ(solve(8).c_str(), "1113213211");
}

TEST(test_count_and_say, testsuit09)
{
    EXPECT_STREQ(solve(9).c_str(), "31131211131221");
}

TEST(test_count_and_say, testsuit10)
{
    EXPECT_STREQ(solve(10).c_str(), "13211311123113112211");
}