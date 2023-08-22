#include <iostream>
#include "Square.h"

Square::Square(int _L, int _x, int _y): Rect(_L, _L, _x, _y)
{
}

Square::Square(int _L, int _x, int _y, int _canvas): Rect(_L, _L, _x, _y, _canvas)
{
}

void Square::ComputeArea()
{
  Rect::ComputeArea();
}

void Square::ComputePerimeter()
{
  Rect::ComputePerimeter();
}

void Square::ComputePoints()
{
  Rect::ComputePoints();
}

void Square::getPoints()
{
  Rect::getPoints();
}