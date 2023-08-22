#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape
{
  private:
  public: /* any member functions if necessary */
    Triangle(int, int, int);
    Triangle(int, int, int, int);
    void ComputeArea();
    void ComputePerimeter();
    void ComputePoints();
};

#endif