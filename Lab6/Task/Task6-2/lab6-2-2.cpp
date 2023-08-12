#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::istringstream;
using std::string;

int main()
{
  string s1 = "value 6";
  // use string object to initialize an istringstream
  istringstream format_str(s1);
  int a;
  string s2;
  format_str >> s2 >> a;
  cout << s2 << a << endl;
  return 0;
}