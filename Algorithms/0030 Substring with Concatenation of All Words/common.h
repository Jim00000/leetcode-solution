#pragma once

typedef struct TrieNode
{
    struct TrieNode *children[26];
    int childcnt;
    int hit;
    int count;
} TrieNode;

typedef struct
{
    TrieNode prefix;
} Trie;

typedef struct ListNode
{
    union 
    {
        TrieNode *data;
        int offset;
    };
    struct ListNode *next;
} ListNode;

typedef struct
{
    ListNode *head;
    ListNode *tail;
    int count;
} LinkedList;

TrieNode *createTrieNode();

void clearTrieNode(TrieNode **node);

Trie *createTrie();

void clearTrie(Trie **trie);

TrieNode* InsertTrie(Trie *trie, char *str);

ListNode *createListNode(TrieNode *trieNode);

ListNode *createListNodeForOffset(int offset);

LinkedList *createLinkedList();

void LinkedListClear(LinkedList **list);

void LinkedListInsertTail(LinkedList *list, TrieNode *trieNode);

void LinkedListInsertOffsetToTail(LinkedList *list, int offset);