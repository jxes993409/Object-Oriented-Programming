#ifndef _ARRAY_H_
#define _ARRAY_H_

class Array
{
  private:
    int *num_arr;
    int length;
  public:
    Array(int *, int);
    ~Array();
    void showArray();
    void add_num();
    int count_n();
};

#endif