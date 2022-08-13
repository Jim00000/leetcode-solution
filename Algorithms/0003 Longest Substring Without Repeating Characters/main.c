#include <stdio.h>
#include "solution.h"

void sample_test(char* string)
{
    int len = lengthOfLongestSubstring(string);
    printf_s("%d\n", len);
}

int main(int argc, char *argv[])
{
    sample_test("abcabcbb");
    sample_test("bbbbb");
    sample_test("pwwkew");
    sample_test("au");
    sample_test("aab");
    return 0;
}