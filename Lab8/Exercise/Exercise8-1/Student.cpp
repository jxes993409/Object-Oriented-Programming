#include <iostream>
#include "Student.h"
#include "Course.h"

Student::Student(string id, string name, string email, string password, string degree, int tuition): Personnel(id, name, email, password)
{
  this->degree = degree;
  this->tuition = tuition;
}

void Student::printInfo()
{
  cout << "\t" << "Attend Courses: ";
  for (Course* c: attendedCourses)
  {
    cout << c->getName() << " ";
  }
  cout << endl << endl;
}

void Student::addAttendCourse(Course* course)
{
  attendedCourses.push_back(course);
}

string Student::getDegree()
{
  return degree;
}

int Student::getTuition()
{
  return tuition;
}