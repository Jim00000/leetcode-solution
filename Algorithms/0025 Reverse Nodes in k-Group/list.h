#pragma once

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode* createListNode(const int val);

ListNode* convertArrayToList(int* const array, const int arraySize);

void printList(ListNode* list);