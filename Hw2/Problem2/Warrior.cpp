#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(int id): Role(120, 30, 20, 10)
{
  srand(time(nullptr));
  this->id = id;
  critRate = static_cast<float>(rand() % 11) / 10.0;
}

Warrior::~Warrior()
{

}

int Warrior::Attack()
{
  if (rand() % 100 < critRate * 100)
  {
    return 2 * Role::getAttack();
  }
  return Role::getAttack();
}

void Warrior::showInfo()
{
  cout << "Player " << id << ": Warrior" << endl;
  Role::showInfo();
  cout << "Crit Rate: " << critRate << endl;
  cout << endl;
}

const char* Warrior::_S(int id, int row)
{
  return (id == 1) ? S1[row] : S2[row];
}

const char* Warrior::_LA(int id, int row)
{
  return (id == 1) ? LA1[row] : LA2[row];
}

const char* Warrior::_SA(int id, int row)
{
  return (id == 1) ? SA1[row] : SA2[row];
}

const char* Warrior::_D(int id, int row)
{
  return (id == 1) ? D1[row] : D2[row];
}