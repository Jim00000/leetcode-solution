#pragma once

namespace leetcode {

class ISolution
{
   public:
    virtual ~ISolution() {}

    // Calculate n^x where -100.0 < x < 100.0 and n is a 32-bit signed integer
    // within the range [-2^31, 2^31-1]
    virtual double myPow(double x, int n) = 0;
};

}  // namespace leetcode

// See https://leetcode.com/problems/powx-n/ for more information
// Last access time : 12.12.2019