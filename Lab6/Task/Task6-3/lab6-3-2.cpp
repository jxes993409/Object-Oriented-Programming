#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int num = 0;
  ifstream in("out.out");
  for ( int i = 0 ; i < 10 ; ++i)
  {
    // use member function to read a binary file
    in.read((char*)&num, sizeof(i));
    cout << num << endl;
  }
  in.close();
  return 0;
}