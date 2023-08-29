#ifndef _POINT2D_H_
#define _POINT2D_H_

#include <iostream>

using namespace std;

class Point2D
{
  private:
    int x;
    int y;
  public:
    Point2D(): x(1), y(1) {}
    Point2D(int _x, int _y): x(_x), y(_y) {}
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    void operator +=(const Point2D&);
    friend ostream& operator <<(ostream&, const Point2D&);
};

#endif