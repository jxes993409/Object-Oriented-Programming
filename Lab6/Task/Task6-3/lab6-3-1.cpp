#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream out("out.out", ios::binary);
  for ( int i = 0 ; i < 10 ; ++i)
  {
    // use member function to write a binary file
    out.write((char*)&i, sizeof(i));
  }
  out.close();
  return 0;
}