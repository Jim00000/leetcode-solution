#include "VMain.hpp"

int main(int argc, char *argv[]) {
  assert(argc == 4 && "There must be three arguments given to this program");
  const int a = std::stoi(argv[1]);
  const int b = std::stoi(argv[2]);
  const int c = std::stoi(argv[3]);
  std::cout << "Input:[" << a << ',' << b << ',' << c << "]" << std::endl;
  int ret = VMain(a, b, c);
  std::cout << std::endl;
  return ret;
}