#include "solution.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

FORCE_INLINE static void swap(int *restrict v1, int *restrict v2)
{
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

static int quicksortCompare(const void *v1, const void *v2)
{
    return *(int *)v1 - *(int *)v2;
}

static int splitArray(int *nums, int numsSize)
{
    for (int right = numsSize - 1; right >= 1; right--)
        if (nums[right] > nums[right - 1])
            return right;
    return 0;
}

static int searchMinValueIdx(int *restrict nums, int numsSize, int leftIdx, int rightIdx)
{
    const int pivot = nums[leftIdx];
    int minVal = INT_MAX, minValIdx = -1;
    for (; rightIdx < numsSize; rightIdx++)
    {
        if (nums[rightIdx] > pivot && nums[rightIdx] < minVal)
        {
            minVal = nums[rightIdx];
            minValIdx = rightIdx;
        }
    }

    return minValIdx;
}

static bool __nextPermutation(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return false;

    const int rightArrayIdx = splitArray(nums, numsSize);
    if (rightArrayIdx == 0 && numsSize > 0)
    {
        return __nextPermutation(nums + 1, numsSize - 1);
    }
    else
    {
        const int leftArrayIdx = rightArrayIdx - 1;
        // printf("rightArrayIdx %d \n", rightArrayIdx);
        const int minValIdx = searchMinValueIdx(nums, numsSize, leftArrayIdx, rightArrayIdx);
        // printf("minValIdx %d \n", minValIdx);
        swap(&nums[leftArrayIdx], &nums[minValIdx]);
        qsort(nums + rightArrayIdx, numsSize - rightArrayIdx, sizeof(nums[0]), quicksortCompare);
    }

    return true;
}

void nextPermutation(int *nums, int numsSize)
{
    if (numsSize > 1)
    {
        if (__nextPermutation(nums, numsSize) == false)
        {
            qsort(nums, numsSize, sizeof(nums[0]), quicksortCompare);
        }
    }
}