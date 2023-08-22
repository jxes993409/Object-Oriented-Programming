#include <iostream>
#include <iomanip>
#include <cmath>
#include "Triangle.h"

Triangle::Triangle(int _L, int _x, int _y): Shape(_L, _x, _y)
{
}

Triangle::Triangle(int _L, int _x, int _y, int _canvas): Shape(_L, _x, _y, _canvas)
{
}

void Triangle::ComputeArea()
{
  cout << "Area: " << getL() * getL() << endl;
}

void Triangle::ComputePerimeter()
{
  cout << "Perimeter: " << fixed << setprecision(2) << 2 * (getL() + sqrt(2) * getL()) << endl;
  cout.unsetf(ios::fixed);
}

void Triangle::ComputePoints()
{
  // upper
  Shape::appendPoints(getX(), getY());
  // bottom
  Shape::appendPoints(getX(), getY() - getL());
  // left
  Shape::appendPoints(getX() - getL(), getY() - getL());
  // right
  Shape::appendPoints(getX() + getL(), getY() - getL());
  
  for (int i = 1; i < getL(); i++)
  {
    Shape::appendPoints(getX() + getL() - i, getY() - getL());     // right -> bottom
    Shape::appendPoints(getX() - getL() + i, getY() - getL());     // left -> bottom
    Shape::appendPoints(getX() + getL() - i, getY() - getL() + i); // right -> upper
    Shape::appendPoints(getX() - getL() + i, getY() - getL() + i); // left -> upper
  }
}