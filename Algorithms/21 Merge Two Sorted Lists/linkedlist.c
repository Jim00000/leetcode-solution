#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct ListNode* createNewNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(newNode != NULL)
    {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

struct ListNode* findTail(struct ListNode *list)
{
    struct ListNode* tail = list;
    while((tail != NULL) && (tail->next != NULL))
    {
        tail = list->next;
    }
    return tail;
}

bool insertToTail(struct ListNode **plist, int val)
{
    struct ListNode *tail = findTail(*plist);

    struct ListNode *newNode = createNewNode(val);

    if(newNode == NULL)
    {
        return false;
    }

    if(tail == NULL)
    {
        *plist = newNode;
    }
    else
    {
        tail->next = newNode;
    }

    return true;
}

void printList(struct ListNode *list)
{
    if(list != NULL)
    {
        struct ListNode * node = list;
        while(node != NULL)
        {
            printf_s("%d", node->val);
            if(node->next != NULL)
                printf_s(" -> ");
            node = node->next;
        }
        printf_s("\n");
    }
}