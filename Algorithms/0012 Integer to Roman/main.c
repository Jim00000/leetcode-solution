#include "solution.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__attribute__((always_inline)) inline static int __divide_remainder(int dividend, int divisor, int *remainder)
{
    int quotient;
    __asm__ volatile(
        /* instructions */
        "xorl %%edx, %%edx          \n"
        "movl %[dividend], %%eax    \n"
        "div  %[divisor]            \n"
        "movl %%eax, %[quotient]    \n"
        "movl %%edx, %[remainder]   \n"
        /* output */
        : [quotient] "=m"(quotient), [remainder] "=m"(*remainder)
        /* input */
        : [dividend] "r"(dividend), [divisor] "r"(divisor)
        : "memory", "eax", "edx");
    return quotient;
}

int main(int argc, char *argv[])
{
    int maxlength = 0;
    for (int i = 0; i < 4000; i++)
    {
        char *roman = intToRoman(i);
        maxlength = maxlength > strlen(roman) ? maxlength : strlen(roman);
        printf_s("%d %s\n", i, roman);
        free(roman);
    }

    printf_s("%d\n", maxlength);

    return 0;
}