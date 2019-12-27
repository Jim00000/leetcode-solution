#include "f2x.hpp"

using namespace leetcode;

double leetcode::f2x(double x)
{
    asm volatile(
        "fld1                   \n\t"  // ST(0) = 1.0
        "fldl %0                \n\t"  // ST(0) = x; ST(1) = 1.0
        "f2xm1                  \n\t"  // ST(0) = 2^x - 1; ST(1) = 1.0
        "faddp %%st(0), %%st(1) \n\t"  // ST(0) = 2^x
        "fstpl %0               \n\t"  //
        :                              // outputs
        : "m"(x));                     // inputs
    return x;
}

__attribute__((naked)) double leetcode::__f2x(const double x)
{
    asm volatile(
        ".intel_syntax noprefix            \n\t"  // intel syntax
        "push rbp                          \n\t"  //
        "mov rbp, rsp                      \n\t"  //
        "movsd QWORD PTR [rbp - 0x8], xmm0 \n\t"  //
        "fld1                              \n\t"  // ST(0) = 1.0
        "fld QWORD PTR [rbp - 0x8]         \n\t"  // ST(0) = x; ST(1) = 1.0
        "f2xm1                             \n\t"  // ST(0) = 2^x - 1; ST(1)
                                                  // = 1.0
        "faddp ST(1), ST(0)                \n\t"  // ST(0) = 2^x
        "fstp QWORD PTR [rbp - 0x8]        \n\t"  //
        "movsd  xmm0, QWORD PTR [rbp-0x8]  \n\t"  //
        "leave                             \n\t"  //
        "ret                               \n\t"  //
        ".att_syntax noprefix              \n\t"  // roll back to AT&T syntax
        :
        :
        :);
}