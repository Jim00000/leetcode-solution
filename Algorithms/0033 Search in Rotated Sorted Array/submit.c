int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle = (left + right) >> 1;

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