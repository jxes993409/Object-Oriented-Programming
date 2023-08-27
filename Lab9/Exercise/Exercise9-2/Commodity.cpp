#include "Commodity.h"

Commodity::Commodity(string name, int price): name(name)
{
  this->price = new int(price);
  this->score = new double(0.0);
}

Commodity::~Commodity()
{
  delete score;
  delete price;
}