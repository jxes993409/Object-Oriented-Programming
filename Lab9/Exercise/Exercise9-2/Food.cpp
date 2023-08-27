#include <iostream>
#include "Food.h"

Food::Food(string name, int price, int car_value, int pro_value, int fat_value): Commodity(name, price)
{
  this->car_value = new int (car_value);
  this->pro_value = new int (pro_value);
  this->fat_value = new int (fat_value);
}

Food::~Food()
{
  delete car_value;
  delete pro_value;
  delete fat_value;
}

void Food::cal_score()
{
  
  *score = *pro_value / static_cast<double>(*price);
}

void Food::show_spec()
{
  cal_score();
  cout << "name: " << name << endl;
  cout << "price: " << *price << endl;
  cout << "car: " << *car_value << endl;
  cout << "pro: " << *pro_value << endl;
  cout << "fat: " << *fat_value << endl;
  cout << "score: " << *score << endl;
  cout << "=======================================" << endl;
}