#pragma once

typedef struct
{
    int key;
    int value;
} HashMapEntry;

struct TreeNode
{
    struct TreeNode *left, *right;
    HashMapEntry entry;
};

struct BinaryTreeHeader
{
    struct TreeNode *root;
    size_t size;
};

size_t hash(size_t value, size_t bucket_size);

////////////////////////////////////////////////////////////////////////////
// public interface
typedef struct
{
    float load_factor;
    int threshold;
    int entry_size;
    int bucket_size;
    struct BinaryTreeHeader *bucket;
} MyHashMap;

MyHashMap *myHashMapCreate();

void myHashMapPut(MyHashMap *obj, int key, int value);

int myHashMapGet(MyHashMap *obj, int key);

void myHashMapRemove(MyHashMap *obj, int key);

void myHashMapFree(MyHashMap *obj);
////////////////////////////////////////////////////////////////////////////