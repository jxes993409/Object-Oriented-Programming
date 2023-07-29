#include<iostream>
#include<string>

typedef struct person_t
{
  std::string name;
  unsigned age;
  void printInfo()
  {
  std::cout << "Name: " << name << " | Age: " << age << std::endl;
  }
} person;

int main()
{
  person p = {"Janet", 20};
  p.printInfo();
  return 0;
}