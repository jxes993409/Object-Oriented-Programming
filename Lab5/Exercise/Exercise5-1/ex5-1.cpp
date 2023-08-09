#include <string>
#include <iostream>
#include "Complex.h"

void inputOperator(int&);
void executeOperator(Complex&, Complex&, int, int&);

int main()
{
  Complex complex1, complex2;
  complex1.inputComplex(false);
  int input_case, last_case;
  while (true)
  {
    inputOperator(input_case);
    executeOperator(complex1, complex2, input_case, last_case);
    printComplex(complex1);
  }
  return 0;
}

void inputOperator(int& input_case)
{
  string input_operator;
  cout << "input operator: ";
  cin >> input_operator;
  if (input_operator == "+") {input_case = 0;}
  else if (input_operator == "-") {input_case = 1;}
  else if (input_operator == "*") {input_case = 2;}
  else if(input_operator == ">>") {input_case = 3;}
  else if (input_operator == "=") {input_case = -1;}
}

void executeOperator(Complex& complex1, Complex& complex2, int input_case, int& last_case)
{
  switch (input_case)
  {
  case 0:
    complex2.inputComplex(true);
    add:
    complex1 = complex1 + complex2;
    last_case = 0;
    break;
  case 1:
    complex2.inputComplex(true);
    sub:
    complex1 = complex1 - complex2;
    last_case = 1;
    break;
  case 2:
    complex2.inputComplex(true);
    mul:
    complex1 = complex1 * complex2;
    last_case = 2;
    break;
  case 3:
    pol:
    printPolar(complex1);
    last_case = 3;
    break;
  case -1:
    if (last_case == 0) {goto add;}
    else if (last_case == 1) {goto sub;}
    else if (last_case == 2) {goto mul;}
    else if (last_case == 3) {goto pol;}
  }
}