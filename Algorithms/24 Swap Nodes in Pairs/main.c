#include <stdio.h>

#include "solution.h"

void test1()
{
    struct ListNode *head = NULL;
    insertToTail(&head, 1);
    insertToTail(&head, 2);
    insertToTail(&head, 3);
    insertToTail(&head, 4);
    printList(head);

    struct ListNode *output = swapPairs(head);
    printList(output);
}

void test2()
{
    struct ListNode *head = NULL;
    insertToTail(&head, 1);
    insertToTail(&head, 2);
    insertToTail(&head, 3);
    insertToTail(&head, 4);
    insertToTail(&head, 5);
    printList(head);

    struct ListNode *output = swapPairs(head);
    printList(output);
}

void test3()
{
    struct ListNode *output = swapPairs(NULL);
    printList(output);
}

void test4()
{
    struct ListNode *head = NULL;
    insertToTail(&head, 1);
    printList(head);

    struct ListNode *output = swapPairs(head);
    printList(output);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}