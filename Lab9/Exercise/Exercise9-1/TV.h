#ifndef _TV_H_
#define _TV_H_

#include "Electronics.h"

class TV: public Electronics
{
  public:
    TV(int, int);
    ~TV();
    void charge() override;
    void run() override;
};

#endif