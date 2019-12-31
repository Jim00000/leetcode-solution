#include <iostream>
#include "Solution.hpp"

namespace {

void check(int n)
{
    leetcode::Solution solver;
    std::cout << n << " : " << solver.countAndSay(n) << '\n';
}

}  // namespace

int main(int argc, char* argv[])
{
    std::cout << "38. Count and Say - LeetCode" << std::endl;
    for (int i = 1; i <= 30; i++) check(i);
    return 0;
}