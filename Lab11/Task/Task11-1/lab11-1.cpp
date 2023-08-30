#include <iostream>
#include <vector>

using namespace std;

// vec1.at(i) provides range checking but vec1[i] does not
int main()
{
  int n = 10;
  vector<int> vec1(n); // allocate a vector with 10 elements
  // use subscripting to access elements
  for (int i = 0; i < vec1.size(); i++) {vec1[i] = i * i;}
  for (int i = 0; i < vec1.size(); i++) {cout << vec1[i] << " ";}
  cout << endl;

  vector<int> vec2; // allocate an empty vector
  // use push_back() to add elements
  for (int i = 0; i < n; i++) {vec2.push_back(i * 2);}

  vector<int>::const_iterator iter;
  // use iterator to traverse container
  for (iter = vec2.begin(); iter != vec2.end(); iter++)  {cout << *iter << " ";}
  cout << endl;

  return 0;
}