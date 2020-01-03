#include <iostream>
#include <queue>

#include "Solution.hpp"

using namespace leetcode;

const int maxMin2(std::vector<int>& v)
{
    std::priority_queue<int> maxHeap{v.cbegin(), v.cend()};
    maxHeap.pop();
    return maxHeap.top();
}

int Solution::maxArea(std::vector<int>& height)
{
    const int n = height.size();
    if (n < 2) throw std::invalid_argument("size of height < 2");
    const int _2stMax = maxMin2(height);
    int maxAreaVal = 0;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - i; j++) {
            const int min = std::min(height.at(i + j), height.at(j));
            const int newArea = min * i;
            maxAreaVal = std::max(maxAreaVal, newArea);
            if (min == _2stMax) goto exit_loop;
        }
    }
exit_loop:;
    return maxAreaVal;
}