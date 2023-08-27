#include <iostream>
#include "Healthy.h"

Healthy::Healthy(string name, int price, int arr_length): Commodity(name, price), arr_length(arr_length)
{
  name_arr = new string [arr_length];
  value_arr = new int [arr_length];
}

Healthy::~Healthy()
{
  delete [] name_arr;
  delete [] value_arr;
}

void Healthy::set_array(string name, int value, int index)
{
  name_arr[index] = name;
  value_arr[index] = value;
}

void Healthy::cal_score()
{
  for (int i = 0; i < arr_length; i++) {*score += value_arr[i];}
  *score /= static_cast<double>(*price);
}

void Healthy::show_spec()
{
  cal_score();
  cout << "name: " << name << endl;
  cout << "price: " << *price << endl;
  for (int i = 0; i < arr_length; i++)
  {
    cout << name_arr[i] << ": " << value_arr[i] << endl;
  }
  cout << "score: " << *score << endl;
  cout << "=======================================" << endl;
}