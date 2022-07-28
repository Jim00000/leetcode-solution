#include <stdlib.h>
#include "solution.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct 
    {
        struct ListNode* head;
        struct ListNode* tail;
    } merged_list = {
        .head = NULL,
        .tail = NULL
    };

    // Check both lists are valid
    if(list1 == NULL && list2 == NULL)
    {
        return NULL;
    }

    // check list1 is valid but list2 is invalid
    if(list1 == NULL && list2 != NULL)
    {
        return list2;
    }
    
    // check list2 is valid but list1 is invalid
    if(list1 != NULL && list2 == NULL)
    {
        return list1;
    }

    // init merged_list
    if(list1->val > list2->val)
    {
        merged_list.head = list2;
        merged_list.tail = list2;
        list2 = list2->next;
    }
    else
    {
        merged_list.head = list1;
        merged_list.tail = list1;
        list1 = list1->next;
    }

    // compare the head of both list. Append the small one to merge_list
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val > list2->val)
        {
            merged_list.tail->next = list2;
            merged_list.tail = list2;
            list2 = list2->next;
        }  
        else if(list1->val < list2->val)
        {
            merged_list.tail->next = list1;
            merged_list.tail = list1;
            list1 = list1->next;
        }
        else
        {
            merged_list.tail->next = list1;
            merged_list.tail = list1;
            list1 = list1->next;
            merged_list.tail->next = list2;
            merged_list.tail = list2;
            list2 = list2->next;
        }
    }

    if(list1 != NULL && list2 == NULL)
    {
        merged_list.tail->next = list1;
    }
    else if(list1 == NULL && list2 != NULL)
    {
        merged_list.tail->next = list2;
    }

    return merged_list.head;
}