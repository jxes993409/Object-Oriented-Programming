#include <iostream>
#include "Teacher.h"
#include "Course.h"

Teacher::Teacher(string id, string name, string email, string password, int salary): Personnel(id, name, email, password)
{
  this->salary = salary;
}

void Teacher::printInfo()
{
  cout << "\tSalary: " << salary << endl;
  cout << "\t" << "Taught Courses: ";
  for (Course* course: taughtCourses)
  {
    cout << course->getName() << " ";
  }
  cout << endl;
}

void Teacher::addTaughtCourse(Course* course)
{
  taughtCourses.push_back(course);
}