#include "solution.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *val1, int *val2)
{
    const int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

int partition(int *array, int left, int right)
{
    const int pivot = array[right - 1];
    int pivot_idx = left;
    for (int i = left; i < right - 1; i++)
    {
        if (pivot > array[i])
        {
            swap(array + i, array + pivot_idx);
            pivot_idx++;
        }
    }

    swap(array + pivot_idx, array + right - 1);

    return pivot_idx;
}

void quicksort_inplace(int *array, int left, int right)
{
    if (left < right)
    {
        const int pivot_index = partition(array, left, right);
        quicksort_inplace(array, left, pivot_index);
        quicksort_inplace(array, pivot_index + 1, right);
    }
}

void quicksort(int *array, int arraySize)
{
    quicksort_inplace(array, 0, arraySize);
}

struct ListNode2
{
    struct ListNode2 *next;
    int val1;
    int val2;
    int val3;
    int valid;
};

int find_minimum(int v1, int v2, int v3)
{
    int small = v1 > v2 ? v2 : v1;
    return v3 > small ? small : v3;
}

int find_maximum(int v1, int v2, int v3)
{
    int large = v1 > v2 ? v1 : v2;
    return v3 > large ? v3 : large;
}

struct ListNode2 *initializeCandidate()
{
    struct ListNode2 *header = malloc(sizeof(struct ListNode2));
    header->next = NULL;
    header->valid = -1;
    return header;
}

int checkDuplicate(struct ListNode2 *node, int val1, int val2, int val3)
{
    return (node->val1 == val1) && (node->val2 == val2);
}

int AddToCandidate(struct ListNode2 *header, int val1, int val2, int val3)
{
    if (header != NULL)
    {
        if (header->valid == -1)
        {
            header->val1 = val1;
            header->val2 = val2;
            header->val3 = val3;
            header->valid = 1;
        }
        else
        {
            while (header->next != NULL)
            {
                if (checkDuplicate(header, val1, val2, val3))
                    return 0;
                header = header->next;
            }

            if (checkDuplicate(header, val1, val2, val3))
                return 0;

            struct ListNode2 *node = initializeCandidate();
            node->val1 = val1;
            node->val2 = val2;
            node->val3 = val3;
            node->valid = 1;
            header->next = node;
        }
        return 1;
    }
    return 0;
}

void fillCandidatesToArray(struct ListNode2 *candidates, int **outputs)
{
    int idx = 0;
    while (candidates != NULL && candidates->valid != -1)
    {
        outputs[idx] = &candidates->val1;
        idx++;
        candidates = candidates->next;
    }
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    struct ListNode2 *candidates = initializeCandidate();

    quicksort(nums, numsSize);

    for(int i = 0; i < numsSize; i++)
    {
        int low = i + 1;
        int high = numsSize - 1;
        while(low < high)
        {
            int sum3 = nums[i] + nums[low] + nums[high];
            if(sum3 == 0)
            {
                *returnSize += AddToCandidate(candidates, nums[i], nums[low], nums[high]);
                low++;
                high--;
            }
            else if(sum3 > 0)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    }

    int **outputs = malloc((*returnSize) * sizeof(int *));
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = 3;
    }

    fillCandidatesToArray(candidates, outputs);

    return outputs;
}