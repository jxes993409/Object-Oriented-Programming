#include <iostream>
#include <iomanip>
#include <cmath>
#include "Complex.h"

Complex::Complex()
{
  real = 0.0;
  imag = 0.0;
}

Complex::Complex(double r, double i)
{
  real = r;
  imag = i;
}

void Complex::inputComplex(bool flag)
{
  if (flag)
  {
    this->real = 0.0;
    this->imag = 0.0;
  }
  string input_complex;
  cout << "input complex number: ";
  cin >> input_complex;
  converttoComplex(input_complex);
}

void Complex::converttoComplex(string input)
{
  vector<string> spilt_input;
  spilt(input, spilt_input);
  for (string str: spilt_input)
  {
    if (str.back() == 'j')
    {
      if (str.length() == 2) {imag = (str.front() == '-') ? imag - 1 : imag + 1;} // -j or +j
      else {imag += stod(str.substr(0, str.length() - 1));}
    }
    else {real += stod(str);}
  }
}

void Complex::spilt(string input, vector<string>& spilt_input)
{
  int current = 0;
  int next;
  while (true)
  {
    next = input.find_first_of("+-", current); // spilt by + or -
    if (next != current)
    {
      string temp;
      // first spilt store the sign later (line: 65)
      temp = (spilt_input.empty()) ? input.substr(current, next - current) : input.substr(current - 1, next - current + 1);
      if (temp.length() != 0) {spilt_input.push_back(temp);}
    }
    if (next == static_cast<int>(string::npos)) {break;}
    current = next + 1;
  }
  // postive -> append '+'
  // negative -> append '-'
  spilt_input[0] = (input.front() == '-') ? '-' + spilt_input[0] : '+' + spilt_input[0];
}

const Complex Complex::operator +(const Complex& pt)
{
  return Complex(real + pt.real, imag + pt.imag);
}

const Complex Complex::operator -(const Complex& pt)
{
  return Complex(real - pt.real, imag - pt.imag);
}

const Complex Complex::operator *(const Complex& pt)
{
  double Z1 = pt.real * (real + imag);
  double Z2 = Z1;
  double Z3 = -imag * (pt.real + pt.imag);
  double Z4 = real * (pt.imag - pt.real);
  return Complex(Z1 + Z3, Z2 + Z4);
}

void printComplex(const Complex& pt)
{
  cout << "Complex number is: " << pt.real;
  if (pt.imag > 1) {cout << "+" << pt.imag << "j" << endl;}
  else if (pt.imag == 1) {cout << "+j" << endl;}
  else if (pt.imag == 0) {cout << endl;}
  else if (pt.imag == -1) {cout << "-j" << endl;}
  else if (pt.imag < -1) {cout << pt.imag << "j" << endl;}
}

void printPolar(const Complex& pt)
{
  double polar = sqrt(pt.real * pt.real + pt.imag * pt.imag);
  double theta = atan(pt.imag / pt.real) * 180 / M_PI;
  cout << "Polar form is: " << fixed << setprecision(3) << polar <<
          "(cos" << theta << "+isin" << theta << ")" << endl;
  cout.unsetf(ios::fixed); // unset setprecision(3)
}