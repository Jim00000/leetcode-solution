#include <cmath>
#include <iostream>
#include <limits>

#include "Solution.hpp"
#include "f2x.hpp"

using namespace leetcode;

// Check whether n is an even number
inline static bool isEvenNum(const int n) { return (n & 0x1) == 0; }

// Check whether n is an odd number
inline static bool isOddNum(const int n) { return !isEvenNum(n); }

// Use taylor series to approximate 2^x
//
// Note that F(x) = F(a) + F'(a) * (x - a) + F''(a) * (x - a)^2 / 2! + F'''(a) *
// (x - a)^3 / 3! + F''''(a) * (x - a)^4 / 4! + ... where F(x) = 2^x, F'(x) =
// lg(2) * 2^x, F''(x) = lg(2)^2 * 2^x, F'''(x) = lg(2)^3 * 2^x ...
//
// To make everything simple, we assume that a = 0 and then
// F(x) = F(0) + F'(0) * (x - 0) + F''(0) * (x - 0)^2 / 2! + ...
//      = 1 + lg(2) * x + lg(2)^2 * x^2 / 2! + lg(2)^3 * x^3 / 3! + ...
double approximate(const double x)
{
    const double logn = log(2);
    const double step = x * logn;
    double value = 1.0, stepX = step, factorial = 1.0, stepFactorial = 2.0;
    size_t it = 0;
    // More iterations to get more precise value
    while (it < 11) {
        value += stepX / factorial;
        stepX *= step;
        factorial *= stepFactorial;
        stepFactorial += 1.0;
        it++;
    }
    return value;
}

double Solution::myPow(double x, int n)
{
    bool reciprocal = false, isNegative = false;
    long N = n;

    if (N < 0) {
        N = abs(N);
        reciprocal = true;
    }

    if (x < 0) {
        x = fabs(x);
        if (isOddNum(n)) isNegative = true;
    }

    // We convert x^n to 2^(n * log2(x))
    // Note that x^n = 2^(log2(x^n))
    //               = 2^(n * log2(x))
    double nlog2x = N * log2(x);
    // Assume that we get 2^δ where δ is a real number, we can divide δ into
    // integer part and fractional part
    //
    // e.g. 3.21117 = 3 (integer part) + 0.21117 (fractional part)
    double integer;
    double fractional = modf(nlog2x, &integer);
    // Use taylor series to approximate 2^x where -1.0 < x < 1.0
    // double value = approximate(fractional);

    // Or use x86 f2xm1 instruction to calculate (2^x - 1)
    // Notice that we have plus one to the result in f2x function
    double value = f2x(fractional);
    // Use shift operation to calculate the value of integer part
    //
    // e.g. integer part is +3 means 1 << 3 → 8
    //      integer part is -5 means 1 / (1 << 5) → 1/32
    double shift = fabs(integer) >= 64
                       ? std::numeric_limits<unsigned long long>::max()
                       : static_cast<unsigned long long>(1)
                             << static_cast<unsigned long long>(fabs(integer));

    if (integer > 0)
        value *= shift;
    else
        value /= shift;

    if (reciprocal) value = 1.0 / value;

    if (isNegative) value = -value;

    return value;
}