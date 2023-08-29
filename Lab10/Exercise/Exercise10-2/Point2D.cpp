#include "Point2D.h"

using namespace std;

void Point2D::setX(int _x)
{
  x = _x;
}

void Point2D::setY(int _y)
{
  y = _y;
}

int Point2D::getX()
{
  return x;
}

int Point2D::getY()
{
  return y;
} 

void Point2D::operator +=(const Point2D& p)
{
  x += p.x;
  y += p.y;
}

ostream& operator <<(ostream& os, const Point2D& p)
{
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}