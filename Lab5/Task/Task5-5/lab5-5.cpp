#include <iostream>
#include <cmath>

using namespace std;

class Point2D
{
  private:
    int x;
    int y;
    double value;
  public:
    Point2D();
    Point2D(int n1, int n2);
    Point2D(int n1, int n2, double v);
    Point2D operator+(const Point2D &);
    Point2D operator-();
    void assignPoint2D(int n1, int n2);
    void assignPoint2D(int n1, int n2, double v);
    void displayPoint2D() const;
    friend double distPoint2D(const Point2D &, const Point2D &);
    friend double distPoint2D(const Point2D &, const Point2D &, const Point2D&);
    friend bool operator ==(const Point2D &, const Point2D &);
    friend bool operator !=(const Point2D &, const Point2D &);
};

Point2D::Point2D()
{
  x = 0;
  y = 0;
  value = 0;
}

Point2D::Point2D(int n1, int n2)
{
  assignPoint2D(n1, n2, 0.0);
}

Point2D::Point2D(int n1, int n2, double v)
{
  assignPoint2D(n1, n2, v);
}

Point2D Point2D::operator+(const Point2D &pt)
{
  return Point2D(x + pt.x, y + pt.y, value + pt.value);
}

Point2D Point2D::operator-()
{
  return Point2D(-x, -y, -value);
}

void Point2D::assignPoint2D(int n1, int n2)
{
  assignPoint2D(n1, n2, value);
}

void Point2D::assignPoint2D(int n1, int n2, double v)
{
  x = n1;
  y = n2;
  value = v;
}

void Point2D::displayPoint2D() const
{
  cout << "(" << x << "," << y << ") = ";
  cout << value << endl;
}

double distPoint2D(const Point2D &pt1, const Point2D &pt2)
{
  return sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
}

double distPoint2D(const Point2D &pt1, const Point2D &pt2, const Point2D &pt3)
{
  double n1 = distPoint2D(pt1, pt2);
  double n2 = distPoint2D(pt1, pt3);
  double n3 = distPoint2D(pt2, pt3);
  return (n1 + n2 + n3);
}

bool operator ==(const Point2D &pt1, const Point2D &pt2)
{
  return pt1.x != pt2.x || pt1.y != pt2.y || pt1.value != pt2.value ? false : true;
}

bool operator !=(const Point2D &pt1, const Point2D &pt2)
{
  return !(pt1 == pt2);
}

int main()
{
  Point2D pt1(3, 4, 4.1);
  Point2D pt2(3, 2, 4.5);
  pt1 == pt2 ? cout << "pt1 is equal to pt2 " : cout << "pt1 is not equal to pt2 ";
  cout << endl;
  pt1.displayPoint2D();
  pt2.displayPoint2D();
  Point2D pt3;
  pt3 = pt1 + pt2;
  pt3.displayPoint2D();
  Point2D pt4 = -pt1;
  pt4.displayPoint2D();
  return 0;
}