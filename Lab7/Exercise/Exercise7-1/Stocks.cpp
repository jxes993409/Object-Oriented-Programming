#include "Stocks.h"

Stocks::Stocks(int _type)
{
  type = new int{_type};
  itemList = new string[_type];
}

Stocks::~Stocks()
{
  if (type != nullptr)
  {
    delete type;
    type = nullptr;
  }
  if (itemList != nullptr)
  {
    delete [] itemList;
    itemList = nullptr;
  }
}

void Stocks::Initialize()
{
  cout << endl << "Initialize" << endl << endl;
  for (int i = 0; i < *type; i++)
  {
    cout << "Item " << i + 1 << ": ";
    cin >> itemList[i];
    cout << endl;
  }
}

void Stocks::Display()
{
  cout << "Item List: ";
  for (int i = 0; i < *type; i++)
  {
    cout << itemList[i] << " ";
  }
  cout << endl;
}

Stocks& Stocks::operator =(const Stocks& stocks)
{
  // delete origin data and allocate new memory space
  if (this->type != nullptr)
  {
    delete this->type;
    this->type = nullptr;
  }
  if (this->itemList != nullptr)
  {
    delete [] this->itemList;
    this->itemList = nullptr;
  }

  type = new int;
  itemList = new string [*(stocks.type)];
  
  *type = *(stocks.type);
  for (int i = 0; i < *type; i++)
  {
    itemList[i] = (stocks.itemList[i]);
  }
  return *this;
}