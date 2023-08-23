#include <iostream>
#include "Teacher.h"
#include "Student.h"
#include "TA.h"
#include "Course.h"

Course::Course(string id, string name, Teacher* teacher)
{
  this->id = id;
  this->name = name;
  this->teacher = teacher;
}

void Course::addTA(TA* ta)
{
  TAs.push_back(ta);
}

void Course::addStudent(Student* student)
{
  students.push_back(student);
}

void Course::printInfo()
{
  cout << "id: " << id << "\t" << "Name: " << name << endl;
  cout << "Teacher: " << endl;
  cout << "\t"; teacher->Personnel::printInfo();
  // output salary and taught course
  teacher->printInfo();
  cout << "TAs: " << endl;
  for (TA* ta: TAs)
  {
    cout << "\t";
    ta->Personnel::printInfo();
    // output salary and taught course
    ta->printInfo();
  }
  cout << "Students: " << endl;
  for (Student* stu: students)
  {
    cout << "\t"; stu->Personnel::printInfo();
    cout << "\t Degree: " << stu->getDegree() << "\tTuition: " << stu->getTuition() << endl;
    // output attend course
    stu->printInfo();
  }
}

string Course::getName()
{
  return '"' + name + '"';
}