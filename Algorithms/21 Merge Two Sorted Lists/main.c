//
// 21. Merge Two Sorted Lists
//

#include <stdio.h>
#include "solution.h"

int main()
{
    struct ListNode* list1 = NULL, *list2 = NULL;
    insertToTail(&list1, 1);
    insertToTail(&list1, 2);
    insertToTail(&list1, 4);
    insertToTail(&list2, 1);
    insertToTail(&list2, 3);
    insertToTail(&list2, 4);
    printList(list1);
    printList(list2);
    
    struct ListNode* list3 = mergeTwoLists(list1, list2);
    printList(list3);
    return 0;
}