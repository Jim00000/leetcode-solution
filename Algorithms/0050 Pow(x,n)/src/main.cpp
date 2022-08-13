#include <iostream>
#include "Simulator.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Pow(x,n) - LeetCode" << std::endl;
    Simulator simulator;
    std::optional<double> r1 = simulator.simulate(0.00001, 2147483647);
    std::cout << "Pow(0.00001, 2147483647) = " << r1.value() << std::endl;
    r1 = simulator.simulate(15.53496, 3);
    std::cout << "Pow(15.53496, 3) = " << r1.value() << std::endl;
    r1 = simulator.simulate(0.44894, -5);
    std::cout << "Pow(0.44894, -5) = " << r1.value() << std::endl;
    r1 = simulator.simulate(-2.0, 2);
    std::cout << "Pow(-2.0, 2) = " << r1.value() << std::endl;
    r1 = simulator.simulate(2.1, 3);
    std::cout << "Pow(2.1, 3) = " << r1.value() << std::endl;
    r1 = simulator.simulate(2.0, 4);
    std::cout << "Pow(2.0, 4) = " << r1.value() << std::endl;
    r1 = simulator.simulate(2.0, 10);
    std::cout << "Pow(2.0, 10) = " << r1.value() << std::endl;
    r1 = simulator.simulate(2.0, -2);
    std::cout << "Pow(2.0, -2) = " << r1.value() << std::endl;
    r1 = simulator.simulate(1.0, 2147483647);
    std::cout << "Pow(1.0, 2147483647) = " << r1.value() << std::endl;
    r1 = simulator.simulate(2.0, -2147483647);
    std::cout << "Pow(2.0, -2147483647) = " << r1.value() << std::endl;
    r1 = simulator.simulate(-1.0, 2147483647);
    std::cout << "Pow(-1.0, 2147483647) = " << r1.value() << std::endl;
    return 0;
}