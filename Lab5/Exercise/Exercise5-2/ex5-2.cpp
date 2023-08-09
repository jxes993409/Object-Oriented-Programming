#include <iostream>
#include "Score.h"

int main()
{
  Score score;
  int option;
  while (true)
  {
    score.print();
    cin >> option;
    if (option == 1) {score.set_score();}
    else if (option == 2) {score.w.set_weight();}
    else if (option == 3) {score.Change();}
    else if (option == 4) {score.avg();}
    else if (option == 5) {score.w.weight_avg();}
  }
  
  return 0;
}