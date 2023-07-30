#include <iostream>
#include "Array.h"

Array::Array(int *arr, int len)
{
  num_arr = arr;
  length = len;
}

Array::~Array()
{
  delete [] num_arr;
  num_arr = NULL;
}

void Array::showArray()
{
  std::cout << "The number in num_arr is";
  for (int i = 0; i < length; i++)
  {
    std::cout << " " << num_arr[i];
  }
  std::cout << std::endl;
}

void Array::add_num()
{
  int input;
  std::cout << "please enter a new number: ";
  std::cin >> input;
  int *temp_arr = new int[++length];
  for (int i = 0; i < length - 1; i++)
  {
    temp_arr[i] = num_arr[i];
  }
  delete [] num_arr;
  num_arr = temp_arr;
  num_arr[length - 1] = input;
}

int Array::count_n()
{
  int input, count = 0;
  std::cout << "please enter a counting number: ";
  std::cin >> input;
  for (int i = 0; i < length; i++)
  {
    if (num_arr[i] == input)
    {
      count++;
    }
  }
  return count;
}