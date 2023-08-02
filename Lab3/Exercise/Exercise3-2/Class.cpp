#include <iostream>
#include <algorithm>
#include "Class.h"

bool sorted_byID(Student x, Student y)
{
  return (x.student_id < y.student_id);
}

Class::Class()
{

}

Class::Class(const Class &old_class)
{
  students = old_class.students;
  class_size = old_class.class_size;
  passing_score = old_class.passing_score;
}

void Class::initialize()
{
  int input_classsize, input_passscore;
  cout << "Number of students: ";
  cin >> input_classsize;
  cout << "Set Passing Score: ";
  cin >> input_passscore;
  set_class_size(input_classsize);
  set_passing_score(input_passscore);
  students = new Student [class_size];
  set_students(students);
}

void Class::students_info()
{
  sort(students, students + class_size, sorted_byID);
  for (int i = 0; i < class_size; i++)
  {
    cout << students[i].name << "\t" << students[i].student_id << "\t" << students[i].score << endl;
  }
  cout << endl;
}

void Class::score_info()
{
  cout << "Average Score: " << find_average() << endl;
  cout << "Median Score: " << find_median() << endl;
  cout << "Fail Student Number: " << find_fail() << endl;
  cout << endl;
}

void Class::set_passing_score(int score)
{
  passing_score = score;
}

void Class::set_score(string stu_name, int score)
{
  int index;
  index = find_student(stu_name);
  if (index == -1)
  {
    cout << "student doesn't exist!" << endl;
  }
  else
  {
    students[index].score = score;
  }
}

void Class::add_student(Student new_stu)
{
  Student *temp_stu = new Student [++class_size];
  for (int i = 0; i < class_size - 1; i++)
  {
    temp_stu[i] = students[i];
  }
  delete [] students;
  students = temp_stu;
  students[class_size - 1] = new_stu;
}

void Class::remove_student(string stu_name)
{
  int index;
  index = find_student(stu_name);
  if (index == -1)
  {
    cout << "student doesn't exist!" << endl;
  }
  else
  {
    Student *temp_stu = new Student [--class_size];
    bool flag = false;
    for (int i = 0; i < class_size + 1; i++)
    {
      if (i == index)
      {
        flag = true;
        continue;
      }
      if (flag)
      {
        temp_stu[i - 1] = students[i];
      }
      else
      {
        temp_stu[i] = students[i];
      }
    }
    delete [] students;
    students = temp_stu;
  }
}

void Class::set_class_size(int size)
{
  class_size = size;
}

void Class::set_students(Student *stu)
{
  for (int i = 0; i < class_size; i++)
  {
    cout << "Student Name: ";
    cin >> stu[i].name;
    cout << "Student ID: ";
    cin >> stu[i].student_id;
    cout << "Score: ";
    cin >> stu[i].score;
  }
}

int Class::find_student(string stu_name)
{
  int index = -1;
  for (int i = 0; i < class_size; i++)
  {
    if (stu_name == students[i].name)
    {
      index = i;
      break;
    }
  }
  return index;
}

double Class::find_average()
{
  double sum = 0, average;
  for (int i = 0; i < class_size; i++)
  {
    sum += students[i].score;
  }
  average = sum / class_size;
  return average;
}

double Class::find_median()
{
  double median;
  int *score_arr = new int [class_size];
  for (int i = 0; i < class_size; i++)
  {
    score_arr[i] = students[i].score;
  }
  sort(score_arr, score_arr + class_size);
  median = class_size % 2 ? score_arr[class_size / 2] : (score_arr[class_size / 2] + score_arr[class_size / 2 - 1]) / 2;
  delete [] score_arr;
  return median;
}

int Class::find_fail()
{
  int count = 0;
  for (int i = 0; i < class_size; i++)
  {
    if (students[i].score < passing_score)
    {
      count++;
    }
  }
  return count;
}