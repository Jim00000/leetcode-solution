#pragma once

#include "ListNode.hpp"

// Add two numbers
namespace ATN {

class ISolution {
   public:
    virtual ~ISolution() {}
    virtual ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) = 0;
};

}  // namespace ATN

// See https://leetcode.com/problems/add-two-numbers/ for more information
// Last access time : 12.09.2019