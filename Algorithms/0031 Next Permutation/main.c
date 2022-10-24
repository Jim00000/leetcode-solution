#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

static void printNums(int* nums, int numSize)
{
    for (int i = 0; i < numSize; i++) printf("%d ", nums[i]);
    printf("\b\n");
}

static void testcase1()
{
    printf("%s\n", __func__);
    int nums[] = {1, 2, 3};
    nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
    printNums(nums, sizeof(nums) / sizeof(nums[0]));
}

static void testcase2()
{
    printf("%s\n", __func__);
    int nums[] = {3, 2, 1};
    nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
    printNums(nums, sizeof(nums) / sizeof(nums[0]));
}

static void testcase3()
{
    printf("%s\n", __func__);
    int nums[] = {1, 1, 5};
    nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
    printNums(nums, sizeof(nums) / sizeof(nums[0]));
}

static void testcase4()
{
    printf("%s\n", __func__);
    int nums[] = {1, 2, 3};
    for (int i = 0; i < 6; i++) {
        nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
        printNums(nums, sizeof(nums) / sizeof(nums[0]));
    }
}

static void testcase5()
{
    printf("%s\n", __func__);
    int nums[] = {1, 2, 3, 4};
    for (int i = 0; i < 24; i++) {
        nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
        printNums(nums, sizeof(nums) / sizeof(nums[0]));
    }
}

static void testcase6()
{
    printf("%s\n", __func__);
    int nums[] = {1, 2};
    for (int i = 0; i < 2; i++) {
        nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
        printNums(nums, sizeof(nums) / sizeof(nums[0]));
    }
}

static void testcase7()
{
    printf("%s\n", __func__);
    int nums[] = {1, 1, 2};
    for (int i = 0; i < 3; i++) {
        nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
        printNums(nums, sizeof(nums) / sizeof(nums[0]));
    }
}

static void testcase8()
{
    printf("%s\n", __func__);
    int nums[] = {1, 1, 2, 2, 3};
    for (int i = 0; i < 120; i++) {
        nextPermutation(nums, sizeof(nums) / sizeof(nums[0]));
        printNums(nums, sizeof(nums) / sizeof(nums[0]));
    }
}

int main(int argc, char* argv[])
{
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();
    testcase6();
    testcase7();
    testcase8();
    return 0;
}