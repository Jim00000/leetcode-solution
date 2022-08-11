#include "solution.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode *TreeNodeCreate(int key, int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->entry.key = key;
    node->entry.value = value;
    return node;
}

int BinarySearchTreeAppendOrReplace(struct BinaryTreeHeader *header, int key, int value)
{
    if (header->root == NULL)
    {
        header->root = TreeNodeCreate(key, value);
        header->size++;
        return 1; // new node is inserted
    }
    else
    {
        struct TreeNode *current = header->root;
        while (true)
        {
            if (current->entry.key > key)
            {
                if (current->left != NULL)
                {
                    current = current->left;
                }
                else
                {
                    current->left = TreeNodeCreate(key, value);
                    header->size++;
                    return 1; // new node is inserted
                }
            }
            else if (current->entry.key < key)
            {
                if (current->right != NULL)
                {
                    current = current->right;
                }
                else
                {
                    current->right = TreeNodeCreate(key, value);
                    header->size++;
                    return 1; // new node is inserted
                }
            }
            else
            {
                // replacement
                current->entry.value = value;
                return 2; // replacement
            }
        }
    }

    return 0; // there is no new node inserted
}

void BinarySearchTreeAppendNode(struct BinaryTreeHeader *header, struct TreeNode *node)
{
    if (header->root == NULL)
    {
        header->root = node;
        header->size++;
    }
    else
    {
        struct TreeNode *current = header->root;
        while (true)
        {
            if (current->entry.key > node->entry.key)
            {
                if (current->left != NULL)
                {
                    current = current->left;
                }
                else
                {
                    current->left = node;
                    header->size++;
                    break;
                }
            }
            else if (current->entry.key < node->entry.key)
            {
                if (current->right != NULL)
                {
                    current = current->right;
                }
                else
                {
                    current->right = node;
                    header->size++;
                    break;
                }
            }
            else
            {
                // replacement
                break;
            }
        }
    }
}

HashMapEntry *BinarySearchTreeSearch(struct BinaryTreeHeader *header, int key)
{
    if (header != NULL && header->root != NULL)
    {
        struct TreeNode *current = header->root;
        while (current != NULL)
        {
            if (current->entry.key > key)
            {
                current = current->left;
            }
            else if (current->entry.key < key)
            {
                current = current->right;
            }
            else
            {
                return &current->entry;
            }
        }
    }

    return NULL;
}

void BinarySearchTreeRemove(struct BinaryTreeHeader *header, int key)
{
    if (header != NULL && header->root != NULL)
    {
        struct TreeNode *current = header->root;
        while (current != NULL)
        {
            if (current->entry.key > key)
            {
                current = current->left;
            }
            else if (current->entry.key < key)
            {
                current = current->right;
            }
            else
            {
                current->entry.value = -1;
                break;
            }
        }
    }
}

void BinarySearchTreeFreeAll(struct TreeNode *node)
{
    if(node != NULL)
    {
        BinarySearchTreeFreeAll(node->left);
        BinarySearchTreeFreeAll(node->right);
        free(node);
    }
}

struct BinaryTreeHeader *BinaryTreeHeaderCreate()
{
    struct BinaryTreeHeader *header = malloc(sizeof(struct BinaryTreeHeader));
    header->root = NULL;
    header->size = 0;
    return header;
}

void TreeNodeRightRotate(struct TreeNode **node)
{
    if (node != NULL)
    {
        struct TreeNode *parent = *node;
        if (parent != NULL && parent->left != NULL)
        {
            struct TreeNode *leftson = parent->left;
            struct TreeNode *grandson = leftson->right;
            leftson->right = parent;
            parent->left = grandson;
            *node = leftson;
        }
    }
}

struct TreeNode *BstToVine(struct TreeNode *root)
{
    while (root->left != NULL)
    {
        TreeNodeRightRotate(&root);
    }
    struct TreeNode *current = root->right;
    struct TreeNode *previous = root;
    while (current != NULL)
    {
        while (current->left != NULL)
        {
            TreeNodeRightRotate(&current);
            previous->right = current;
        }
        previous = current;
        current = current->right;
    }
    return root;
}

void TreeNodeLeftRotate(struct TreeNode **node)
{
    if (node != NULL)
    {
        struct TreeNode *parent = *node;
        if (parent != NULL && parent->right != NULL)
        {
            struct TreeNode *rightson = parent->right;
            struct TreeNode *grandson = rightson->left;
            rightson->left = parent;
            parent->right = grandson;
            *node = rightson;
        }
    }
}

void compress(struct TreeNode **root, int times)
{
    struct TreeNode *head = NULL, *prev = NULL;
    struct TreeNode *node = *root;
    for (int i = 0; i < times; i++)
    {
        TreeNodeLeftRotate(&node);
        if (prev != NULL)
            prev->right = node;
        else
            head = node;
        prev = node;
        node = node->right;
        if (node == NULL)
            break;
    }
    *root = head;
}

void DSWAlgorithm(struct TreeNode **_root, const int total_node)
{
    struct TreeNode *root = *_root;
    root = BstToVine(root);

    int level = (int)floor(log2f((float)total_node));
    int bottom = total_node - ((1 << level) - 1);

    compress(&root, bottom);

    for (int i = ((1 << level) - 1) / 2; i > 0; i /= 2)
    {
        compress(&root, i);
    }

    *_root = root;
}

