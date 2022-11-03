#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

void testcase(int *restrict nums, int numSize, int target)
{
    int returnSize = 0;
    int *range = searchRange(nums, numSize, target, &returnSize);
    if (range != NULL)
    {
        if (returnSize != 0)
        {
            printf("%d ~ %d\n", range[0], range[1]);
        }
        free(range);
        range = NULL;
    }
    else
    {
        printf("[WARN] range is null\n");
    }
}

void vanillaTestCaseSuit()
{
    testcase((int[]){5, 7, 7, 8, 8, 10}, 6, 8);
    testcase((int[]){5, 7, 7, 8, 8, 10}, 6, 6);
    testcase(NULL, 0, 0);
}

void myTestCaseSuit()
{
    testcase((int[]){1}, 1, 1);
    testcase((int[]){1}, 1, 0);
    testcase((int[]){1}, 1, 2);
    testcase((int[]){1, 2}, 2, 1);
    testcase((int[]){1, 2}, 2, 2);
    testcase((int[]){1, 2}, 2, 0);
    testcase((int[]){1, 2}, 2, 3);
    testcase((int[]){1, 1, 1, 1, 1, 1, 1, 1, 1}, 9, 1);
    testcase((int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10, 1);
}

void failedTestCaseSuit()
{
    testcase((int[]){1, 3}, 2, 1);
}

int main(int argc, char *argv[])
{
    vanillaTestCaseSuit();
    myTestCaseSuit();
    failedTestCaseSuit();
    return 0;
}