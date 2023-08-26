#include <iostream>
#include <iomanip>
#include "Mage.h"
#include "Warrior.h"
#include "Vampire.h"

using namespace std;

int choose_role(int);
void output(Role*, Role*, int, int, bool);
void output_hp(Role*, Role*);
int choose_moves();
int compute_hp(Role*, Role*, int);

int main()
{
  Role* P1;
  Role* P2;

  int option = choose_role(1);
  if (option == 1) {P1 = new Mage(1);}
  else if (option == 2) {P1 = new Warrior(1);}
  else {P1 = new Vampire(1);}

  option = choose_role(2);
  if (option == 1) {P2 = new Mage(2);}
  else if (option == 2) {P2 = new Warrior(2);}
  else {P2 = new Vampire(2);}

  P1->showInfo();
  P2->showInfo();

  bool first = P1->getSpeed() > P2->getSpeed();
  for (int i = 1;; i++)
  {
    int option, state;
    if (!first)
    {
      P2->setDefense(1);
      // Player 2
      cout << "Round: " << i << endl;
      cout << "player 2's turn" << endl;
      output(P1, P2, 2, 0, P1->getisDefense());
      output_hp(P1, P2);

      option = choose_moves();
      P2->setDefense(option);

      output(P1, P2, 2, option, P1->getisDefense());
      state = compute_hp(P1, P2, 2);
      if (state)
      {
        state == 1 ? cout << "Player 1 lose" : cout << "Player 2 lose";
        cout << endl;
        break;
      }
      // Player 1
      cout << "Round: " << i << endl;
      cout << "player 1's turn" << endl;
      output(P1, P2, 1, 0, P2->getisDefense());
      output_hp(P1, P2);

      option = choose_moves();
      P1->setDefense(option);

      output(P1, P2, 1, option, P2->getisDefense());
      state = compute_hp(P1, P2, 1);
      if (state)
      {
        state == 1 ? cout << "Player 1 lose" : cout << "Player 2 lose";
        cout << endl;
        break;
      }
    }
    else
    {
      // Player 1
      P1->setDefense(1);
      cout << "Round: " << i << endl;
      cout << "player 1's turn" << endl;
      output(P1, P2, 1, 0, P2->getisDefense());
      output_hp(P1, P2);

      option = choose_moves();
      P1->setDefense(option);

      output(P1, P2, 1, option, P2->getisDefense());
      state = compute_hp(P1, P2, 1);
      if (state)
      {
        state == 1 ? cout << "Player 1 lose" : cout << "Player 2 lose";
        cout << endl;
        break;
      }
      // Player 2
      cout << "Round: " << i << endl;
      cout << "player 2's turn" << endl;
      output(P1, P2, 2, 0, P1->getisDefense());
      output_hp(P1, P2);

      option = choose_moves();
      P2->setDefense(option);

      output(P1, P2, 2, option, P1->getisDefense());
      state = compute_hp(P1, P2, 2);
      if (state)
      {
        state == 1 ? cout << "Player 1 lose" : cout << "Player 2 lose";
        cout << endl;
        break;
      }
    }
  }
  delete P1;
  delete P2;
  return 0;
}

int choose_role(int i)
{
  cout << "Player " << i << " choose role:" << endl;
  cout << "1. Mage" << endl;
  cout << "2. Warrior" << endl;
  cout << "3. Vampire" << endl;
  int option;
  cin >> option;
  return option;
}

void output(Role* P1, Role* P2, int turn, int option, bool isDefense)
{
  if (option == 0 && isDefense == false)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_S(1, i) << "        " << P2->_S(2, i) << endl;
    }
  }
  else if (turn == 1 && option == 0 && isDefense == true)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_S(1, i) << "       " << P2->_D(2, i) << endl;
    }
  }
  else if (turn == 2 && option == 0 && isDefense == true)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_D(1, i) << "       " << P2->_S(2, i) << endl;
    }
  }
  else if (turn == 1 && option == 1 && isDefense == true)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "          " << P1->_SA(1, i) << " " << P2->_D(2, i) << endl;
    }
  }
  else if (turn == 1 && option == 1 && isDefense == false)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "          " << P1->_LA(1, i) << P2->_S(2, i) << endl;
    }
  }
  else if (turn == 1 && option == 2&& isDefense == true)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_D(1, i) << "     " << P2->_D(2, i) << endl;
    }
  }
  else if (turn == 1 && option == 2&& isDefense == false)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_D(1, i) << "       " << P2->_S(2, i) << endl;
    }
  }
  else if (turn == 2 && option == 1 && isDefense == true)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_D(1, i) << " " << P2->_SA(2, i) << endl;
    }
  }
  else if (turn == 2 && option == 1 && isDefense == false)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_S(1, i) << P2->_LA(2, i) << endl;
    }
  }
  else if (turn == 2 && option == 2 && isDefense == true)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_D(1, i) << "        " << P2->_D(2, i) << endl;
    }
  }
  else if (turn == 2 && option == 2 && isDefense == false)
  {
    for (int i = 0; i < 5; i++)
    {
      cout << "      " << P1->_S(1, i) << "       " << P2->_D(2, i) << endl;
    }
  }
}

void output_hp(Role* P1, Role* P2)
{
  cout <<  "     p1:" << setw(4) << P1->getHp() << "      p2:" << setw(4) << P2->getHp() << endl;
}

int choose_moves()
{
  cout << "1. Attack" << endl;
  cout << "2. Defense" << endl;
  int option;
  cin >> option;
  return option;
}

int compute_hp(Role* P1, Role* P2, int turn)
{
  if (turn == 1)
  {
    int Damage;
    if (P1->getisDefense()) {Damage = 0;}
    else
    {
      if (P2->getisDefense()) {Damage = ((P1->Attack() - P2->getDefense()) > 0) ?  P1->Attack() - P2->getDefense() : 0;}
      else {Damage = P1->Attack();}
      Damage == 0 ? cout << "0 Damage" : cout << "";
      cout << endl;
      P2->setHp(Damage + P1->magic_Attack());
    }
    P2->setHp(P1->hp_Steal());
    P1->setHp(-P1->hp_Steal());
  }
  else if (turn == 2)
  {
    int Damage;
    if (P2->getisDefense()) {Damage = 0;}
    else
    {
      if (P1->getisDefense()) {Damage = ((P2->Attack() - P1->getDefense()) > 0) ?  P2->Attack() - P1->getDefense() : 0;}
      else {Damage = P2->Attack();}
      Damage == 0 ? cout << "0 Damage" : cout << "";
      cout << endl;
      P1->setHp(Damage + P2->magic_Attack());
    }
    P1->setHp(P2->hp_Steal());
    P2->setHp(-P2->hp_Steal());
  }
  if (P1->getHp() > 0 && P2->getHp() > 0) {return 0;}
  else if (P1->getHp() <= 0 && P2->getHp() > 0) {return 1;}
  else {return 2;}
}