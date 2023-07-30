#ifndef _DOUBLE_H_
#define _DOUBLE_H_

class Double
{
  private:
    double num;
  public:
    Double(double);
    ~Double();
    void showResult();
  private:
    double Round();
    double Ceil();
    double Floor();
};

#endif