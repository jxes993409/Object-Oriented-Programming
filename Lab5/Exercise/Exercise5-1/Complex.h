#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <vector>
#include <string>

using namespace std;

class Complex
{
  private:
    double real;
    double imag;
  public:
    Complex();
    Complex(double, double);
    void inputComplex(bool);
    const Complex operator +(const Complex&);
    const Complex operator -(const Complex&);
    const Complex operator *(const Complex&);
    friend void printComplex(const Complex&);
    friend void printPolar(const Complex&);
  private:
    void converttoComplex(string);
    void spilt(string, vector<string>&);
};

#endif