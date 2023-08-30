#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <vector>

using namespace std;

class Student
{
  private:
    string id;
    string name;
    vector<int> Scores; // store 3 score {Calculus, English, Physics}
  public:
    Student(string, string, vector<int>); // (ID, Name, Scores)
    ~Student();
    friend ostream& operator <<(ostream &out, const Student s);
    // add any function you need
    string getId() const;
    string getName() const;
    vector<int>& getScore();
};

#endif