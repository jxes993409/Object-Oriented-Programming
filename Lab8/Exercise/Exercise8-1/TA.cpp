#include <iostream>
#include "TA.h"

TA::TA(string id, string name, string email, string password, string degree, int tuition, int salary):
Personnel(id, name, email, password),
Student(id, name, email, password, degree, tuition),
Teacher(id, name, email, password, salary)
{
}

void TA::printInfo()
{
  Teacher::printInfo();
  Student::printInfo();
}