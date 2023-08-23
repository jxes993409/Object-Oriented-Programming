#include <iostream>
#include "Personnel.h"

Personnel::Personnel()
{
  id = "";
  name = "";
  email = "";
  password = "";
}

Personnel::Personnel(string id, string name, string email, string password)
{
  this->id = id;
  this->name = name;
  this->email = email;
  this->password = password;
}

void Personnel::printInfo()
{
  cout << "id: " << id << "\t" << "Name: " << name << "\t" << "email: " << email;
}

string Personnel::getId()
{
  return id;
}