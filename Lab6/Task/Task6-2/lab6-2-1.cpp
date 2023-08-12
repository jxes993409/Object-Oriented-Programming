#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;

int main()
{
  int i = 1024;
  double d = 3.14159;
  ostringstream message;
  message << "i = " << i << ", d = " << d;
  // cout << message << endl;
  cout << message.str() << endl;
  return 0;
}