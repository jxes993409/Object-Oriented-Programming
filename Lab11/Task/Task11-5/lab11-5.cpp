#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class A
{
  public:
    int a,b;
};

bool compare(const A &c1, const A &c2)
{
  if (c1.a < c2.a) {return true;}
  else if (c1.a == c2.a && c1.b < c2.b) {return true;}
  else {return false;}
}

int main()
{
  vector<A> vec(3);
  vec[0].a = 1; vec[0].b = 2;
  vec[1].a = 3; vec[1].b = 2;
  vec[2].a = 3; vec[2].b = 3;
  sort(vec.begin(), vec.end(), compare);
  for (int i = 0; i < vec.size(); i++) {cout << vec[i].a << " " << vec[i].b << endl;}
  return 0;
}