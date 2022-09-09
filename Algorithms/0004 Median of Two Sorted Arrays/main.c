#include "solution.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf_s("%lf\n", findMedianSortedArrays((int[]){1, 3}, 2, (int[]){2, 4}, 2));
    printf_s("%lf\n", findMedianSortedArrays((int[]){1, 3, 5, 7, 8, 9, 10, 11}, 8, (int[]){2, 4}, 2));
    printf_s("%lf\n", findMedianSortedArrays((int[]){1, 3}, 2, (int[]){2}, 1));
    printf_s("%lf\n", findMedianSortedArrays((int[]){1, 3, 5}, 3, (int[]){2, 4}, 2));
    printf_s("%lf\n", findMedianSortedArrays((int[]){4, 7, 8}, 3, (int[]){2, 3}, 2));
    printf_s("\n");

    // corner case
    printf_s("[corner case] \n");
    printf_s("%lf\n", findMedianSortedArrays((int[]){2, 3}, 2, (int[]){2, 3}, 2));
    printf_s("%lf\n", findMedianSortedArrays((int[]){2, 2, 2}, 3, (int[]){2, 2}, 2));
    printf_s("%lf\n", findMedianSortedArrays((int[]){3, 3, 3}, 3, NULL, 0));
    printf_s("%lf\n", findMedianSortedArrays((int[]){1, 6, 10}, 3, NULL, 0));
    printf_s("%lf\n", findMedianSortedArrays((int[]){4, 7}, 2, NULL, 0));
    printf_s("%lf\n", findMedianSortedArrays((int[]){4}, 1, NULL, 0));
    return 0;
}