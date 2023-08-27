#include <iostream>
#include "Phone.h"

Phone::Phone(int in_rate, int out_rate, int length, int width): Electronics(length, width), in_rate(in_rate), out_rate(out_rate)
{
  current_power = 0;
}

Phone::~Phone()
{
  
}

void Phone::poweron()
{
  if (current_power > 0 || Electronics::get_charging())
  {
    Electronics::set_usage(true);
  }
}

void Phone::run()
{
  if (Electronics::get_charging())
  {
    cout << "Phone: (charging)  ";
    // is using? -> charge rate = in rate - out rate : charge rate = in rate
    if (Electronics::get_usage()) {current_power = ((current_power + in_rate - out_rate) < 100) ? current_power + in_rate - out_rate : 100;}
    else {current_power = ((current_power + in_rate) < 100) ? current_power + in_rate : 100;}
  }
  else
  {
    cout << "Phone: (not charging)  ";
    if (Electronics::get_usage()) {current_power = ((current_power - out_rate) > 0) ? current_power - out_rate : 0;}
  }
  // power = 0, trun off the phone
  if (current_power == 0)
  {
    Electronics::poweroff();
  }
  cout << current_power << "%" << endl;
  Electronics::run();
}