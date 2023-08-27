#include <iostream>

using namespace std;

class Point2D
{
  private:
    int *x;
    int *y;
  public:
    Point2D()
    {
      x = new int (0);
      y = new int (0);
      cout << "New X and Y" << endl;
    }
    Point2D(int _x, int _y)
    {
      x = new int (_x);
      y = new int (_y);
      cout << "New X and Y" << endl;
    }
    virtual ~Point2D()
    {
      delete x;
      delete y;
      cout << "Delete X and Y" << endl;
    }
};

// an abstract class cannot be defined.
// It is illegal to define as Shape s;
class Shape
{
  protected:
    int color;
  public:
    virtual void draw() = 0;
    virtual bool is_closed() = 0;
    virtual ~Shape(){}
};

class Circle: public Shape
{
  private:
    Point2D center;
    double radius;
  public:
    Circle(const Point2D& p, int r, int c)
    {
      // copy data from p to center
      radius = r;
      color = c;
    }
    ~Circle()
    {

    }
    void draw();
    bool is_closed() {return true;}
};

void Circle::draw()
{
}

int main()
{
  Point2D pt(3,4);
  Circle c(pt,5,255);
  c.draw();
  return 0;
}