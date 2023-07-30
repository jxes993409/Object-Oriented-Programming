#include <iostream>

struct student
{
  std::string name;
  int mathScore;
  int chineseScore;
};

int main()
{
  struct student students[3] =
  {
    {.name = "Bob", .mathScore = 100, .chineseScore = 90},
    {.name = "Alice", .mathScore = 59, .chineseScore = 59},
    {.name = "John", .mathScore = 87, .chineseScore = 87},
  };
  for (int i = 0; i < 3; i++)
  {
    std::cout << "studentName: " << students[i].name << std::endl;
    std::cout << "\t math score: " << students[i].mathScore << std::endl;
    std::cout << "\t chinese score: " << students[i].chineseScore << std::endl;
  }
  return 0;
}
