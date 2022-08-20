#include "solution.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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