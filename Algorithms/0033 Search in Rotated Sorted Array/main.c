#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

void testcase(int *restrict nums, int numSize, int target)
{
    int output = search(nums, numSize, target);
    printf("%d\n", output);
}

void testcasesuit1()
{
    int nums[] = {28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 0,  1,  2,
                  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 28);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 29);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 30);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 31);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 32);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 33);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 34);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 35);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 36);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 37);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 38);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 39);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 40);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 41);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 42);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 43);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 44);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 45);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 46);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 47);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 48);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 49);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 0);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 1);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 2);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 3);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 4);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 5);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 6);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 7);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 8);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 9);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 10);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 11);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 12);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 13);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 14);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 15);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 16);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 17);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 18);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 19);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 20);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 21);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 22);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 23);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 24);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 25);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 26);
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 27);
}

void testcasesuit2()
{
    int nums[] = {3, 1};
    testcase(nums, sizeof(nums) / sizeof(nums[0]), 0);

}

int main(int argc, char *argv[])
{
    testcasesuit1();
    testcasesuit2();
    return 0;
}