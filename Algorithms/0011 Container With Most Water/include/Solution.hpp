#pragma once

#include "ISolution.hpp"

namespace leetcode {

class Solution : public ISolution
{
   public:
    int maxArea(std::vector<int> &height) override;
};

}  // namespace leetcode