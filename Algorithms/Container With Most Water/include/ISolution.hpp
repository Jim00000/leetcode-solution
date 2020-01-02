#pragma once

#include <vector>

namespace leetcode {
class ISolution
{
   public:
    virtual ~ISolution() = default;

    virtual int maxArea(std::vector<int>& height) = 0;
};
}  // namespace leetcode