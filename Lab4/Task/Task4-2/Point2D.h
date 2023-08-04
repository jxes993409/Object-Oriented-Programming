#ifndef _POINT2D_H_
#define _POINT2D_H_

#include <iostream>

using namespace std;

class Point2D
{
  private:
    mutable int x; // add mutable to make lab 4-2-2 work successfully
    mutable int y; // add mutable to make lab 4-2-2 work successfully
    mutable int color;
    static const int limit = 10;
    static double value; // indicates that all object’s value are the same

  public:
    Point2D();
    void assignPoint2D(int x, int y);
    void displayPoint2D() const; // add const to make const Point2D work successfully
    static void setValue(double v); // only static member function can access static member
};

Point2D::Point2D()
{
  x = 0;
  y = 0;
}

void Point2D::assignPoint2D(int n1, int n2)
{
  x = n1;
  y = n2;
}

void Point2D::displayPoint2D() const
{
  x = 5;
  y = 4;
  color = 10;
  cout << "(" << x << "," << y << ") = ";
  cout << value << endl;
}

void Point2D::setValue(double v)
{
  value = (v < limit ? v : limit);
}

double Point2D::value = 0.0;

#endif