#include <stdio.h>
#include "solution.h"

void sample_test(char* string, int numRows)
{
    char* zigzag_string = convert(string, numRows);
    printf_s("%s\n", zigzag_string);
}

int main(int argc, char *argv[])
{
    sample_test("PAYPALISHIRING", 3);
    sample_test("PAYPALISHIRING", 4);
    sample_test("PAYPALISHIRING", 5);
    return 0;
}