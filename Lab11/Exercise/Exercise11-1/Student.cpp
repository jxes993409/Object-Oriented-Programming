#include <iostream>
#include "Student.h"

Student::Student(string id, string name, vector<int> Scores): id(id), name(name), Scores(Scores)
{

}

Student::~Student()
{

}

ostream& operator <<(ostream& os, const Student s)
{
  os << "ID: " << s.id << ", Name: " << s.name << endl;
  os << "Scores >" << endl;
  os << "\tCalculus: " << s.Scores[0] << endl;
  os << "\tEnglish: " << s.Scores[1] << endl;
  os << "\tPhysics: " << s.Scores[2] << endl;
  return os;
}

string Student::getId() const
{
  return id;
}

string Student::getName() const
{
  return name;
}

vector<int>& Student::getScore()
{
  return Scores;
}