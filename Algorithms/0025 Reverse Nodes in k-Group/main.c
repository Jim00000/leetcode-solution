#include "solution.h"

void testcase1()
{
    ListNode* list = convertArrayToList((int[]){1, 2, 3, 4, 5}, 5);
    ListNode* rev = reverseKGroup(list, 2);
    printList(rev);
}

void testcase2()
{
    ListNode* list = convertArrayToList((int[]){1, 2, 3, 4, 5}, 5);
    ListNode* rev = reverseKGroup(list, 3);
    printList(rev);
}

void testcase3()
{
    ListNode* list = convertArrayToList((int[]){1, 2, 3, 4, 5}, 5);
    ListNode* rev = reverseKGroup(list, 4);
    printList(rev);
}

void testcase4()
{
    ListNode* list = convertArrayToList((int[]){1, 2}, 2);
    ListNode* rev = reverseKGroup(list, 2);
    printList(rev);
}

void testcase5()
{
    ListNode* list = convertArrayToList((int[]){1, 2, 3, 4}, 4);
    ListNode* rev = reverseKGroup(list, 2);
    printList(rev);
}

int main(int argc, char *argv[])
{
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();
    return 0;
}