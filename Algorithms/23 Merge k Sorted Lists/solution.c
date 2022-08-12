#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

struct MyTreeNode
{
    struct MyTreeNode *left, *right;
    struct ListNode *node;
};

struct MyTreeNode* TreeNodeCreate(struct ListNode *node)
{
    struct MyTreeNode* treenode = malloc(sizeof(struct MyTreeNode));
    treenode->left = NULL;
    treenode->right = NULL;
    treenode->node = node;
    return treenode;
}

void BinarySearchTreeAppend(struct MyTreeNode** root, struct ListNode* node)
{
    if(root != NULL)
    {
        struct MyTreeNode* _root = *root;
        if(_root == NULL)
        {
            _root = TreeNodeCreate(node);
            *root = _root;
        }
        else
        {
            while(_root != NULL)
            {
                if(_root->node->val >= node->val)
                {
                    if(_root->left != NULL)
                        _root = _root->left;
                    else
                    {
                        _root->left = TreeNodeCreate(node);
                        break;
                    }
                }
                else
                {
                    if(_root->right != NULL)
                        _root = _root->right;
                    else
                    {
                        _root->right = TreeNodeCreate(node);
                        break;
                    }
                }
            }
        }
    }
}

void traverseInorder(struct MyTreeNode* root, struct ListNode **head, struct ListNode **tail)
{
    if(root != NULL)
    {
        traverseInorder(root->left, head, tail);
        if(*head == NULL)
        {
            *head = root->node;
            *tail = root->node;
        }
        else
        {
            (*tail)->next = root->node;
            *tail = root->node;
        }
        traverseInorder(root->right, head, tail);
        free(root);
    }
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (lists != NULL && listsSize > 0)
    {
        struct MyTreeNode* bst_root = NULL;
        for(int i = 0; i < listsSize; i++)
        {
            struct ListNode* node = lists[i];
            while(node != NULL)
            {
                BinarySearchTreeAppend(&bst_root, node);
                node = node->next;
            }
        }

        // Inorder traversal
        struct ListNode *head = NULL, *tail = NULL;
        traverseInorder(bst_root, &head, &tail);
        if(tail != NULL)
            tail->next = NULL; // avoid tail node point to internal node of the linkedlist itself
        return head;
    }
    return NULL;
}