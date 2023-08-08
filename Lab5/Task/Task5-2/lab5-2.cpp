#include <iostream>
#include <assert.h>

using namespace std;

class Vec
{
  public:
    Vec() {len = 0;}
    Vec(int n);
    ~Vec();
    void setValue(int idx, int v);
    void printVec() const;
    // move Items to public and assign constructor to public
    class Items         // nested class Items for Vec
    {                   // all members in Items are private
      private:          // make Vec can access member in Items
        friend class Vec;
        int value;
      public:
        Items() {value = 0;}
        Items(int v) {value = v;}
    };
  private:
    int len;
    Items *vec;
};

Vec::Vec(int n)
{
  len = n;
  vec = new Items [len];
}

Vec::~Vec()
{
  if (len > 0) {delete [] vec;}
  vec = NULL;
}

void Vec::setValue(int idx, int v)
{
  assert(idx < len);
  vec[idx].value = v;
}

void Vec::printVec() const
{
  for (int i = 0; i < len; i++) {cout << vec[i].value << " ";}
  cout << endl;
}

int main()
{
  Vec vector(5);
  vector.printVec();
  for (int i = 0; i < 5; i++) {vector.setValue(i, i);}
  vector.printVec();
  Vec::Items n;
  return 0;
}