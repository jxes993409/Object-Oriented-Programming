#include <iostream>
#include "Circle.h"

Circle::Circle(int _L, int _x, int _y): Shape(_L, _x, _y)
{
}

Circle::Circle(int _L, int _x, int _y, int _canvas): Shape(_L, _x, _y, _canvas)
{
}

void Circle::ComputeArea()
{
  cout << "Area: " << PI * getL() * getL() << endl;
}

void Circle::ComputePerimeter()
{
  cout << "Perimeter: " << 2 * PI * getL() << endl;
}

void Circle::ComputePoints()
{
  // upper
  Shape::appendPoints(getX(), getY() - getL());
  // bottom
  Shape::appendPoints(getX(), getY() + getL());
  // left
  Shape::appendPoints(getX() - getL(), getY());
  // right
  Shape::appendPoints(getX() + getL(), getY());
  for (int i = 1; i < getL(); i++)
  {
    Shape::appendPoints(getX() + i, getY() - getL() + i); // upper right
    Shape::appendPoints(getX() + getL() - i, getY() + i); // bottom right
    Shape::appendPoints(getX() - i, getY() + getL() - i); // bottom left
    Shape::appendPoints(getX() - getL() + i, getY() - i); // upper left
  }
}