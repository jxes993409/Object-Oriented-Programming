#include "Vector.h"

template <class T>
Vector<T>::Vector(int len, T val): len(len)
{
  vec = new T [len];
  for (int i = 0; i < len; i++) {vec[i] = val;}
}

template <>
Vector<double>::Vector(int len, double val): len(len)
{
  vec = new double [len];
  for (int i = 0; i < len; i++) {vec[i] = val;}
}

template <>
Vector<Point2D>::Vector(int len, Point2D val): len(len)
{
  vec = new Point2D [len];
  for (int i = 0; i < len; i++) {vec[i] = val;}
}

template <class T>
Vector<T>::Vector(int len, T* arr): len(len)
{
  vec = new T [len];
  for (int i = 0; i < len; i++) {vec[i] = arr[i];}
}

template <>
Vector<double>::Vector(int len, double* arr): len(len)
{
  vec = new double [len];
  for (int i = 0; i < len; i++) {vec[i] = arr[i];}
}

template <>
Vector<Point2D>::Vector(int len, Point2D* arr): len(len)
{
  vec = new Point2D [len];
  for (int i = 0; i < len; i++) {vec[i] = arr[i];}
}

template <class T>
Vector<T>::~Vector()
{
  delete [] vec;
}

template <>
Vector<double>::~Vector()
{
  delete [] vec;
}

template <>
Vector<Point2D>::~Vector()
{
  delete [] vec;
}

template <class T>
void Vector<T>::display()
{
  for (int i = 0; i < len; i++) {cout << vec[i] << " ";}
  cout << endl;
}

template <>
void Vector<double>::display()
{
  for (int i = 0; i < len; i++) {cout << vec[i] << " ";}
  cout << endl;
}

template <>
void Vector<Point2D>::display()
{
  for (int i = 0; i < len; i++) {cout << vec[i] << " ";}
  cout << endl;
}

template <class T>
void Vector<T>::operator +=(const Vector<T>& v)
{
  for (int i = 0; i < len; i++)
  {
    vec[i] += v.vec[i];
  }
}

template <>
void Vector<double>::operator +=(const Vector<double>& v)
{
  for (int i = 0; i < len; i++)
  {
    vec[i] += v.vec[i];
  }
}

template <>
void Vector<Point2D>::operator +=(const Vector<Point2D>& v)
{
  for (int i = 0; i < len; i++)
  {
    vec[i] += v.vec[i];
  }
}

template <class S>
S dot(const Vector<S>& v1, const Vector<S>& v2)
{
  S ret = S(0);
  for (int i = 0; i < v1.len; i++) {ret += v1.vec[i] * v2.vec[i];}
  return ret;
}

template <>
double dot(const Vector<double>& v1, const Vector<double>& v2)
{
  double ret = 0.0;
  for (int i = 0; i < v1.len; i++) {ret += v1.vec[i] * v2.vec[i];}
  return ret;
}

template <>
Point2D dot(const Vector<Point2D>& v1, const Vector<Point2D>& v2)
{
  Point2D ret(0, 0);
  int sum_x = 0;
  int sum_y = 0;
  for (int i = 0; i < v1.len; i++)
  {
    sum_x += v1.vec[i].getX() * v2.vec[i].getX();
    sum_y += v1.vec[i].getY() * v2.vec[i].getY();
  }
  ret.setX(sum_x);
  ret.setY(sum_y);
  return ret;
}

// template Vector<double>::Vector(int, double);
// template Vector<double>::Vector(int, double*);
// template Vector<double>::~Vector();
// template void Vector<double>::display();
// template void Vector<double>::operator +=(const Vector<double>&);
// template double dot(const Vector<double>&, const Vector<double>&);

// template Vector<Point2D>::Vector(int, Point2D);
// template Vector<Point2D>::Vector(int, Point2D*);
// template Vector<Point2D>::~Vector();
// template void Vector<Point2D>::display();
// template void Vector<Point2D>::operator +=(const Vector<Point2D>&);
// template Point2D dot(const Vector<Point2D>&, const Vector<Point2D>&);