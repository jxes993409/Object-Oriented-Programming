#include <iostream>
#define Area(x, y) ((x) * (y)) // marco

int main()
{
  double n = Area(3, 5.1);
  std::cout << "Area(3,5.1) = " << n << std::endl;
  return 0;
}