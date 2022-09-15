#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode *createListNode(const int val)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}

ListNode *convertArrayToList(int *const array, const int arraySize)
{
    ListNode _head = {.next = NULL, .val = -1};
    ListNode *tail = &_head;

    for (int i = 0; i < arraySize; i++)
    {
        tail->next = createListNode(array[i]);
        tail = tail->next;
    }
    return _head.next;
}

void printList(ListNode* list)
{
    while(list != NULL)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("nil\n");
}