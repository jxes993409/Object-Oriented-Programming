#ifndef _TEACHER_H_
#define _TEACHER_H_

#include <vector>
#include "Personnel.h"

class Course;

class Teacher: public virtual Personnel
{
  protected:
    int salary;
    vector<Course*> taughtCourses;
  public:
    Teacher(string id, string name, string email, string password, int salary);
    void printInfo();
    void addTaughtCourse(Course* course);
};

#endif