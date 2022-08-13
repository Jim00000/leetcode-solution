#pragma once

#include "ISolution.hpp"

namespace leetcode {

class Solution : public ISolution
{
   public:
    virtual std::string countAndSay(int n) override;
};

}  // namespace leetcode