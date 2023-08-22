#include <iostream>
#include "Rect.h"

Rect::Rect(int _L, int _W, int _x, int _y): Shape(_L, _x, _y)
{
  W = _W;
}

Rect::Rect(int _L, int _W, int _x, int _y, int _canvas): Shape(_L, _x, _y, _canvas)
{
  W = _W;
}

void Rect::ComputeArea()
{
  cout << "Area: " << getL() * W << endl;
}

void Rect::ComputePerimeter()
{
  cout << "Perimeter: " << 2 * (W + getL()) << endl;
}

void Rect::ComputePoints()
{
  // upper
  Shape::appendPoints(getX(), getY() - W / 2);
  // bottom
  Shape::appendPoints(getX(), getY() + W / 2);
  // left
  Shape::appendPoints(getX() - getL() / 2, getY());
  // right
  Shape::appendPoints(getX() + getL() / 2, getY());
  // upper right
  Shape::appendPoints(getX() + getL() / 2, getY() - W / 2);
  // bottom right
  Shape::appendPoints(getX() + getL() / 2, getY() + W / 2);
  // bottom left
  Shape::appendPoints(getX() - getL() / 2, getY() + W / 2);
  // upper left
  Shape::appendPoints(getX() - getL() / 2, getY() - W / 2);

  for (int i = 1; i < getL() / 2; i++)
  {
    Shape::appendPoints(getX() + i, getY() - W / 2);              // upper -> upper right
    Shape::appendPoints(getX() + getL() / 2 - i, getY() + W / 2); // bottom right -> bottom
    Shape::appendPoints(getX() - i, getY() + W / 2);              // bottom -> bottom left
    Shape::appendPoints(getX() - getL() / 2 + i, getY() - W / 2); // upper left -> upper
  }
  for (int i = 1; i < W / 2; i++)
  {
    Shape::appendPoints(getX() + getL() / 2, getY() - W / 2 + i); // upper right -> right
    Shape::appendPoints(getX() + getL() / 2, getY() + i);         // right -> bottom right
    Shape::appendPoints(getX() - getL() / 2, getY() + W / 2 - i); // bottom left -> left
    Shape::appendPoints(getX() - getL() / 2, getY() - i);         // left -> upper left
  }
}