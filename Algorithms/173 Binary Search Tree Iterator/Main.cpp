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
    BSTIterator(TreeNode* root) noexcept {
         _stack.push(root);
        while(root->left != nullptr) {
            root = root->left;
            _stack.push(root);
        }
    }
    
    int next() noexcept {
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
    
    bool hasNext() noexcept {
        return not _stack.empty();
    }
private:
    std::stack<TreeNode*> _stack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */