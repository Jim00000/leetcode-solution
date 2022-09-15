#include "solution.h"
#include <stdio.h>

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    if (k == 1)
        return head;

    ListNode pseudo_head = {.val = -1, .next = NULL};
    ListNode pseudo_tail = {.val = -1, .next = NULL};
    ListNode *_head = NULL;
    ListNode *_tail = NULL;
    int group_length = k;

    ListNode *_fastkrunner = head;
    int forward = k;
    while (forward > 0 && _fastkrunner != NULL)
    {
        _fastkrunner = _fastkrunner->next;
        forward--;
    }

    if (_fastkrunner == NULL && forward != 0)
        return head;

    while (head != NULL)
    {
        if (pseudo_head.next == NULL)
        {
            pseudo_head.next = head;
            pseudo_tail.next = head;
            head = head->next;
            pseudo_head.next->next = NULL;
        }
        else
        {
            ListNode *current = head;
            head = head->next;
            current->next = pseudo_head.next;
            pseudo_head.next = current;
        }

        group_length--;
        if (_fastkrunner != NULL)
            _fastkrunner = _fastkrunner->next;
        else
            forward++;

        if (group_length == 0)
        {
            if (_head == NULL)
            {
                _head = pseudo_head.next;
            }
            if (_tail != NULL)
            {
                _tail->next = pseudo_head.next;
            }
            pseudo_head.next = NULL;
            _tail = pseudo_tail.next;
            group_length = k;
            if (_fastkrunner == NULL)
            {
                if (forward != 0)
                {
                    _tail->next = head;
                    break;
                }
            }
        }
    }

    return _head;
}