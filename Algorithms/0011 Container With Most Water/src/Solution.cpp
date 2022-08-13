#include <iostream>
#include <queue>

#include "Solution.hpp"

using namespace leetcode;

int Solution::maxArea(std::vector<int>& height)
{
    const int n = height.size();
    if (n < 2) throw std::invalid_argument("size of height < 2");
    int maxAreaVal = (n - 1) * std::min(height.at(n - 1), height.at(0));
    int i = 0, j = n - 1;
    while (i < j) {
        maxAreaVal =
            std::max(maxAreaVal, (j - i) * std::min(height.at(i), height.at(j)));
        if (height.at(i) < height.at(j)) {
            i++;
        } else {
            j--;
        }
    }

    return maxAreaVal;
}