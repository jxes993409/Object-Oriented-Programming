#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Rect.h"

class Square: public Rect
{
  private:
  public: /* any member functions if necessary */
    Square(int, int, int);
    Square(int, int, int, int);
    void ComputeArea();
    void ComputePerimeter();
    void ComputePoints();
    void getPoints();
};

#endif