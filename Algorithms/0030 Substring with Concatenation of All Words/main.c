#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

void testcase1()
{
    printf("testcase1\n");
    int returnSize = 0;
    int *indices = findSubstring("barfoofoobarthefoobarman", (char *[]){"foo", "bar", "the"}, 3, &returnSize);
    fflush(stdout);
    free(indices);
}

void testcase2()
{
    printf("testcase2\n");
    int returnSize = 0;
    int *indices = findSubstring("aaa", (char *[]){"a", "a"}, 2, &returnSize);
    fflush(stdout);
    free(indices);
}

void testcase3()
{
    printf("testcase3\n");
    int returnSize = 0;
    int *indices = findSubstring("barfoo", (char *[]){"foo", "bar"}, 2, &returnSize);
    fflush(stdout);
    free(indices);
}

void testcase4()
{
    printf("testcase4\n");
    int returnSize = 0;
    int *indices = findSubstring("aa", (char *[]){"aaa", "aaaa"}, 2, &returnSize);
    fflush(stdout);
    free(indices);
}

void testcase5()
{
    printf("testcase5\n");
    int returnSize = 0;
    int *indices = findSubstring("aaaaaaaaaaaa", (char *[]){"a", "a", "a", "a", "a"}, 5, &returnSize);
    fflush(stdout);
    free(indices);
}

int main(int argc, char *argv[])
{
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();
    return 0;
}