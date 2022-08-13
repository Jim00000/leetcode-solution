#include <gtest/gtest.h>
#include "Simulator.hpp"

TEST(test_add_two_numbers, testsuit1)
{
    Simulator simulator;
    const uint32_t result = simulator.simulate({2, 4, 3}, {5, 6, 4}).value();
    EXPECT_EQ(result, 807);
}

TEST(test_add_two_numbers, testsuit2)
{
    Simulator simulator;
    const uint32_t result = simulator.simulate({2, 4, 3}, {8, 5}).value();
    EXPECT_EQ(result, 400);
}

TEST(test_add_two_numbers, testsuit3)
{
    Simulator simulator;
    const uint32_t result = simulator.simulate({5}, {5}).value();
    EXPECT_EQ(result, 10);
}

TEST(test_add_two_numbers, testsuit4)
{
    Simulator simulator;
    const uint32_t result = simulator.simulate({1}, {9, 9}).value();
    EXPECT_EQ(result, 100);
}