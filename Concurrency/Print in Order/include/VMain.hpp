#pragma once

#include "Foo.hpp"
#include "Print.hpp"
#include <cassert>
#include <future>
#include <iostream>

void printTasK(Foo *F, const int selector) {
  switch (selector) {
  case 1:
    F->first(PrintFirst);
    break;
  case 2:
    F->second(PrintSecond);
    break;
  case 3:
    F->third(PrintThird);
    break;
  default:
    break;
  }
}

int VMain(const int a, const int b, const int c) {
  Foo F;
  // Thread A
  std::future<void> A = std::async(printTasK, &F, a);
  // Thread B
  std::future<void> B = std::async(printTasK, &F, b);
  // Thread C
  std::future<void> C = std::async(printTasK, &F, c);
  A.wait();
  B.wait();
  C.wait();
  return 0;
}