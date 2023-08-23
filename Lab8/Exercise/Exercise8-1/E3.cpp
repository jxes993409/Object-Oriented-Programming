#include <fstream>
#include <iostream>

#include "Personnel.h"
#include "Student.h"
#include "Teacher.h"
#include "TA.h"
#include "Course.h"
#include "E3.h"

E3::~E3()
{
  // delete pe
  for (Personnel* pe: personnels)
  {
    delete pe;
  }
  // delete Student
  for (Student* stu: students)
  {
    delete stu;
  }
  // delete Teacher
  for (Teacher* tea: teachers)
  {
    delete tea;
  }
  // delete TA
  for (TA* ta: TAs)
  {
    delete ta;
  }
  // delete Course
  for (Course* cou: courses)
  {
    delete cou;
  }
}

void E3::importPersonnelsFromCsv(string csvFilename)
{
  ifstream ifs(csvFilename, ios::in);
  string str;
  vector<string> str_vec;
  getline(ifs, str);
  while (getline(ifs, str))
  {
    spilt(str_vec, str, ",");
  }
  int personal_count = str_vec.size() / 8;
  for (int i = 0; i < personal_count; i++)
  {
    int index = 8 * i;
    Personnel* push_personnel = new Personnel(str_vec[index + 0], str_vec[index + 1], str_vec[index + 2], str_vec[index + 3]);
    personnels.push_back(push_personnel);
    if (str_vec[index + 4] == "Student")
    {
      Student* push_student = new Student(str_vec[index + 0], str_vec[index + 1], str_vec[index + 2], str_vec[index + 3], str_vec[index + 5], stoi(str_vec[index + 6]));
      students.push_back(push_student);
    }
    else if (str_vec[index + 4] == "TA")
    {
      TA* push_TA = new TA(str_vec[index + 0], str_vec[index + 1], str_vec[index + 2], str_vec[index + 3], str_vec[index + 5], stoi(str_vec[index + 6]), stoi(str_vec[index + 7]));
      TAs.push_back(push_TA);
    }
    else
    {
      Teacher* push_Teacher = new Teacher(str_vec[index + 0], str_vec[index + 1], str_vec[index + 2], str_vec[index + 3], stoi(str_vec[index + 7]));
      teachers.push_back(push_Teacher);
    }
  }
  ifs.close();
}

void E3::importCoursesFromCsv(string csvFilename)
{
  ifstream ifs(csvFilename, ios::in);
  string str;
  vector<string> str_vec;
  getline(ifs, str);
  while (getline(ifs, str))
  {
    spilt(str_vec, str, ",");
  }
  int course_count = str_vec.size() / 5;
  for (int i = 0; i < course_count; i++)
  {
    int index = 5 * i;
    // add teacher's info
    for (Teacher* t: teachers)
    {
      if (str_vec[index + 2] == t->Personnel::getId())
      {
        Course* push_course = new Course(str_vec[index + 0], str_vec[index + 1], t);
        t->addTaughtCourse(push_course);
        courses.push_back(push_course);
      }
    }
    // add ta's info
    vector<string> ta_vec;
    spilt(ta_vec, str_vec[index + 3], "|");
    for (TA* ta: TAs)
    {
      for (string ta_id: ta_vec)
      {
        if (ta_id == ta->Personnel::getId())
        {
          courses[i]->addTA(ta);
          ta->addTaughtCourse(courses[i]);
        }
      }
    }
    // add student's info
    vector<string> stu_vec;
    spilt(stu_vec, str_vec[index + 4], "|");
    for (TA* ta: TAs)
    {
      for (string ta_id: stu_vec)
      {
        if (ta_id == ta->Personnel::getId())
        {
          courses[i]->addStudent(ta);
          ta->Student::addAttendCourse(courses[i]);
        }
      }
    }
    for (Student* stu: students)
    {
      for (string stu_id: stu_vec)
      {
        if (stu_id == stu->Personnel::getId())
        {
          courses[i]->addStudent(stu);
          stu->addAttendCourse(courses[i]);
        }
      }
    }
  }
  ifs.close();
}

void E3::printAllPersonnel()
{
  for (auto p: personnels)
  {
    p->printInfo();
    cout << endl;
  }
}

void E3::printAllCourse()
{
  for (auto c: courses)
  {
    c->printInfo();
  }
}

void E3::spilt(vector<string>& str_vec, string str, string tok)
{
  int current = 0;
  int next;
  while (true)
  {
    next = str.find_first_of(tok, current);

    string temp;
    temp = str.substr(current, next - current);
    str_vec.push_back(temp);

    if (next == static_cast<int>(string::npos)) {break;}
    current = next + 1;
  }
}