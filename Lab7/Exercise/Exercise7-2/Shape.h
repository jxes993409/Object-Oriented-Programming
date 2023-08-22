#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <vector>

using namespace std;

struct Point
{
  int x;
  int y;
};

class Shape
{
  private:
    int L;
    int pos_x;
    int pos_y;
    int canvas_size;
    vector<Point> points; //all plotting points
  public: /* any member functions if necessary */
    Shape(int, int, int);
    Shape(int, int, int, int);
    void appendPoints(int x, int y);
    bool find(int x, int y);
    void draw();
    vector<Point> getPoints();
    int getL();
    int getX();
    int getY();
};

#endif