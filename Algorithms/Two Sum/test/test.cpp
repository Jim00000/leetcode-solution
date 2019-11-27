#include "Simulator.hpp"
#include <gtest/gtest.h>

TEST(test_two_sum, testsuit1) {
  const bool Output = Simulate({2, 7, 11, 15}, 9, {0, 1});
  EXPECT_TRUE(Output);
}

TEST(test_two_sum, testsuit2) {
  const bool Output = Simulate({2, 7, 11, 15}, 18, {1, 2});
  EXPECT_TRUE(Output);
}

TEST(test_two_sum, testsuit3) {
  const bool Output = Simulate({3, 3}, 6, {0, 1});
  EXPECT_TRUE(Output);
}

TEST(test_two_sum, testsuit4) {
  const bool Output = Simulate({3, 2, 3}, 6, {0, 2});
  EXPECT_TRUE(Output);
}