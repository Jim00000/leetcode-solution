#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

FORCE_INLINE static int getMiddle(int left, int right)
{
    return (left + right) >> 1;
}

int search(int *nums, int numsSize, int target)
{
    if (numsSize == 1)
        return target == nums[0] ? 0 : -1;

    int left = 0;
    int right = numsSize - 1;
    int middle = getMiddle(left, right);

    if (target == nums[middle])
        return middle;
    if (target == nums[left])
        return left;
    if (target == nums[right])
        return right;

    if(numsSize <= 3)
        return -1;

    if (target > nums[left])
    {
        if (nums[middle] > nums[left])
        {
            if (nums[middle] > target)
            { // nums[left] < target < nums[middle]
                // nums in strict ascending order between nums[middle] > target > nums[left]
                return search(nums, middle + 1, target);
            }
            else // target > nums[middle] > nums[left]
            {
                int idx = search(&nums[middle], numsSize - middle, target);
                return idx == -1 ? -1 : middle + idx;
            }
        }
        else // nums[middle] < nums[left] < target
        {
            if (nums[middle] < nums[right])
            { // nums[middle] < nums[right] < nums[left] < target
                return search(nums, middle + 1, target);
            }
            else // nums[middle] > nums[right]
            {    // nums[right] < nums[middle] < nums[left] < target
                // impossible case
                return -2;
            }
        }
    }
    else // target < nums[right]
    {
        if (nums[middle] > target)
        {
            if (nums[middle] < nums[right])
            { // target < nums[middle] < nums[right] < nums[left]
                return search(nums, middle + 1, target);
            }
            else // nums[right] < nums[middle]
            { // target < nums[right] < nums[left] < nums[middle]
                int idx = search(&nums[middle], numsSize - middle, target);
                return idx == -1 ? -1 : middle + idx;
            }
        }
        else // nums[middle] < target < nums[right] < nums[left]
        {
            int idx = search(&nums[middle], numsSize - middle, target);
            return idx == -1 ? -1 : middle + idx;
        }
    }

    return -1;
}