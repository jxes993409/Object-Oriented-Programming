#include <iostream>
#include <cmath>
#include "Score.h"

Score::Weight::Weight(Score& x): score(x)
{

}

Score::Score():w (*this)
{
  name = "";
  math = 0;
  science = 0;
  english = 0;
}

void Score::set_score()
{
  cout << "name: "; cin >> name;
  cout << "math score: "; cin >> math;
  cout << "science score: "; cin >> science;
  cout << "english score: "; cin >> english;
}

void Score::avg()
{
  average = (math + science + english) / 3;
  cout << "average is: " << average << endl;
}

void Score::Change()
{
  math = sqrt(math) * 10;
  science = sqrt(science) * 10;
  english = sqrt(english) * 10;
  average = (math + science + english) / 3;
  cout << "average is: " << average << endl;
}

void Score::print()
{
  cout << "input 1~4 to select function :" << endl;
  cout << "1.Set score"  << endl;
  cout << "2.Set weight"  << endl;
  cout << "3.Change score"  << endl;
  cout << "4.Show average"  << endl;
  cout << "5.Show weight average" << endl;
}

void Score::Weight::set_weight()
{
  cout << "math weight: "; cin >> math_weight;
  cout << "science weight: "; cin >> science_weight;
  cout << "english weight: "; cin >> english_weight;
}

void Score::Weight::weight_avg()
{
  score.average = (score.math * math_weight + score.science * science_weight + score.english * english_weight);
  cout << "average is: " << score.average << endl;
}