#pragma once

#include "ISolution.hpp"

namespace ATN {

class Solution : public ATN::ISolution
{
   public:
    virtual ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) override;
};

}  // namespace ATN