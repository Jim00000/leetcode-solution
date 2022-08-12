//
// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
//

#include <stdio.h>
#include "solution.h"

void sample_test()
{
    struct ListNode *list1 = NULL;
    insertToTail(&list1, 1);
    insertToTail(&list1, 4);
    insertToTail(&list1, 5);

    struct ListNode *list2 = NULL;
    insertToTail(&list2, 1);
    insertToTail(&list2, 3);
    insertToTail(&list2, 4);

    struct ListNode *list3 = NULL;
    insertToTail(&list3, 2);
    insertToTail(&list3, 6);

    struct ListNode *lists[] = {
        list1,
        list2,
        list3
    };

    struct ListNode *merged = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
    printList(merged);
}

void sample_test2()
{
    struct ListNode *list1 = NULL;
    insertToTail(&list1, 1);
    insertToTail(&list1, 2);
    insertToTail(&list1, 2);

    struct ListNode *list2 = NULL;
    insertToTail(&list2, 1);
    insertToTail(&list2, 1);
    insertToTail(&list2, 2);


    struct ListNode *lists[] = {
        list1,
        list2
    };

    struct ListNode *merged = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
    printList(merged);
}

void sample_test3()
{
    struct ListNode *lists[] = {
        NULL
    };

    struct ListNode *merged = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));
    printList(merged);
}

int main(int argc, char *argv[])
{
    /// TODO: use binary search tree to implement it
    ///  1. Build binary search tree
    ///  2. Inorder traversal
    sample_test();
    sample_test2();
    sample_test3();
    return 0;
}