#pragma once

#include "Solution.hpp"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <set>
#include <vector>

template <typename T>
bool equal(std::vector<T> &input1, std::vector<T> &input2) {
  std::set<T> set1{input1.cbegin(), input1.cend()};
  std::set<T> set2{input2.cbegin(), input2.cend()};
  return set1 == set2;
}

template <typename T>
bool Simulate(std::initializer_list<T> integers, T target,
              std::initializer_list<T> solutions) {
  Solution solver;
  std::vector<T> inputs{integers}, sols_vec{solutions};
  std::vector<T> indices = solver.twoSum(inputs, target);
  bool isCorrect = equal(indices, sols_vec);
  return isCorrect;
}