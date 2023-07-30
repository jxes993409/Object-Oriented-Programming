// a constant pointer
#include <iostream>

int main()
{
  double a = 1.34;
  double *const pa = &a; // a const pointer to a double

  std::cout << "*pa = " << *pa << std::endl; // value of a

  // double b = 6.5;
  // pa = &b; // a constant pointer cannot be changed
  std::cout << "*pa = " << *pa << std::endl;

  *pa = 7.6; // a constant pointer can be modified
  std::cout << "*pa = " << *pa << std::endl;
  std::cout << "  a = " << a << std::endl;
  return 0;
}