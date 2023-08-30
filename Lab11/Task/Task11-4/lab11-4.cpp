#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n = 10;
  vector<int> vec(n); // vec here is just an example.
  for (int i = 0; i < vec.size(); i++) // vec = {3, 6, 7, 5, 3, 5, 6, 2, 9, 1}
  vec[i] = rand() % n;
  sort(vec.begin(), vec.end()); // vec = {1, 2, 3, 3, 5, 5, 6, 6, 7, 9}
  reverse(vec.begin(), vec.end()); // vec = {9, 7, 6, 6, 5, 5, 3, 3, 2, 1}
  for (int i = 0; i < vec.size(); i++) {cout << vec[i] << " ";}
  cout << endl;
  vector<int>::iterator iter = find(vec.begin(), vec.end(), 8);
  if (iter != vec.end()) {cout << "8 is in the vector." << endl;}
  else {cout << "8 is not in the vector." << endl;}
  return 0;
}