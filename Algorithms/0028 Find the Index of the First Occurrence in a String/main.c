#include "solution.h"
#include <stdio.h>

void testcase1()
{
    int occur = 0;
    occur = strStr("sadbutsad", "sad");
    printf("%d should be 0\n", occur);
    occur = strStr("leetcode", "leeto");
    printf("%d should be -1\n", occur);
    occur = strStr("aaa", "aaaa");
    printf("%d should be -1\n", occur);
    occur = strStr("mississippi", "issip");
    printf("%d should be 4\n", occur);
    occur = strStr("aabaaabaaac", "aabaaac");
    printf("%d should be 4\n", occur);
}

int main(int argc, char *argv[])
{
    testcase1();
    return 0;
}