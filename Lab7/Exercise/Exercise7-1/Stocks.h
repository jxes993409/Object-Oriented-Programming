#ifndef _STOCKS_H_
#define _STOCKS_H_

#include <iostream>
#include <string>

using namespace std;

class Stocks
{
  private:
    int* type;
    string* itemList;
  public: /* any member functions if necessary */
    Stocks(int);
    ~Stocks();
    void Initialize();
    void Display();
    Stocks& operator =(const Stocks&);
};

#endif