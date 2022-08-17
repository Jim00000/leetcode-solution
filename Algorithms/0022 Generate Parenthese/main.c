#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int total_size = 0;
    for (int i = 1; i <= 8; i++)
    {
        char** data = generateParenthesis(i, &total_size);
        printf_s("[%d] total_size:%d\n", i, total_size);
        for (int i = 0; i < total_size; i++)
        {
            printf_s("%s\n", data[i]);
            free(data[i]);
        }
        printf_s("\n");
        free(data);
    }
    return 0;
}