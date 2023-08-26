#include <iostream>
#include "Role.h"

using namespace std;

Role::Role()
{

}

Role::Role(int hp, int attack, int defense, int speed): hp(hp), attack(attack), defense(defense), speed(speed)
{
  isDefense = false;
}

Role::~Role()
{
  
}

int Role::Attack()
{
  return 0;
}

int Role::magic_Attack()
{
  return 0;
}

float Role::hp_Steal()
{
  return 0;
}

void Role::showInfo()
{
  cout << "HP: " << hp << endl;
  cout << "Attack: " << attack << endl;
  cout << "Defense: " << defense << endl;
  cout << "Speed: " << speed << endl;
}

int Role::getHp()
{
  return hp;
}

int Role::getAttack()
{
  return attack;
}

int Role::getDefense()
{
  return defense;
}

int Role::getSpeed()
{
  return speed;
}

bool Role::getisDefense()
{
  return isDefense;
}

void Role::setHp(int Damage)
{
  hp -= Damage;
}

void Role::setDefense(int option)
{
  isDefense = (option == 2) ? true : false;
}

const char* Role::_S(int id, int row)
{
  return nullptr;
}

const char* Role::_LA(int id, int row)
{
  return nullptr;
}

const char* Role::_SA(int id, int row)
{
  return nullptr;
}

const char* Role::_D(int id, int row)
{
  return nullptr;
}