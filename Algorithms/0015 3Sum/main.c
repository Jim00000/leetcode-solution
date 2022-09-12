#include "solution.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int returnSize;
    int *returnColumnSize;
    threeSum((int[]){-9, 4, 2, -4, -3, -4, -8, -5, -8, -6, -5, 2, 3, 9, -5, -2, 1}, 17, &returnSize, &returnColumnSize);
    threeSum((int[]){0,-4,-1,-4,-2,-3,2}, 7, &returnSize, &returnColumnSize);
    threeSum((int[]){1, 1, -2}, 3, &returnSize, &returnColumnSize);
    return 0;
}