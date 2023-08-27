#ifndef _COMMODITY_H_
#define _COMMODITY_H_

#include <string>

using namespace std;

class Commodity
{
  private:
  public:
    string name;
    double* score;
    int* price;
    Commodity(string name, int price);
    virtual ~Commodity();
    virtual void cal_score() = 0;
    virtual void show_spec() = 0;
};

#endif