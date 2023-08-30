#ifndef _GROUP_H_
#define _GROUP_H_

#include "Student.h"

class Group
{
  private:
    vector<Student> students;
    int student_num;

    int sum_score_Calculus;
    int high_Calculus;
    int low_Calculus;

    int sum_score_English;
    int high_English;
    int low_English;

    int sum_score_Physics;
    int high_Physics;
    int low_Physics;
  public:
    Group();
    ~Group();
    void addStudent(Student);
    void removeStudentByID(string);
    void removeStudentByName(string);
    void gradeDistribution();
    // print out Avg, Max, Min Score of each subject
    // add any function you need
    void studentInfo(int);
    void calculateScore();
};

#endif