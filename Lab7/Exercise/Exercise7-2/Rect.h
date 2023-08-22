#ifndef _RECT_H_
#define _RECT_H_

#include "Shape.h"

class Rect: public Shape
{
  private:
    int W;
  public: /* any member functions if necessary */
		Rect(int, int, int, int);
		Rect(int, int, int, int, int);
		void ComputeArea();
    void ComputePerimeter();
    void ComputePoints();
};

#endif