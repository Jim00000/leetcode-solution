#include "solution.h"
#include <stdlib.h>

struct ListNode *swapPairs(struct ListNode *head)
{
    struct
    {
        struct ListNode *head;
        struct ListNode *tail;
    } newlist;

    // Check empty list
    if (head == NULL)
    {
        return head;
    }

    // Check single-node linked list. Don't do anything.
    if (head->next == NULL)
    {
        return head;
    }
    else
    {
        // Handle first pair-node and swap link
        struct ListNode *next_pair_head = head->next->next;
        newlist.head = head->next;
        newlist.tail = head;
        newlist.head->next = newlist.tail;
        newlist.tail->next = next_pair_head;
        head = next_pair_head;
    }

    // Handle other pair-node except the first one
    while (head != NULL && head->next != NULL)
    {
        struct ListNode *next_pair_head = head->next->next;
        newlist.tail->next = head->next;
        newlist.tail->next->next = head;
        newlist.tail = head;
        head = next_pair_head;
    }

    // Handle last node if exist (i.e. odd-numbered linked list). Otherwise the head will be NULL
    // This is necessary to avoid tail circular loop from tail node being pointed to previous node
    newlist.tail->next = head;

    return newlist.head;
}