#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Shape.h"

#define PI 3.14

class Circle: public Shape
{
  private:
  public: /* any member functions if necessary */
    Circle(int, int, int);
    Circle(int, int, int, int);
    void ComputeArea();
    void ComputePerimeter();
    void ComputePoints();
};

#endif