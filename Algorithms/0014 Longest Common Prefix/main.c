#include "solution.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *strs[] = {"flower", "flow", "flight"};
    printf_s("A:%s\n", longestCommonPrefix(strs, sizeof(strs) / sizeof(strs[0])));
    char *strs1[] = {"dog", "racecar", "car"};
    printf_s("A:%s\n", longestCommonPrefix(strs1, 3));
    char *strs2[] = {"dog", "dog"};
    printf_s("A:%s\n", longestCommonPrefix(strs2, 2));
    char *strs3[] = {""};
    printf_s("A:%s\n", longestCommonPrefix(strs3, 1));
    char *strs4[] = {"", ""};
    printf_s("A:%s\n", longestCommonPrefix(strs4, 2));
    char *strs5[] = {"flower","flower","flower","flower"};
    printf_s("A:%s\n", longestCommonPrefix(strs5, 4));


    // printf_s("%d \n", string_compare("HelloWorldGoodLife1", "HelloWorldGoodLife2"));
    // printf_s("%d \n", string_compare("HelloWorlD", "HellaWorld"));
    // printf_s("%d \n", string_compare("He", "eW"));
    // printf_s("%d \n", string_compare("same", "same"));

    // printf_s("%d\n", string_compare("He", "H"));

    return 0;
}