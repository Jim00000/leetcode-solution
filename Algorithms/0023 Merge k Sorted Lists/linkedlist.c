#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode *createNewNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode != NULL)
    {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

struct ListNode *findTail(struct ListNode *list)
{
    struct ListNode *tail = list;
    while ((tail != NULL) && (tail->next != NULL))
    {
        tail = tail->next;
    }
    return tail;
}

bool insertToTail(struct ListNode **plist, int val)
{
    struct ListNode *tail = findTail(*plist);

    struct ListNode *newNode = createNewNode(val);

    if (newNode == NULL)
    {
        return false;
    }

    if (tail == NULL)
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
    if (list != NULL)
    {
        struct ListNode *node = list;
        while (node != NULL)
        {
            printf_s("%d", node->val);
            if (node->next != NULL)
                printf_s(" -> ");
            node = node->next;
        }
        printf_s("\n");
    }
}

void plotListAsPng(struct ListNode *list)
{
    if (list != NULL)
    {
        int serial = 0;
        char buffer[BUFSIZ];
        FILE *fptr;
        fopen_s(&fptr, "linkedlist.dot", "w");
        fprintf(fptr, "digraph linkedlist {\n");
        fprintf(fptr, "    rankdir=LR;\n");

        struct ListNode *node = list, *prev = NULL;
        while (node != NULL)
        {
            fprintf(fptr, "    node_%d [label=\"%d\"]\n", serial++, node->val);
            node = node->next;
        }

        serial = 0;
        node = list;
        while (node != NULL)
        {
            if (prev != NULL)
            {
                fprintf(fptr, "    node_%d -> node_%d \n", serial, serial + 1);
                serial += 1;
            }
            prev = node;
            node = node->next;
        }
        fprintf(fptr, "}\n");
        fclose(fptr);
        sprintf(buffer, "dot linkedlist.dot -Tpng > linkedlist.png");
        system(buffer);
        sprintf(buffer, "start ./linkedlist.png");
        system(buffer);
    }
}