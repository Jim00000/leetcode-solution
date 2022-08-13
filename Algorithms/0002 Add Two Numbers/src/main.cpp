#include <iostream>
#include "Simulator.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Add Two Numbers - LeetCode" << std::endl;
    Simulator simulator;
    std::optional<uint32_t> result = simulator.simulate({1}, {9, 9});
    if (result.has_value())
        std::cout << result.value() << std::endl;
    else
        std::cerr << "Invalid value" << std::endl;
    return 0;
}