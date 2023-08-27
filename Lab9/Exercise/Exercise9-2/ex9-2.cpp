#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Food.h"
#include "Healthy.h"

using namespace std;

bool sortedbyName(Commodity* c1, Commodity* c2);
void spilt(vector<string>&, string, string);

int main(int argc, char* argv[])
{
  ifstream ifs(argv[1], ios::in);
  vector<Commodity*> commodity;
  string str;
  while (getline(ifs, str))
  {
    vector<string> str_vec;
    spilt(str_vec, str, " ");
    // Healthy
    if (str_vec[0] == "H")
    {
      Healthy* push_healthy = new Healthy(str_vec[1], stoi(str_vec[2]), stoi(str_vec[3]));
      for (int i = 0; i < stoi(str_vec[3]); i++)
      {
        push_healthy->set_array(str_vec[4 + 2 * i], stoi(str_vec[5 + 2 * i]), i);
      }
      commodity.push_back(push_healthy);
    }
    // Food
    else
    {
      Food* push_food = new Food(str_vec[1], stoi(str_vec[2]), stoi(str_vec[3]), stoi(str_vec[4]), stoi(str_vec[5]));
      commodity.push_back(push_food);
    }
  }
  sort(commodity.begin(), commodity.end(), sortedbyName);
  for (Commodity* c: commodity) {c->show_spec();}
  for (Commodity* c: commodity) {delete c;}
  return 0;
}

bool sortedbyName(Commodity* c1, Commodity* c2)
{
  return c1->name < c2->name;
}

void spilt(vector<string>& str_vec, string str, string tok)
{
  int current = 0;
  int next;
  while (true)
  {
    next = str.find_first_of(tok, current);

    string temp;
    temp = str.substr(current, next - current);
    str_vec.push_back(temp);

    if (next == static_cast<int>(string::npos)) {break;}
    current = next + 1;
  }
}