struct TreeNode *getTailAndRemoveInvalidTreeNode(struct TreeNode **root, int *removed_count)
{
    int removed_counter = 0;
    if (root != NULL && *root != NULL)
    {
        struct TreeNode *prev = NULL, *curr = *root;
        while (curr != NULL)
        {
            if (curr->entry.value == -1)
            {
                removed_counter++;
                if (prev == NULL) // root
                {
                    struct TreeNode *next = curr->right;
                    free(curr);
                    curr = next;
                    *root = next; // new head
                    continue;
                }
                else
                {
                    struct TreeNode *next = curr->right;
                    prev->right = next;
                    free(curr);
                    curr = next;
                    continue;
                }
            }
            else
            {
                prev = curr;
                curr = curr->right;
            }
        }

        if (removed_count != NULL)
        {
            *removed_count = removed_counter;
        }

        return prev; // return tail node
    }

    return NULL;
}

void HashMapRehashing(MyHashMap *hashmap)
{
    // TreeNode is used to pretend linked-list node. Left-child pointer is
    // prohibited to be used
    struct TreeNode *pseudo_head = TreeNodeCreate(-1, -1), *prev_tail = NULL;
    for (int i = 0; i < hashmap->bucket_size; i++)
    {
        if (hashmap->bucket[i].root != NULL)
        {
            struct TreeNode *root = BstToVine(hashmap->bucket[i].root);
            int removed_count = 0;
            // Invalid node will be removed in getTailAndRemoveInvalidTreeNode
            struct TreeNode *root_tail = getTailAndRemoveInvalidTreeNode(&root, &removed_count);
            hashmap->entry_size -= removed_count;
            if (pseudo_head->right == NULL)
            {
                pseudo_head->right = root;
            }
            else
            {
                if (prev_tail != NULL)
                {
                    prev_tail->right = root;
                }
            }
            if (root_tail != NULL)
                prev_tail = root_tail;
            struct BinaryTreeHeader *header = &hashmap->bucket[i];
            header->root = NULL;
            header->size = 0;
        }
    }

    free(hashmap->bucket);
    // Double the bucket size
    hashmap->bucket_size *= 2;
    hashmap->threshold = hashmap->bucket_size * hashmap->load_factor;
    hashmap->bucket = calloc(hashmap->bucket_size, sizeof(struct BinaryTreeHeader));

    // rebuild binary search tree for each bucket
    struct TreeNode *tree_node = pseudo_head->right;
    while (tree_node != NULL)
    {
        pseudo_head->right = tree_node->right; // save next node
        tree_node->left = NULL;
        tree_node->right = NULL;
        const int bucket_idx = hash(tree_node->entry.key, hashmap->bucket_size);
        BinarySearchTreeAppendNode(&hashmap->bucket[bucket_idx], tree_node);
        tree_node = pseudo_head->right;
    }

    // rebalance the binary search tree for every bucket
    for (int i = 0; i < hashmap->bucket_size; i++)
    {
        if (hashmap->bucket[i].root != NULL && hashmap->bucket[i].size > 2)
        {
            DSWAlgorithm(&hashmap->bucket[i].root, hashmap->bucket[i].size);
        }
    }

    free(pseudo_head);
}

MyHashMap *myHashMapCreate()
{
    MyHashMap *hashmap = (MyHashMap *)malloc(sizeof(MyHashMap));
    hashmap->load_factor = 0.75f;
    hashmap->entry_size = 0;
    hashmap->bucket_size = 16;
    hashmap->threshold = hashmap->bucket_size * hashmap->load_factor;
    hashmap->bucket = calloc(hashmap->bucket_size, sizeof(struct BinaryTreeHeader));
    return hashmap;
}

size_t hash(size_t value, size_t bucket_size)
{
    // bucket_size shall be power of 2
    // Fibonacci Hashing
    return (value * 11400714819323198485llu) >> (64 - ((int)log2f(bucket_size)));
}

void myHashMapPut(MyHashMap *obj, int key, int value)
{
    if (obj != NULL)
    {
        if (obj->entry_size > obj->threshold) // check if rehashing condition is triggered
        {
            HashMapRehashing(obj);
        }

        const int bucket_idx = hash(key, obj->bucket_size);
        const int status = BinarySearchTreeAppendOrReplace(&obj->bucket[bucket_idx], key, value);
        if (status == 1) // if new node is created and inserted into the tree
            obj->entry_size++;
    }
}

int myHashMapGet(MyHashMap *obj, int key)
{
    if (obj != NULL)
    {
        int bucket_idx = hash(key, obj->bucket_size);
        HashMapEntry *entry = BinarySearchTreeSearch(&obj->bucket[bucket_idx], key);
        if (entry != NULL)
            return entry->value;
    }
    return -1;
}

void myHashMapRemove(MyHashMap *obj, int key)
{
    if (obj != NULL)
    {
        int bucket_idx = hash(key, obj->bucket_size);
        BinarySearchTreeRemove(&obj->bucket[bucket_idx], key);
    }
}

void myHashMapFree(MyHashMap *obj)
{
    if (obj != NULL)
    {
        for (int i = 0; i < obj->bucket_size; i++)
            BinarySearchTreeFreeAll(obj->bucket[i].root);
        free(obj->bucket);
        free(obj);
    }
}