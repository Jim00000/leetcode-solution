/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * @brief solution of Delete Node in a Linked List
 * 
 * Time complexity: O(N)
 * Space complexity: O(1)
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while(node->next != nullptr) {
            node->val = node->next->val;
            prev = node;
            node = node->next;    
        }
        
        prev->next = nullptr;
    }
};