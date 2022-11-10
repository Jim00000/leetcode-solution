#include "solution.h"

const static char *keypad[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

const static int alphabet_length[] = {
    0, // 0
    0, // 1
    3, // 2
    3, // 3
    3, // 4
    3, // 5
    3, // 6
    4, // 7
    3, // 8
    4  // 9
};

static int digits_len;

static void getCombinationSize(  //
    char *restrict digits,       // input
    int *restrict size,          // output
    int *restrict digits_length) // output
{
    int sz = 1;
    char *digits_base = digits;

    while (*digits != '\0')
    {
        const int number = (*digits - '0');
        sz *= alphabet_length[number];
        digits++;
    }

    *size = sz;
    *digits_length = digits - digits_base;
}

static void makeLetterCombinations(char *restrict digits, char *words, int word_cur_idx, char **combs,
                                   int *restrict combs_cur_idx)
{
    if (*digits == '\0')
    {
        char *comb = malloc((digits_len + 1) * sizeof(char));
        memcpy(comb, words, digits_len + 1);
        combs[*combs_cur_idx] = comb;
        (*combs_cur_idx) += 1;
        return;
    }
    const int number = (*digits - '0');
    for (int i = 0; i < alphabet_length[number]; i++)
    {
        words[word_cur_idx] = keypad[number][i];
        makeLetterCombinations(digits + 1, words, word_cur_idx + 1, combs, combs_cur_idx);
    }
    words[word_cur_idx] = '\0';
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize)
{
    if (*digits == '\0')
    {
        *returnSize = 0; 
        return NULL;
    }

    getCombinationSize(digits, returnSize, &digits_len);

    char **combs = malloc(*returnSize * sizeof(char *));
    int combs_cur_idx = 0;

    if (digits_len > 0)
    {
        char *word = calloc(digits_len + 1 /* +1 for end of NULL */, sizeof(char));
        int word_cur_idx = 0;
        makeLetterCombinations(digits, word, word_cur_idx, combs, &combs_cur_idx);
        free(word);
    }

    return combs;
}