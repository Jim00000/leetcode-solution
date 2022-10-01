#include "solution.h"
#include <stdio.h>
#include <stdint.h>

void testcase(int32_t dividend, int32_t divisor, int32_t expected)
{
    int quotient = divide(dividend, divisor);
    const char* result = quotient == expected ? "Pass" : "Fail";
    printf_s("[%s] %d / %d = %d (%d)\n", result, dividend, divisor, quotient, expected);
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    testcase(5, 5, 1);
    testcase(4, 5, 0);
    testcase(0, 3, 0);
    testcase(3, 3, 1);
    testcase(4, 3, 1);
    testcase(5, 3, 1);
    testcase(6, 3, 2);
    testcase(7, 3, 2);
    testcase(8, 3, 2);
    testcase(9, 3, 3);
    testcase(10, 3, 3);
    testcase(11, 3, 3);
    testcase(12, 3, 4);
    testcase(13, 3, 4);
    testcase(14, 3, 4);
    testcase(15, 3, 5);
    testcase(16, 3, 5);
    testcase(17, 3, 5);
    testcase(18, 3, 6);
    testcase(19, 3, 6);
    testcase(20, 3, 6);
    testcase(21, 3, 7);
    testcase(1, 1, 1);
    testcase(0, 1, 0);
    testcase(7, -3, -2);
    testcase(-7, 3, -2);
    testcase(-1, 4, 0);
    testcase(-2147483648, -1, 2147483647);
    testcase(-2147483648, 1, -2147483648);
    testcase(-2147483648, -3, 715827882);
    return 0;
}