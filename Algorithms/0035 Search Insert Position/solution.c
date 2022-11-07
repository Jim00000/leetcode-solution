#include "solution.h"

int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle = (left + right) >> 1;

    if(target < nums[left])
        return 0;
    if(nums[right] < target)
        return numsSize;
    if(nums[left] == target)
        return left;
    if(nums[right] == target)
        return right;
    if(nums[middle] == target)
        return middle;

    if(numsSize == 2)
    {
        if(nums[left] < target && target < nums[right])
            return right;
        return -1;
    }

    if(nums[middle] > target)
    {
        return searchInsert(nums, numsSize - middle, target);
    }
    else // nums[middle] < target
    {
        int idx = searchInsert(&nums[middle], numsSize - middle, target);
        return middle + idx;
    }
}