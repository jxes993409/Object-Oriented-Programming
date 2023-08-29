#include <iostream>
#include <iomanip>

using namespace std;

class Point2D
{
  private:
    int x;
    int y;
  public:
    void setX(int _x) {x = _x;}
    void setY(int _y) {y = _y;}
    Point2D(): x(0), y(0) {};
    // virtual ~Point2D() = default;
    bool operator <(const Point2D& p)
    {
      if (x < p.x) {return true;}
      else if (x == p.x)
      {
        if (y < p.y) {return true;}
        return false;
      }
      return false;
    }
    friend ostream& operator <<(ostream& os, const Point2D& p)
    {
      os << "(" << p.x << ", " << p.y << ")";
      return os;
    }
};

template <class T>
T* new1D(int n)
{
  T* vec = new T [n];
  return vec;
}

template <class T>
void rand1D(T* vec, int n)
{
  for (int i = 0; i < n; i++)
  {
    vec[i] = rand() % 10;
  }
}

// int
template <>
void rand1D(int* vec, int n)
{
  for (int i = 0; i < n; i++)
  {
    vec[i] = rand() % 10;
  }
}

// double
template <>
void rand1D(double* vec, int n)
{
  for (int i = 0; i < n; i++)
  {
    vec[i] = rand() % 1000 / 100.0;
  }
}

// char
template <>
void rand1D(char* vec, int n)
{
  for (int i = 0; i < n; i++)
  {
    vec[i] = rand() % 26 + 65;
  }
}

// Point 2D
template <>
void rand1D(Point2D* vec, int n)
{
  for (int i = 0; i < n; i++)
  {
    int _x = rand() % 10;
    int _y = rand() % 10;
    vec[i].setX(_x);
    vec[i].setY(_y);
  }
}

template <class T>
void display1D(T* vec, int n)
{
  for (int i = 0; i < n; i++) {cout << vec[i] << " ";}
  cout << endl;
}

// double
template <>
void display1D(double* vec, int n)
{
  for (int i = 0; i < n; i++) {cout << fixed << setprecision(2) << vec[i] << " ";}
  cout << endl;
  cout.unsetf(ios::fixed);
}

// Point2D
template <>
void display1D(Point2D* vec, int n)
{
  for (int i = 0; i < n; i++) {cout << vec[i] << " ";}
  cout << endl;
}

template <class T>
void sort1D(T* vec, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (!(vec[j] < vec[j + 1]))
      {
        T temp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = temp;
      }
    }
  }
}

template <class T>
void delete1D(T* vec)
{
  delete [] vec;
}

template <class T>
void analysis(int n)
{
  T *vec = new1D<T>(n);
  rand1D<T>(vec, n);
  // for int, 0~9
  // for double, 0.00~9.99, i.e., rand()%1000/100.0
  // for char, A~Z
  // for Point2D, x: 0~9 y: 0~9
  display1D<T>(vec, n);
  // for double, set the precision with 2
  sort1D<T>(vec, n);
  display1D<T>(vec, n);
  delete1D<T>(vec);
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  srand(1);
  analysis<int>(n);
  analysis<double>(n);
  analysis<char>(n);
  analysis<Point2D>(n);
  return 0;
}