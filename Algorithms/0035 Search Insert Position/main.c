#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

void testcase(int *restrict nums, int numSize, int target, int expected)
{
    int insertion = searchInsert(nums, numSize, target);
    printf("insertion: %d expected: %d \n", insertion, expected);
    fflush(stdout);
}

void vanillaTestCaseSuit()
{
    testcase((int[]){1, 3, 5, 6}, 4, 5, 2);
    testcase((int[]){1, 3, 5, 6}, 4, 2, 1);
    testcase((int[]){1, 3, 5, 6}, 4, 7, 4);
}

void MyTestCaseSuit1()
{
    testcase((int[]){1, 3, 5, 6}, 4, 0, 0);
    testcase((int[]){1, 3, 5, 6}, 4, 1, 0);
    testcase((int[]){1, 3, 5, 6}, 4, 3, 1);
    testcase((int[]){1, 3, 5, 6}, 4, 4, 1);
    testcase((int[]){1, 3, 5, 6}, 4, 6, 3);
    testcase((int[]){1, 3, 5, 6}, 4, 8, 4);
    testcase((int[]){1, 3, 5, 6}, 4, 9, 4);
}

void MyTestCaseSuit2()
{
    testcase((int[]){1, 3, 5, 7, 9}, 5, 0, 0);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 1, 0);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 2, 1);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 3, 1);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 4, 2);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 5, 2);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 6, 3);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 7, 3);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 8, 4);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 9, 4);
    testcase((int[]){1, 3, 5, 7, 9}, 5, 10, 5);
}

void CornerCaseSuit()
{
    testcase((int[]){1}, 1, 0, 0);
    testcase((int[]){1}, 1, 1, 0);
    testcase((int[]){1}, 1, 2, 1);
}


int main(int argc, char *argv[])
{
    vanillaTestCaseSuit();
    MyTestCaseSuit1();
    MyTestCaseSuit2();
    CornerCaseSuit();
    return 0;
}