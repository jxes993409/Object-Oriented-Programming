#include <iostream>

using namespace std;

class B
{
  private:
    int i;
  protected:
    float f;
  public:
    B() {i = 0; f = 0.0; d = 0.0;}
    double d;
    void g1(B b) {f = b.f;}
};

class X: protected B
{
  protected:
    short s;
  public:
    X() {s = 0;}
    void g2(X x) {B::g1(x);}
    void g3(B b) {B::g1(b);}
};

int main()
{
  B b1;
  X x1;
  x1.g2(x1);
  return 0;
}