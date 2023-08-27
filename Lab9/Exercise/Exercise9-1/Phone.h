#ifndef _PHONE_H_
#define _PHONE_H_

#include "Electronics.h"

class Phone: public Electronics
{
  private:
    int current_power;
    int in_rate;
    int out_rate;
  public:
    Phone(int, int, int, int);
    ~Phone();
    void poweron() override;
    void run() override;
};

#endif