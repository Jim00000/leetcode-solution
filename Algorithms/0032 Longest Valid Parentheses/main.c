#include "solution.h"
#include <stdio.h>
#include <stdlib.h>

void testcase(char *restrict s)
{
    int valid = longestValidParentheses(s);
    printf("%s => %d\n", s, valid);
}

int main(int argc, char *argv[])
{
    testcase("(()");
    testcase(")()())");
    testcase("");
    testcase("(");
    testcase(")");
    testcase(")(");
    testcase("(()())");
    testcase("())(()");
    testcase(")((())");
    testcase("()(()");
    testcase("()()");
    testcase("()(())");
    testcase(")(())))(())())");
    return 0;
}