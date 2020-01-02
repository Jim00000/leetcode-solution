#include <iostream>
#include <queue>

#include "Solution.hpp"

using namespace leetcode;

static int maxmin(std::vector<int>& v)
{
    std::priority_queue<int> maxheap{v.cbegin(), v.cend()};
    const unsigned int _1st_large_val = maxheap.top();
    maxheap.pop();
    const unsigned int _2st_large_val = maxheap.top();
}

int Solution::maxArea(std::vector<int>& height)
{
    // WIP
    maxmin(height);
    return 0;
}