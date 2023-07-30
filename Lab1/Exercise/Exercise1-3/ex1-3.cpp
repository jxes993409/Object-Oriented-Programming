#include <iostream>
#include "Array.h"

using namespace Array;

int main()
{
  int len;
  std::cout << "please enter the initial length: ";
  std::cin >> len;
  std::cout << "please enter " << len << " integer numbers: ";
  int *arr = new int[len];
  for (int i = 0; i < len; i++)
  {
    std::cin >> arr[i];
  }
  Arr array;
  initialize(array, arr, len);
  
  for (int i = 0; i < 3; i++)
  {
    showArray(array);
    int count = count_n(array);
    std::cout << "The counting number appears "<< count << " times in the num_arr" << std::endl;
    if (i == 2)
    {
      break;
    }
    add_num(array);
  }
  delete [] array.num_arr;
  array.num_arr = NULL;
  return 0;
}