#include <stdio.h>
#include "solution.h"

void sample_test(char* input)
{
    printf_s("%d\n", isValid(input));
}

int main(int argc, char *argv[])
{
    sample_test("()");
    sample_test("()[]{}");
    sample_test("(]");
    sample_test("{[()]}");
    sample_test("))))");
    sample_test("((((");
    sample_test("]");
    return 0;
}