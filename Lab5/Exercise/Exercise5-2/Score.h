#ifndef _SCORE_H_
#define _SCORE_H_

#include <string>

using namespace std;

class Score
{
  private:
    string name;
    double math, science, english;
    double average;
    class Weight
    {
      private:
        double weighted_avg;
        double math_weight, science_weight, english_weight;
        Score &score;
      public:
        //Weight(){}
        Weight(Score& x);
        void set_weight();
        void weight_avg();
    };
  public:
    Weight w;
    Score();
    void set_score();
    void avg();
    void Change();
    void print();
};

#endif