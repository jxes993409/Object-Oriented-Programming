#include <iostream>
#include <map>
#include <string>

using namespace std;

// map stores elements in increasing order based on a less-than operation <
int main()
{
  map<string, int> age;
  map<string, int>::iterator it;
  age["Mary"] = 22;
  age["Jacky"] = 18;
  age["John"] = 20;
  // practice_1
  // it = age.find("Jacky");
  // age.erase(it);
  // practice_2
  // age.erase(age.find("John"));
  // practice_3
  // cout << "Mary " << age.find("Mary")->second << endl;

  for (map<string,int>::const_iterator iter = age.begin(); iter != age.end(); iter++)
  {
    cout << "name: " << iter->first << " ";
    cout << "age: " << iter->second << endl;
  }
  return 0;
}