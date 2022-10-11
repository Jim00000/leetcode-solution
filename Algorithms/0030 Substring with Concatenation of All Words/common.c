#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TrieNode *createTrieNode()
{
    TrieNode *node = malloc(sizeof(TrieNode));
    memset(node, 0, sizeof(TrieNode));
    return node;
}

ListNode *createListNode(TrieNode *trieNode)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->data = trieNode;
    node->next = NULL;
    return node;
}

ListNode *createListNodeForOffset(int offset)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->offset = offset;
    node->next = NULL;
    return node;
}

void clearTrieNode(TrieNode **node)
{
    if (node != NULL && *node != NULL)
    {
        if ((*node)->childcnt > 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if ((*node)->children[i] != NULL)
                {
                    clearTrieNode(&(*node)->children[i]);
                }
            }
            free(*node);
            *node = NULL;
        }
        else
        {
            if ((*node)->count == 0)
                printf("[WARN] Invalid node \n");
            free(*node);
            *node = NULL;
        }
    }
}

LinkedList *createLinkedList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void LinkedListClear(LinkedList **list)
{
    if (list != NULL && *list != NULL)
    {
        ListNode *node = (*list)->head;
        while (node != NULL)
        {
            ListNode *current = node;
            node = node->next;
            free(current);
        }
        free(*list);
        *list = NULL;
    }
}

void LinkedListInsertTail(LinkedList *list, TrieNode *trieNode)
{
    if (list != NULL)
    {
        if (list->head == NULL)
        {
            list->head = createListNode(trieNode);
            list->tail = list->head;
        }
        else
        {
            list->tail->next = createListNode(trieNode);
            list->tail = list->tail->next;
        }
        list->count++;
    }
}

void LinkedListInsertOffsetToTail(LinkedList *list, int offset)
{
    if (list != NULL)
    {
        if (list->head == NULL)
        {
            list->head = createListNodeForOffset(offset);
            list->tail = list->head;
        }
        else
        {
            list->tail->next = createListNodeForOffset(offset);
            list->tail = list->tail->next;
        }
        list->count++;
    }
}

Trie *createTrie()
{
    Trie *trie = malloc(sizeof(Trie));
    memset(trie, 0, sizeof(Trie));
    return trie;
}

void clearTrie(Trie **trie)
{
    if (trie != NULL && *trie != NULL)
    {
        for(int i = 0; i < 26; i++)
        {
            if((*trie)->prefix.children[i] != NULL)
            {
                clearTrieNode(&(*trie)->prefix.children[i]);
            }
        }
        free(*trie);
        *trie = NULL;
    }
}

TrieNode *InsertTrie(Trie *trie, char *str)
{
    if (trie != NULL && str != NULL)
    {
        TrieNode *parent = &trie->prefix;

        while (*str != '\0')
        {
            const int idx = *str - 'a';
            TrieNode *child = parent->children[idx];
            if (child == NULL)
            {
                child = createTrieNode();
                parent->children[idx] = child;
                parent->childcnt++;
            }
            parent = child;
            str++;
        }

        parent->count++;        // record that this is the leaf node if count > 0
        if (parent->count == 1) // only return new node
            return parent;
    }

    return NULL;
}