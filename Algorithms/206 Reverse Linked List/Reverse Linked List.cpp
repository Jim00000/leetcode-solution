/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * @brief Reverse Linked List
 * 
 * Time Complexity : O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* rev_head = nullptr;
        while(head != nullptr) {
            ListNode* headnext = head->next;
            head->next = rev_head;
            rev_head = head;
            head = headnext;
        }
        return rev_head;
    }
};