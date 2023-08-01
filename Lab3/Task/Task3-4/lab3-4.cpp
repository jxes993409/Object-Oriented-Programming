#include <iostream>

using namespace std;

class Point
{
  private:
    int x;
    int y;
  public:
    Point()
    {
      x = 0;
      y = 0;
    }
    int get_x() // Accessor
    {
      return x;
    }
    int get_y() // Accessor
    {
      return y;
    }
    void set_x(int px) // Mutator
    {
      x = px; 
    }
    void set_y(int py) // Mutator
    {
      y = py;
    }
};

int main()
{
  Point p;
  p.set_x(1);
  p.set_y(2);

  cout << "Point: x = " << p.get_x() << ",y = " << p.get_y() << endl;
  return 0;
}