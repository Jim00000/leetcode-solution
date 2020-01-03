#include <iostream>
#include "Solution.hpp"

static bool maxArea(std::vector<int>&& v, const int expected)
{
    leetcode::Solution solver;
    const int result = solver.maxArea(v);
    std::cout << "Output : " << result << " Expected : " << expected
              << std::endl;
    return result == expected;
}

int main()
{
    std::cout << "11. Count and Say - LeetCode" << std::endl;
    maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    maxArea({1, 1}, 1);
    return 0;
}