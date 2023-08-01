#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>

using namespace std;

struct Point
{
  double x;
  double y;
};

struct Line
{
  Point P1;
  Point P2;
};

class LineGp
{
  private:
    Line lines[3];
    vector<Point> intersectP;
  public:
    LineGp();
    void set_lines();
    void printLines();
    void computeArea();
  private:
    void set_L(int, Line &);
    void intersect(Line, Line);
    void intersect_lines();
};

#endif