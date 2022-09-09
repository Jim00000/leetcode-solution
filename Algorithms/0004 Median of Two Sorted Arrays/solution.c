#include "solution.h"

static double findMedianSortedArraysRecursive(int *nums1, int nums1Size, int *nums2, int nums2Size, int count)
{
    if (count == 0)
    {
        if (nums1Size == 0 && nums2Size > 0)
        {
            return nums2[0];
        }
        if (nums1Size > 0 && nums2Size == 0)
        {
            return nums1[0];
        }
        if (nums1[0] >= nums2[0])
        {
            return nums2[0];
        }
        if (nums1[0] < nums2[0])
        {
            return nums1[0];
        }
    }
    else
    {
        if (nums1Size == 0 && nums2Size > 0)
        {
            return findMedianSortedArraysRecursive(nums1, nums1Size, nums2 + 1, nums2Size - 1, count - 1);
        }
        if (nums1Size > 0 && nums2Size == 0)
        {
            return findMedianSortedArraysRecursive(nums1 + 1, nums1Size - 1, nums2, nums2Size, count - 1);
        }
        if (nums1[0] >= nums2[0])
        {
            return findMedianSortedArraysRecursive(nums1, nums1Size, nums2 + 1, nums2Size - 1, count - 1);
        }
        if (nums1[0] < nums2[0])
        {
            return findMedianSortedArraysRecursive(nums1 + 1, nums1Size - 1, nums2, nums2Size, count - 1);
        }
    }

    return -99999;
}

static double findAverageMedianSortedArraysRecursive(int *nums1, int nums1Size, int *nums2, int nums2Size, int count)
{
    if (count == 0)
    {
        if (nums1Size == 0 && nums2Size > 0)
        {
            return nums2[0];
        }
        if (nums1Size > 0 && nums2Size == 0)
        {
            return nums1[0];
        }
        if (nums1[0] >= nums2[0])
        {
            return nums2[0];
        }
        if (nums1[0] < nums2[0])
        {
            return nums1[0];
        }
    }
    else if(count == 1)
    {
        if (nums1Size == 0 && nums2Size > 0)
        {
             return (nums2[0] + findAverageMedianSortedArraysRecursive(nums1, nums1Size, nums2 + 1, nums2Size - 1, count - 1)) / 2.0;
        }
        if (nums1Size > 0 && nums2Size == 0)
        {
            return (nums1[0] + findAverageMedianSortedArraysRecursive(nums1 + 1, nums1Size - 1, nums2, nums2Size, count - 1)) / 2.0;
        }
        if (nums1[0] >= nums2[0])
        {
             return (nums2[0] + findAverageMedianSortedArraysRecursive(nums1, nums1Size, nums2 + 1, nums2Size - 1, count - 1)) / 2.0;
        }
        if (nums1[0] < nums2[0])
        {
            return (nums1[0] + findAverageMedianSortedArraysRecursive(nums1 + 1, nums1Size - 1, nums2, nums2Size, count - 1)) / 2.0;
        }
    }
    else if (count > 0)
    {
        if (nums1Size == 0 && nums2Size > 0)
        {
            return findAverageMedianSortedArraysRecursive(nums1, nums1Size, nums2 + 1, nums2Size - 1, count - 1);
        }
        if (nums1Size > 0 && nums2Size == 0)
        {
            return findAverageMedianSortedArraysRecursive(nums1 + 1, nums1Size - 1, nums2, nums2Size, count - 1);
        }
        if (nums1[0] >= nums2[0])
        {
            return findAverageMedianSortedArraysRecursive(nums1, nums1Size, nums2 + 1, nums2Size - 1, count - 1);
        }
        if (nums1[0] < nums2[0])
        {
            return findAverageMedianSortedArraysRecursive(nums1 + 1, nums1Size - 1, nums2, nums2Size, count - 1);
        }
    }

    return -99999;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    const int numsSize = nums1Size + nums2Size;
    if (numsSize & 0x1)
    {
        // odd, one median
        return findMedianSortedArraysRecursive(nums1, nums1Size, nums2, nums2Size, numsSize / 2);
    }
    else
    {
        // even, average of two median
        return findAverageMedianSortedArraysRecursive(nums1, nums1Size, nums2, nums2Size, numsSize / 2);
    }
}