// a pointer to a constant
#include <iostream>

int main()
{
  double a = 1.34;
  const double *pa = &a; // a pointer to a constant
  std::cout << "*pa = " << *pa << std::endl;
  double b = 6.5;
  pa = &b; // a pointer to a constant can change the pointer
  std::cout << "*pa = " << *pa << std::endl;
  //*pa = 7.6; // cannot modify a pointer to a constant
  b = 7.6;
  std::cout << "*pa = " << *pa << std::endl;

  return 0;
}