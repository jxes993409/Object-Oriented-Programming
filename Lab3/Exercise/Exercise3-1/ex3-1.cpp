#include "LineGp.h"

using namespace std;

int main()
{
  LineGp l;
  l.set_lines(); // input points
  l.printLines(); // print lines
  l.computeArea(); // find intersections and compute area
  return 0;
}