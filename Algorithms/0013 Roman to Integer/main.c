#include "solution.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__attribute__((always_inline)) inline static int __divide_remainder(const int dividend, const int divisor,
                                                                    int *remainder)
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

const static int roman_num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const static char *roman_symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const static int roman_symbols_size[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};

char *intToRoman(int num)
{
    int roman[] = {
        0, // I    1
        0, // IV   4
        0, // V    5
        0, // IX   9
        0, // X    10
        0, // XL   40
        0, // L    50
        0, // XC   90
        0, // C    100
        0, // CD   400
        0, // D    500
        0, // CM   900
        0  // M    1000
    };

    char *roman_string = malloc(16 * sizeof(char));
    roman_string[15] = '\0';
    int ch_ptr = 0;

    for (int i = 12; i >= 0; i--)
    {
        if (num >= roman_num[i])
        {
            roman[i] = __divide_remainder(num, roman_num[i], &num);

            for (int j = 0; j < roman[i]; j++)
            {
                strcpy_s(roman_string + ch_ptr, 16 - ch_ptr, roman_symbols[i]);
                ch_ptr += roman_symbols_size[i];
            }
        }
    }

    return roman_string;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < 4000; i++)
    {
        char *roman = intToRoman(i);
        printf_s("%d\n", romanToInt(roman));
        free(roman);
    }
    return 0;
}