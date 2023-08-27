#ifndef _FOOD_H_
#define _FOOD_H_

#include "Commodity.h"

using namespace std;

class Food: public Commodity
{
  private:
    int* car_value;
    int* pro_value;
    int* fat_value;
  public:
    Food(string, int, int, int, int);
    ~Food();
    void cal_score() override;
    void show_spec() override;
};

#endif