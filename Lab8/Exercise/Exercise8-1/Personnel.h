#ifndef _PERSONNEL_H_
#define _PERSONNEL_H_

#include <string>

using namespace std;

class Personnel
{
  private:
    string id;
    string name;
    string email;
    string password;
  public:
    Personnel();
    Personnel(string id, string name, string email, string password);
    virtual ~Personnel() = default;
    void printInfo(); // output id, name and email
    string getId();
};

#endif