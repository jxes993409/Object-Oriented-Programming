#include <iostream>
#include "EEE.h"

EEE::EEE()
{

}

EEE::~EEE()
{

}

void EEE::addStudent(string group_name, Student s)
{
  if (groups.find(group_name) == groups.end())
  {
    Group g;
    groups[group_name] = g;
  }
  groups[group_name].addStudent(s);
}

void EEE::removeStudentByID(string group_name, string id)
{
  if (groups.find(group_name) == groups.end())
  {
    cout << "Group doesn't exist" << endl;
    return;
  }
  groups[group_name].removeStudentByID(id);
}

void EEE::removeStudentByName(string group_name, string name)
{
  if (groups.find(group_name) == groups.end())
  {
    cout << "Group doesn't exist" << endl;
    return;
  }
  groups[group_name].removeStudentByName(name);
}

void EEE::gradeDistribution(string group_name)
{
  if (groups.find(group_name) == groups.end())
  {
    cout << "Group doesn't exist" << endl;
    return;
  }
  groups[group_name].gradeDistribution();
}

void EEE::viewInfo(string group_name, int mode)
{
  if (groups.find(group_name) == groups.end())
  {
    cout << "Group doesn't exist" << endl;
    return;
  }
  switch (mode)
  {
    case 0:
      groups[group_name].studentInfo(0);
      break;
    case 1:
      groups[group_name].studentInfo(1);
      break;
    case 2:
      groups[group_name].studentInfo(2);
      break;
  }
}