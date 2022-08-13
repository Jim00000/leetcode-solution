#pragma once

#include "ISolution.hpp"

namespace leetcode {

class Solution : public ISolution
{
   public:
    virtual double myPow(double x, int n) override;
};

}  // namespace leetcode