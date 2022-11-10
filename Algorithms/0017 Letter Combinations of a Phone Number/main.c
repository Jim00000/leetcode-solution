#include "solution.h"

void testcase(char *digits)
{
    int returnSize = 0;
    char **combs = letterCombinations(digits, &returnSize);
    if (combs != NULL && returnSize > 0)
    {
        for (int i = 0; i < returnSize; i++)
        {
            if (combs[i] != NULL)
            {
                printf("%s\n", combs[i]);
                fflush(stdout);
                free(combs[i]);
                combs[i] = NULL;
            }
        }
        free(combs);
        combs = NULL;
    }
}

void vanillaTestCaseSuit()
{
    testcase("23");
    testcase("");
    testcase("2");
}

void MyTestCaseSuit1()
{
    testcase("234");
    testcase("2345");
    testcase("23456");
}

void CornerCaseSuit()
{
}

int main(int argc, char *argv[])
{
    vanillaTestCaseSuit();
    MyTestCaseSuit1();
    CornerCaseSuit();
    return 0;
}