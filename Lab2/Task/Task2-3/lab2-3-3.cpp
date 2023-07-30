// a constant pointer to a constant
#include <iostream>

int main()
{
  double a = 1.34;
  const double *const pa = &a; // a const pointer to a constant

  std::cout << "*pa = " << *pa << std::endl;

  double b = 6.5;
  // pa = &b; // a constant pointer to constant cannot be changed
  std::cout << "*pa = " << *pa << std::endl;
  // *pa = 7.6; // a constant pointer to constant cannot be modified
  std::cout << "*pa = " << *pa << std::endl;
  return 0;

  return 0;
}