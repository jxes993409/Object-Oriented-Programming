#include <iostream>
#include <cmath>
#include <algorithm>
#include "LineGp.h"

using namespace std;

LineGp::LineGp()
{

}

void LineGp::set_lines()
{
  for (int i = 0; i < 3; i++)
  {
    set_L(i, lines[i]);
  }
}

void LineGp::printLines()
{
  cout << "////LINES////" << endl;
  cout << "L0: (" << lines[0].P1.x << "," << lines[0].P1.y << ") ("
                  << lines[0].P2.x << "," << lines[0].P2.y << ")" << endl;
  cout << "L1: (" << lines[1].P1.x << "," << lines[1].P1.y << ") ("
                  << lines[1].P2.x << "," << lines[1].P2.y << ")" << endl;
  cout << "L2: (" << lines[2].P1.x << "," << lines[2].P1.y << ") ("
                  << lines[2].P2.x << "," << lines[2].P2.y << ")" << endl;
  cout << "////LINES////\n\n" << endl;
}

void LineGp::computeArea()
{
  intersect_lines();
  if (intersectP.size() != 3)
  {
    cout << "\n\nNo Triangle\n\n" << endl;
  }
  else
  {
    // s0 = len(inter p1, inter p2)
    // s1 = len(inter p0, inter p2)
    // s2 = len(inter p0, inter p1)
    double s, s0, s1, s2, area;
    s0 = sqrt(pow((intersectP[1].x - intersectP[2].x), 2) + pow((intersectP[1].y - intersectP[2].y), 2));
    s1 = sqrt(pow((intersectP[0].x - intersectP[2].x), 2) + pow((intersectP[0].y - intersectP[2].y), 2));
    s2 = sqrt(pow((intersectP[0].x - intersectP[1].x), 2) + pow((intersectP[0].y - intersectP[1].y), 2));
    s = (s0 + s1 + s2) / 2;
    area = sqrt(s * (s - s0) * (s - s1) * (s - s2));
    cout << "\n\nArea is: " << area << "\n\n" << endl;
  }
}

void LineGp::set_L(int i, Line &line)
{
  cout << "L" << i << ":" << endl;
  cout << "Point 1: "; // input line[i] point 1
  cin >> line.P1.x >> line.P1.y;
  cout << "Point 2: "; // input line[i] point 2
  cin >> line.P2.x >> line.P2.y;
  if (min(line.P1.x, line.P2.x) != line.P1.x)
  {
    swap(line.P1.x, line.P2.x);
    swap(line.P1.y, line.P2.y);
  }
}

void LineGp::intersect(Line l1, Line l2)
{
  int m1_x = l1.P1.x - l1.P2.x;
  int m1_y = l1.P1.y - l1.P2.y;
  int m2_x = l2.P1.x - l2.P2.x;
  int m2_y = l2.P1.y - l2.P2.y;
  int v_l1 = -m1_y * l1.P1.x +  m1_x * l1.P1.y;
  int v_l2 = -m2_y * l2.P1.x +  m2_x * l2.P1.y;
  // line: (-m_y)x + (m_x)y = c
  cout << -m1_y << "x " << ((m1_x) < 0 ? "- " : "+ ") << abs(m1_x) << "y = " << v_l1 << endl;
  cout << -m2_y << "x " << ((m2_x) < 0 ? "- " : "+ ") << abs(m2_x) << "y = " << v_l2 << endl;
  double delta, delta_x, delta_y;
  delta = (-m1_y * m2_x) - (-m2_y * m1_x);
  delta_x = (v_l1 * m2_x) - (v_l2 * m1_x);
  delta_y = (-m1_y * v_l2) - (-m2_y * v_l1);
  if (!delta) // parallel
  {
    cout << "Two lines are parallel!" << endl;
  }
  else
  {
    Point inter;
    inter.x = delta_x / delta;
    inter.y = delta_y / delta;
    bool flag = true;
    if (inter.x < l1.P1.x || inter.x > l1.P2.x || inter.y < min(l1.P1.y, l1.P2.y) || inter.y > max(l1.P1.y, l1.P2.y) ||
        inter.x < l2.P1.x || inter.x > l2.P2.x || inter.y < min(l2.P1.y, l2.P2.y) || inter.y > max(l2.P1.y, l2.P2.y))
    {
      flag = false;
    }
    if (flag)
    {
      cout << "Intersect at (" << inter.x << "," << inter.y << ")" << endl;
      intersectP.push_back(inter);
    }
    else
    {
      cout << "Intersect point isn't in range!" << endl;
    }
  }
}

void LineGp::intersect_lines()
{
  cout << "L0, L1" << endl;
  intersect(lines[0], lines[1]);
  cout << "L0, L2" << endl;
  intersect(lines[0], lines[2]);
  cout << "L1, L2" << endl;
  intersect(lines[1], lines[2]);
}