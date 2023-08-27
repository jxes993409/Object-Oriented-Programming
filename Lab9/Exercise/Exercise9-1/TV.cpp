#include <iostream>
#include "TV.h"

TV::TV(int length, int width): Electronics(length, width)
{

}

TV::~TV()
{
  
}

void TV::charge()
{
  Electronics::charge();
  Electronics::set_usage(false);
}

void TV::run()
{
  if (Electronics::get_charging() && Electronics::get_usage()) {cout << "TV: (charging)" << endl;}
  else {cout << "TV: (not charging)" << endl;}
  Electronics::run();
}