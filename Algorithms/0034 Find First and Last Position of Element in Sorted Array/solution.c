#include "solution.h"
#include <stdlib.h>

FORCE_INLINE int *create_invalid_range()
{
    int *restrict range = malloc(2 * sizeof(int));
    range[0] = range[1] = -1;
    return range;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    if (numsSize == 0 || target > nums[numsSize - 1] || nums[0] > target)
        return create_invalid_range();
    else if (numsSize == 1)
    {
        if (nums[0] == target)
        {
            int *restrict range = malloc(2 * sizeof(int));
            range[0] = range[1] = 0;
        }
        else
            return create_invalid_range();
    }

    int left = 0;

    while (nums[left] < target)
    {
        int diff = target - nums[left];
        if (diff >= numsSize)
            diff = numsSize - 1;
        left += diff;
    }

    while (left >= 1 && nums[left - 1] == nums[left])
    {
        left--;
    }

    int right = numsSize - 1;

    while (nums[right] > target)
    {
        int diff = nums[right] - target;
        if (diff >= numsSize)
            diff = numsSize - 1;
        right -= diff;
    }

    while (right + 1 < numsSize && nums[right + 1] == nums[right])
    {
        right++;
    }

    if (nums[left] != target && nums[right] != target)
        return create_invalid_range();

    int *restrict range = malloc(2 * sizeof(int));
    range[0] = left;
    range[1] = right;
    return range;
}