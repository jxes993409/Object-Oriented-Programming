#include <iostream>
#include <string>

typedef struct person_t
{
  std::string name;
  unsigned age;
} person;

void printInfo(person p)
{
  std::cout << "Name: " << p.name << " | Age: " << p.age << std::endl;
}
int main()
{
  person p = {"Janet", 20};
  printInfo(p);
  return 0;
}