#include "VMain.hpp"
#include <gtest/gtest.h>
#include <type_traits>

template <typename STRING, typename = std::enable_if_t<
                               std::is_convertible_v<STRING, std::string>>>
void CheckOutput(STRING &&Output) {
  const std::string ExpectedOutput = "firstsecondthird";
  EXPECT_EQ(Output, ExpectedOutput);
}

template <int A, int B, int C> void TestTemplate() {
  static_assert(1 <= A && A <= 3);
  static_assert(1 <= B && B <= 3);
  static_assert(1 <= C && C <= 3);
  testing::internal::CaptureStdout();
  VMain(A, B, C);
  std::string Output = testing::internal::GetCapturedStdout();
  CheckOutput(Output);
}

TEST(test_print_in_order, order_1_2_3) { TestTemplate<1, 2, 3>(); }
TEST(test_print_in_order, order_1_3_2) { TestTemplate<1, 3, 2>(); }
TEST(test_print_in_order, order_2_1_3) { TestTemplate<2, 1, 3>(); }
TEST(test_print_in_order, order_2_3_1) { TestTemplate<2, 3, 1>(); }
TEST(test_print_in_order, order_3_2_1) { TestTemplate<3, 2, 1>(); }
TEST(test_print_in_order, order_3_1_2) { TestTemplate<3, 1, 2>(); }