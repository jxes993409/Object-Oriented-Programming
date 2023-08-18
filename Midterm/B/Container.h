#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "Pair.h"

class Container
{
  private:
    Pair **data;
    int capacity = 0;
    static int count;
    void sort();

  public:
    // Constructors and destructor
    Container();
    Container(const Pair&);
    Container(Pair**, int);
    Container(const Container&);
    ~Container();

    // Member functions
    void erase(Pair*);
    void clear();
    bool empty();
    bool insert(const Pair&);
    int size() const;
    Pair* find(int);
    Pair* end();
    Pair* begin();

    // Static & friend functions
    static int getCount();
    friend ostream& operator <<(ostream&, const Container&);

    // Union container
    Container& operator +=(const Container&);
    Container operator +(const Container&);
    // Complement container
    Container& operator -=(const Container&);
    Container operator -(const Container&);
    // Swap container
    void operator *=(Container&);
    // Assign container
    Container& operator =(const Container&);
};

#endif