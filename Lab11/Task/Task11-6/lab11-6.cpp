#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  map<int, string> classroom;
  classroom[9912345] = "Jacky";
  classroom[9923456] = "John";
  classroom[9934567] = "Mary";
  for (map<int,string>::const_iterator iter = classroom.begin(); iter != classroom.end(); iter++)
  {
    cout << "ID: " << iter->first << " ";
    cout << "name: " << iter->second << endl;
  }
  return 0;
}