#include "Solution.hpp"

#include <iostream>
#include <stdexcept>
#include <unordered_map>

std::vector<int> Solution::twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> table;
  for (int i = 0; i < nums.size(); i++) {
    const int diff = target - nums[i];

    if (table.find(diff) != table.cend()) {
      return {i, table[diff]};
    }

    table[nums[i]] = i;
  }

  throw std::invalid_argument("No solutions are found");
}