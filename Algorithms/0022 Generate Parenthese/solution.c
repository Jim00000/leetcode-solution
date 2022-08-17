#include "solution.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkCombination(int *symbols, int size, int length, int cumulative_sum, int one_count, int max_one, char** combinations, int *returnSize)
{
    if (cumulative_sum >= 0)
    {
        if (size < length)
        {
            if (one_count <= max_one)
            {
                symbols[size] = 1;
                checkCombination(symbols, size + 1, length, cumulative_sum + 1, one_count + 1, max_one, combinations, returnSize);
                symbols[size] = -1;
                checkCombination(symbols, size + 1, length, cumulative_sum - 1, one_count, max_one, combinations, returnSize);
            }
        }
        else if (size == length && one_count == max_one)
        {
            combinations[*returnSize] = malloc((length + 1) * sizeof(char));
            for(int i = 0; i < length; i++)
            {
                if(symbols[i] == 1)
                    combinations[*returnSize][i] = '(';
                else
                    combinations[*returnSize][i] = ')';
            }
            combinations[*returnSize][length] = '\0';
            (*returnSize)++;
        }
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    *returnSize = 0;
    const int length = 2 * n;
    int *symbols = calloc(length, sizeof(int));
    char** combinations = calloc(1430, sizeof(char*));
    symbols[0] = 1;
    checkCombination(symbols, 1, length, 1, 1, n, combinations, returnSize);

    return combinations;
}