#ifndef _CLASS_H_
#define _CLASS_H_

#include <string>

using namespace std;

struct Student
{
  string name;
  string student_id;
  int score;
};

class Class
{
  private:
    int class_size;
    int passing_score;
    Student *students;
  public:
    Class();
    Class(const Class &);
    ~Class();
    void initialize();
    void students_info();
    void score_info();
    void set_passing_score(int);
    void set_score(string, int);
    void add_student(Student);
    void remove_student(string);
  private:
    void set_class_size(int);
    void set_students(Student *);
    int find_student(string);
    double find_average();
    double find_median();
    int find_fail();
};


#endif