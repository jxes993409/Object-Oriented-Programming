#include "Fruits.h"

Fruits::Fruits(int _type, int _expired_month, int _expired_date): Stocks(_type)
{
  expired_month = new int;
  expired_date = new int;
  *expired_month = _expired_month;
  *expired_date = _expired_date;
}

Fruits::~Fruits()
{
  if (expired_month != nullptr)
  {
    delete expired_month;
    expired_month = nullptr;
  }
  if (expired_date != nullptr)
  {
    delete expired_date;
    expired_date = nullptr;
  }
}

void Fruits::Display()
{
  Stocks::Display();
  cout << endl;
  if (expired_month == nullptr && expired_date == nullptr) cout << "No Expiration Date";
  else {cout << "Expired at " << *expired_month << "/" << *expired_date;}
  cout << endl;
}

Fruits& Fruits::operator =(const Stocks& stocks)
{
  if (this->expired_month != nullptr)
  {
    delete this->expired_month;
    this->expired_month = nullptr;
  }
  if (this->expired_date != nullptr)
  {
    delete this->expired_date;
    this->expired_date = nullptr;
  }
  Stocks::operator =(stocks);
  return *this;
}