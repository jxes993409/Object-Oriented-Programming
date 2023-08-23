#ifndef _E3_H_
#define _E3_H_

#include <vector>
#include <string>

using namespace std;

class Personnel;
class Student;
class Teacher;
class TA;
class Course;

class E3
{
  vector<Personnel*> personnels;
  vector<Student*> students;
  vector<Teacher*> teachers;
  vector<TA*> TAs;
  vector<Course*> courses;
  private:
    void spilt(vector<string>&, string, string);
  public:
    ~E3();
    void importPersonnelsFromCsv(string csvFilename);
    void importCoursesFromCsv(string csvFilename);
    void printAllPersonnel();
    void printAllCourse();
};

#endif