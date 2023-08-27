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
    }
    virtual ~Point2D()
    {
      delete x;
      delete y;
      cout << "Delete X and Y" << endl;
    }
    void setPoint2D(int _x, int _y)
    {
      *x = _x;
      *y = _y;
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

class Polygon: public Shape
{
  public:
    bool is_closed() {return true;}
};
class Triangle: public Polygon
{
  private:
    Point2D *vertices;
  public:
    Triangle(Point2D* p, int c)
    {
      vertices = new Point2D [3];
      // copy data from p to vertices
    }
    ~Triangle() {delete [] vertices;}
    void draw();
};

void Triangle::draw()
{

}

int main()
{
  Point2D *vec = new Point2D[3];
  vec[0].setPoint2D(1,1);
  vec[1].setPoint2D(6,1);
  vec[2].setPoint2D(1,8);
  Triangle t(vec,255);
  delete []vec;
  t.draw();
  return 0;
}