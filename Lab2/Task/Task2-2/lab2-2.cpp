#include <iostream>

int main()
{
  int a = 1024;
  int &refa = a;

  std::cout << "    a = " << a << std::endl; // value of a
  std::cout << "   &a = " << &a << std::endl; // address of a
  // std::cout << " *a = " << *a << std::endl; // compiler error
  std::cout << " refa = " << refa << std::endl; // value of a
  std::cout << "&refa = " << &refa << std::endl; // address of a
  // std::cout << "*refa = " << *refa << std::endl; // compiler error

  return 0;
}