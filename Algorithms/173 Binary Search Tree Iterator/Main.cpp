#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode* root) : _root(root) {
        TreeNode* head = root;
         _stack.push(head);
        while(head->left != nullptr) {
            head = head->left;
            _stack.push(head);
        }
    }
    
    int next() {
        TreeNode* node = _stack.top();
        _stack.pop();
        const int val = node->val;
        if(node->right != nullptr) {
            node = node->right;
            _stack.push(node);
            while(node->left != nullptr) {
                node = node->left;
                _stack.push(node);
            }
        }
        return val;
    }
    
    bool hasNext() {
        return not _stack.empty();
    }
private:
    std::stack<TreeNode*> _stack;
    TreeNode* _root;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */