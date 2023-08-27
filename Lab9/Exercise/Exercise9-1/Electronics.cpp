#include <iostream>
#include "Electronics.h"

Electronics::Electronics(int length, int width): length(length), width(width)
{
  usage = false;
  charging = false;
}

Electronics::~Electronics()
{

}

bool Electronics::get_charging()
{
  return charging;
}

void Electronics::set_charging(bool flag)
{
  charging = flag;
}

bool Electronics::get_usage()
{
  return usage;
}

void Electronics::set_usage(bool flag)
{
  usage = flag;
}

void Electronics::charge()
{
  get_charging() ? set_charging(false) : set_charging(true);
}

void Electronics::poweron()
{
  if (get_charging())
  {
    set_usage(true);
  }
}

void Electronics::poweroff()
{
  set_usage(false);
}

void Electronics::run()
{
  cout << " ";
  for (int i = 0; i < width; i++) {cout << "-";}
  cout << " " << endl;
  
  for (int i = 0; i < length - 2; i++)
  {
    cout << "|";
    for (int j = 0; j < width; j++)
    {
      get_usage() ? cout << "*" : cout << " ";
    }
    cout << "|" << endl;
  }

  cout << " ";
  for (int i = 0; i < width; i++) {cout << "-";}
  cout << " " << endl;
}