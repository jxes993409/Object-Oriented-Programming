#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include "Personnel.h"

class Course;

class Student: public virtual Personnel
{
  protected:
    string degree;
    int tuition;
    vector<Course*> attendedCourses;
  public:
    Student(string id, string name, string email, string password, string degree, int tuition);
    void printInfo();
    void addAttendCourse(Course* course);
    string getDegree();
    int getTuition();
};

#endif