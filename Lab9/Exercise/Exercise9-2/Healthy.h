#ifndef _HEALTHY_H_
#define _HEALTHY_H_

#include "Commodity.h"

using namespace std;

class Healthy: public Commodity
{
  private:
    string* name_arr;
    int* value_arr;;
    int arr_length;
  public:
    Healthy(string, int, int);
    ~Healthy();
    void set_array(string, int, int);
    void cal_score() override;
    void show_spec() override;
};

#endif