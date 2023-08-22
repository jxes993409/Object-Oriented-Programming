#include <iostream>
#include <algorithm>
#include "Shape.h"

bool sorted_X(Point p1, Point p2)
{
  return p1.x < p2.x;
}

bool sorted_Y(Point p1, Point p2)
{
  if (p1.x == p2.x) {return p1.y < p2.y;}
  return false;
}

Shape::Shape(int _L, int _x, int _y)
{
  L = _L;
  pos_x = _x;
  pos_y = _y;
  canvas_size = 20;
}

Shape::Shape(int _L, int _x, int _y, int _canvas)
{
  L = _L;
  pos_x = _x;
  pos_y = _y;
  canvas_size = _canvas;
}

void Shape::appendPoints(int x, int y)
{
  Point pushPoint;
  pushPoint.x = x;
  pushPoint.y = y;
  points.push_back(pushPoint);
}

bool Shape::find(int x, int y)
{
  for (Point p: points)
  {
    if (p.x == x && p.y == y)
    {
      return true;
    }
  }
  return false;
}

void Shape::draw()
{
  sort(points.begin(), points.end(), sorted_X);
  sort(points.begin(), points.end(), sorted_Y);
  cout << "|";
  for (int i = 0; i < canvas_size; i++) {cout << i % 10;}
  cout << "|";
  cout << endl;
  for (int i = canvas_size - 1; i >= 0; i--)
  {
    cout << i % 10;
    for (int j = 0; j < canvas_size; j++)
    {
      vector<Point>::iterator iter;
      if (find(j, i)) {cout << "*";}
      else {cout << " ";}
    }
    cout << i % 10;
    cout << "\\" << i;
    cout << endl;
  }
  cout << "|";
  for (int i = 0; i < canvas_size; i++) {cout << i % 10;}
  cout << "|";
  cout << endl;
}

vector<Point> Shape::getPoints()
{
  return points;
}

int Shape::getL()
{
  return L;
}

int Shape::getX()
{
  return pos_x;
}

int Shape::getY()
{
  return pos_y;
}