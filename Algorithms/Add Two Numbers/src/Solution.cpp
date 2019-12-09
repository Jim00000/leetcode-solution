#include "Solution.hpp"

using namespace ATN;

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    unsigned int carry = 0, sum;
    ListNode *sumnode = new ListNode(0);
    ListNode *sumhead = sumnode;

    while (true) {
        unsigned int v1 = l1 != nullptr ? l1->val : 0;
        unsigned int v2 = l2 != nullptr ? l2->val : 0;
        sum = v1 + v2 + carry;

        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        sumnode->val = sum;
        l1 = l1 != nullptr ? l1->next : nullptr;
        l2 = l2 != nullptr ? l2->next : nullptr;

        if (((unsigned long)l1 | (unsigned long)l2) == 0) break;

        sumnode->next = new ListNode(0);
        sumnode = sumnode->next;
    }

    if (carry == 1) {
        sumnode->next = new ListNode(0);
        sumnode = sumnode->next;
        sumnode->val = 1;
    }

    return sumhead;
}