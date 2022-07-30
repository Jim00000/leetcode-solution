#pragma once

#include <stdbool.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* createNewNode(int val);

struct ListNode* findTail(struct ListNode *list);

bool insertToTail(struct ListNode **list, int val);

void printList(struct ListNode *list);