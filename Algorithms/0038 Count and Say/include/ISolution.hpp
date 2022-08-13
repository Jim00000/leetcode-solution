#pragma once

#include <string>

namespace leetcode {

class ISolution
{
   public:
    virtual ~ISolution() {}

    // 1 <= n <= 30
    virtual std::string countAndSay(int n) = 0;
};

}  // namespace leetcode

// See https://leetcode.com/problems/count-and-say/ for more information
// Last access time : 12.31.2019