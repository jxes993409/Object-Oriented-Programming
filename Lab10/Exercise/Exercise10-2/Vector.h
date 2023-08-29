#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point2D.h"

template <class T>
class Vector
{
  private:
    int len;
    T* vec;
  public:
    // add any member if necessary
    Vector(int, T);
    Vector(int, T*);
    ~Vector();
    void display();
    void operator +=(const Vector<T>&);
    template<class S>
    friend S dot(const Vector<S>&, const Vector<S>&);
};

#endif