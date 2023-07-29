#include <iostream>

const int n = 10000;

int main()
{
  int n = 10;
  // :: indicate the member function under global namespace
  std::cout << n << " " << ::n << std::endl;
  return 0;
}