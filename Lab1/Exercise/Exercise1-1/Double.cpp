#include <iostream>
#include <cmath>
#include "Double.h"

Double::Double(double n)
{
  num = n;
}

Double::~Double() {}

void Double::showResult()
{
  std::cout << "the beginning of the function(showResult)" << std::endl;
  std::cout << "Round(" << num << ") = " << Double::Round() << std::endl;
  std::cout << "Ceil(" << num << ") = " << Double::Ceil() << std::endl;
  std::cout << "Floor(" << num << ") = " << Double::Floor() << std::endl;
  std::cout << "the end of the function(showResult)" << std::endl;
}

double Double::Round()
{
  return round(num);
}

double Double::Ceil()
{
  return ceil(num);
}

double Double::Floor()
{
  return floor(num);
}