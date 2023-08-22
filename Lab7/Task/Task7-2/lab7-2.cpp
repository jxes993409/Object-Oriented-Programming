#include <iostream>

using namespace std;

class Point2D
{
  private:
    int x;
    int y;
  public:
    Point2D(int n1 = 0, int n2 = 0): x(n1), y(n2) {}
    void display() const;
};

void Point2D::display() const
{
  cout << x << "," << y;
}

class Point4D: public Point2D
{
  private:
    int z;
    int t;
  public:
    Point4D(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0): Point2D(n1, n2), z(n3), t(n4) {}
    void display() const;
};

// Note that the prototype of function f is
// (const Point2D&, const Point2D&)
void Point4D::display() const
{
  Point2D::display();
  cout << "," << z << "," << t;
}

class Car: public Point4D
{
  private:
    int color;
    int year;
  public:
  Car(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0): Point4D(n1, n2, n3, n4)
  {
    color = 0;
    year = 0;
  }
  // copy constructor of Car should also provide
  // copy constructor for Point2D and Point4D
  Car(const Point4D& p): Point4D(p)
  {
    color = 0;
    year = 0;
  }
  void display() const;
  void setColor(const int c) {color = c;}
  void setYear(const int y) {year = y;}
};

void Car::display() const
{
  cout << "color: " << color << endl;
  cout << "year: " << year << endl;
  Point4D::display();
}

int main()
{
  Point4D pt4(1,2,3,4);
  Car c1(pt4);
  c1.setColor(128);
  c1.setYear(2011);
  c1.display(); cout << endl;
  return 0;
}