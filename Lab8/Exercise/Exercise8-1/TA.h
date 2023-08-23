#ifndef _TA_H_
#define _TA_H_

#include "Student.h"
#include "Teacher.h"

class TA: public Student, public Teacher
{
  private:
  public:
    TA(string id, string name, string email, string password, string degree, int tuition, int salary);
    void printInfo();
};

#endif