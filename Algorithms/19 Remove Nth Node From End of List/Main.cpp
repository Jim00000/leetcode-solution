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

#include <vector>

/**
 * @brief solution of Remove Nth Node From End of List
 * 
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> vec;
        
        ListNode* node = head;
        while(node != nullptr) {
            vec.push_back(node);
            node = node->next;
        }
        
        int idx = vec.size() - n;
        if(idx == 0) {
            head = head->next;
        } else {
            vec[idx-1]->next = vec[idx]->next;    
        }
        
        return head;
    }
};