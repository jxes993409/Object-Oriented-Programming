#include <iostream>
#include "Double.h"

int main()
{
  double input;
  std::cout << "Please enter the number: ";
  std::cin >> input;
  Double number(input);
  number.showResult();
  return 0;
}