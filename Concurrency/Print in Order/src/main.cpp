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

int main(int argc, char *argv[]) {
  assert(argc == 4 && "There must be three arguments given to this program");
  const int a = std::stoi(argv[1]);
  const int b = std::stoi(argv[2]);
  const int c = std::stoi(argv[3]);
  std::cout << "Input:[" << a << ',' << b << ',' << c << "]" << std::endl;
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
  std::cout << std::endl;
  return 0;
}