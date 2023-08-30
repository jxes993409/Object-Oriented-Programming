#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Group.h"

bool sortedbyID(const Student& s1, const Student& s2)
{
  return s1.getId() < s2.getId();
}

bool sortedbyName(const Student& s1, const Student& s2)
{
  return s1.getName() < s2.getName();
}

Group::Group()
{

}

Group::~Group()
{

}

void Group::addStudent(Student s)
{
  students.push_back(s);
}

void Group::removeStudentByID(string id)
{
  for (int i = 0; i < static_cast<int>(students.size()); i++)
  {
    if (students[i].getId() == id)
    {
      students.erase(students.begin() + i);
      cout << "Remove Successfully" << endl;
      return;
    }
  }
  cout << "Student doesn't exist" << endl;
}

void Group::removeStudentByName(string name)
{
  for (int i = 0; i < static_cast<int>(students.size()); i++)
  {
    if (students[i].getName() == name)
    {
      students.erase(students.begin() + i);
      cout << "Remove Successfully" << endl;
      return;
    }
  }
  cout << "Student doesn't exist" << endl;
}

void Group::gradeDistribution()
{
  calculateScore();
  cout << fixed << setprecision(2);
  cout << "Student Num: " << student_num << endl;
  cout << "<Calculus>" << endl;
  cout << "Avg: " << static_cast<double>(sum_score_Calculus) / student_num << endl;
  cout << "Max: " << high_Calculus << endl;
  cout << "Min: " << low_Calculus << endl;
  cout << "<English>" << endl;
  cout << "Avg: " << static_cast<double>(sum_score_English) / student_num << endl;
  cout << "Max: " << high_English << endl;
  cout << "Min: " << low_English << endl;
  cout << "<Physics>" << endl;
  cout << "Avg: " << static_cast<double>(sum_score_Physics) / student_num << endl;
  cout << "Max: " << high_Physics << endl;
  cout << "Min: " << low_Physics << endl;
  cout << endl;
  cout.unsetf(ios::fixed);
}

void Group::studentInfo(int mode)
{
  if (mode == 1) {sort(students.begin(), students.end(), sortedbyID);}
  else if (mode == 2) {sort(students.begin(), students.end(), sortedbyName);}
  student_num = students.size();
  cout << "Student Num: " << student_num << endl;
  for (int i = 0; i < student_num; i++)
  {
    cout << "<Student " << i + 1 << "> ";
    cout << students[i] << endl;
  }
}

void Group::calculateScore()
{
  student_num = students.size();

  sum_score_Calculus = 0;
  high_Calculus = 0;
  low_Calculus = 100;

  sum_score_English = 0;
  high_English = 0;
  low_English = 100;

  sum_score_Physics = 0;
  high_Physics = 0;
  low_Physics = 100;
  
  for (int i = 0; i < student_num; i++)
  {
    int Calculus_score = students[i].getScore()[0];
    int English_score = students[i].getScore()[1];
    int Physics_score = students[i].getScore()[2];

    sum_score_Calculus += Calculus_score;
    high_Calculus = (high_Calculus < Calculus_score) ? Calculus_score : high_Calculus;
    low_Calculus = (low_Calculus > Calculus_score) ? Calculus_score : low_Calculus;

    sum_score_English += English_score;
    high_English = (high_English < English_score) ? English_score : high_English;
    low_English = (low_English > English_score) ? English_score : low_English;


    sum_score_Physics += Physics_score;
    high_Physics = (high_Physics < Physics_score) ? Physics_score : high_Physics;
    low_Physics = (low_Physics > Physics_score) ? Physics_score : low_Physics;
  }
}