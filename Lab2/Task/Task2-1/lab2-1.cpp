#include <iostream>

int main()
{
  double a = 1.34;
  double *pa = &a;

  std::cout << "  a = " << a << std::endl; // value of a
  std::cout << " &a = " << &a << std::endl; // address of a
  // std::cout << " *a = " << *a << std::endl; // compiler error
  std::cout << " pa = " << pa << std::endl; // address of a
  std::cout << "&pa = " << &pa << std::endl; // address of pa
  std::cout << "*pa = " << *pa << std::endl; // value of a
  *pa = 6.5;
  std::cout << "  a = " << a << std::endl; // new value of a. 1.34 -> 6.5
  std::cout << "*pa = " << *pa << std::endl; // value of a

  return 0;
}