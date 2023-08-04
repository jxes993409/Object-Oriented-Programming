#include <iostream>

using namespace std;

// In C++11, it is not allowed to initialized non-integral type in class definition
// line 14: static double value = 0.0; Not allowed!

class Point2D
{
  private:
    int x;
    int y;
    static const int limit = 10;
    static double value; // indicates that all object’s value are the same

  public:
    Point2D();
    void assignPoint2D(int x, int y);
    void displayPoint2D();
    static void setValue(double v); // only static member function can access static member
};

Point2D::Point2D()
{
  x = 0;
  y = 0;
}

void Point2D::assignPoint2D(int n1, int n2)
{
  x = n1;
  y = n2;
}

void Point2D::displayPoint2D()
{
  cout << "(" << x << "," << y << ") = ";
  cout << value << endl;
}

void Point2D::setValue(double v)
{
  value = (v < limit ? v : limit);
}

double Point2D::value = 0.0;

int main()
{
  Point2D ptArray[10];
  ptArray[0].setValue(31.1); // modify the static member by static member fuction
  for (int i = 0; i < 10; i++)
  {
    ptArray[i].assignPoint2D(i, i+2);
    ptArray[i].displayPoint2D();
  }

  return 0;
}