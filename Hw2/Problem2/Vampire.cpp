#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vampire.h"

using namespace std;

Vampire::Vampire(int id): Role(80, 25, 15, 7)
{
  srand(time(nullptr));
  this->id = id;
  lifeSteal = static_cast<float>(rand() % 11) / 10.0;
  hpSteal = lifeSteal * Role::getHp();
}

Vampire::~Vampire()
{

}

void Vampire::showInfo()
{
  cout << "Player " << id << ": Vampire" << endl;
  Role::showInfo();
  cout << "Life Steal: " << lifeSteal << endl;
  cout << endl;
}

int Vampire::Attack()
{
  return Role::getAttack();
}

float Vampire::hp_Steal()
{
  return hpSteal;
}

const char* Vampire::_S(int id, int row)
{
  return (id == 1) ? S1[row] : S2[row];
}

const char* Vampire::_LA(int id, int row)
{
  return (id == 1) ? LA1[row] : LA2[row];
}

const char* Vampire::_SA(int id, int row)
{
  return (id == 1) ? SA1[row] : SA2[row];
}

const char* Vampire::_D(int id, int row)
{
  return (id == 1) ? D1[row] : D2[row];
}