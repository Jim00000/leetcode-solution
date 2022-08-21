#include "solution.h"

const static int roman_num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const static char *roman_symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const static int roman_symbols_size[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};

int romanToInt(char * s)
{
    int integer = 0;
    int idx = 12;

    while(*s != '\0' && idx >= 0)
    {
        if(roman_symbols_size[idx] == 1)
        {
            if(roman_symbols[idx][0] == *s)
            {
                integer += roman_num[idx];
                s++;
            }
            else
            {
                idx--;
            }
        }
        else
        {
            if(roman_symbols[idx][0] == *s && roman_symbols[idx][1] == *(s + 1))
            {
                integer += roman_num[idx];
                s += 2;
            }
            else
            {
                idx--;
            }
        }
    }

    return integer;
}