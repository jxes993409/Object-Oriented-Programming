#include <iostream>
#define D_TRIPLE(n) (n + n + n);
// my.GetValue() + my.GetValue() + my.GetValue()
// hihihi
// 2 + 2 + 2
// 6
inline int I_TRIPLE(int n) {return n + n + n;}
// my.GetValue()
// hi
// 2 -> return 2 + 2 + 2

struct MyClass{
  int m_nValue;
  int GetValue();
};

int MyClass::GetValue()
{
  std::cout << "hi";
  return m_nValue;
}

int main()
{
  MyClass my;
  my.m_nValue=2;
  int r1 = D_TRIPLE(my.GetValue());
  std::cout << std::endl;
  int r2 = I_TRIPLE(my.GetValue());
  std::cout << std::endl;
  std::cout << r1 << " " << r2 << std::endl;
  return 0;
}