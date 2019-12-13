// C Header

// C++ header
#include "Simulator.hpp"
#include "Solution.hpp"

using namespace leetcode;

std::optional<double> Simulator::simulate(double x, int n)
{
    Solution solver;
    double result = solver.myPow(x, n);
    return result;
}