#include <gtest/gtest.h>
#include "Simulator.hpp"

// F(x,n) := x^n
void test_template(const double x, const double n, const double expected,
                   const double error = 1e-8)
{
    Simulator simulator;
    std::optional<double> r1 = simulator.simulate(x, n);
    double result = r1.value();
    EXPECT_NEAR(result, expected, error);
}

TEST(test_powerx_n, testsuit01) { test_template(0.00001, 2147483647, 0); }
TEST(test_powerx_n, testsuit02) { test_template(15.53496, 3, 3749.1292951); }
TEST(test_powerx_n, testsuit03) { test_template(0.44894, -5, 54.835080941); }
TEST(test_powerx_n, testsuit04) { test_template(-2.0, 2, 4); }
TEST(test_powerx_n, testsuit05) { test_template(2.1, 3, 9.261); }
TEST(test_powerx_n, testsuit06) { test_template(2.0, 4, 16); }
TEST(test_powerx_n, testsuit07) { test_template(2.0, 10, 1024); }
TEST(test_powerx_n, testsuit08) { test_template(2.0, -2, 0.25); }
TEST(test_powerx_n, testsuit09) { test_template(1.0, 2147483647, 1.0); }
TEST(test_powerx_n, testsuit10) { test_template(1.0, 2147483647, 1.0); }
TEST(test_powerx_n, testsuit11) { test_template(2.0, -2147483647, 0); }
TEST(test_powerx_n, testsuit12) { test_template(-1.0, 2147483647, -1.0); }
TEST(test_powerx_n, testsuit13) { test_template(1.0, -2147483647, 1.0); }