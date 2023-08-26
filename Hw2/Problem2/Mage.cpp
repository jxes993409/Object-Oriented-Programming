#include <iostream>
#include "Mage.h"

using namespace std;

Mage::Mage(int id): Role(100, 10, 10, 5)
{
  this->id = id;
  magicAttack = 30;
}

Mage::~Mage()
{

}

int Mage::Attack()
{
  return Role::getAttack();
}

int Mage::magic_Attack()
{
  return magicAttack;
}

void Mage::showInfo()
{
  cout << "Player " << id << ": Mage" << endl;
  Role::showInfo();
  cout << "Magic Attack: " << magicAttack << endl;
  cout << endl;
}

const char* Mage::_S(int id, int row)
{
  return (id == 1) ? S1[row] : S2[row];
}

const char* Mage::_LA(int id, int row)
{
  return (id == 1) ? LA1[row] : LA2[row];
}

const char* Mage::_SA(int id, int row)
{
  return (id == 1) ? SA1[row] : SA2[row];
}

const char* Mage::_D(int id, int row)
{
  return (id == 1) ? D1[row] : D2[row];
}