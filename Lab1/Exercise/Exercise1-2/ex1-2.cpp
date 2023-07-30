#include <iostream>
#include "Array.h"

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
  Array array(arr, len);
  
  for (int i = 0; i < 3; i++)
  {
    array.showArray();
    int count = array.count_n();
    std::cout << "The counting number appears "<< count << " times in the num_arr" << std::endl;
    if (i == 2)
    {
      break;
    }
    array.add_num();
  }

  return 0;
}