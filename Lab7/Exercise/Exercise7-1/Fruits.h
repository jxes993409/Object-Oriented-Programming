#ifndef _FRUITS_H_
#define _FRUITS_H_

#include "Stocks.h"

class Fruits: public Stocks
{
  private:
    int *expired_month;
    int *expired_date;
  public: /* any member functions if necessary */
    Fruits(int, int, int);
    ~Fruits();
    void Display();
    Fruits& operator =(const Stocks&);
};

#endif