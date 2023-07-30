#include <iostream>
#include "Array.h"

namespace Array
{
  void initialize(Arr &A, int* arr, int len)
  {
    A.num_arr = arr;
    A.length = len;
  }
  void showArray(Arr &A)
  {
    std::cout << "The number in num_arr is";
    for (int i = 0; i < A.length; i++)
    {
      std::cout << " " << A.num_arr[i];
    }
    std::cout << std::endl;
  }
  void add_num(Arr &A)
  {
    int input;
    std::cout << "please enter a new number: ";
    std::cin >> input;
    int *temp_arr = new int[++A.length];
    for (int i = 0; i < A.length - 1; i++)
    {
      temp_arr[i] = A.num_arr[i];
    }
    delete [] A.num_arr;
    A.num_arr = temp_arr;
    A.num_arr[A.length - 1] = input;
  }
  int count_n(Arr &A)
  {
    int input, count = 0;
    std::cout << "please enter a counting number: ";
    std::cin >> input;
    for (int i = 0; i < A.length; i++)
    {
      if (A.num_arr[i] == input)
      {
        count++;
      }
    }
    return count;
  }
}
