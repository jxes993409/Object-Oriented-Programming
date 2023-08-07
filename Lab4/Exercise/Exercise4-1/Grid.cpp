#include <iostream>
#include <iomanip>
#include "Grid.h"

using namespace std;

int Grid::gridOpenCount = 0;

void Grid::setMine()
{
  isMine = true;
}

void Grid::setExplode()
{
  isExplode = true;
}

void Grid::setMineCount(int mineCount)
{
  Grid::mineCount = mineCount;
}

void Grid::open()
{
  isOpen = true;
  gridOpenCount = gridOpenCount + 1;
}

bool Grid::getIsMine()
{
  return isMine;
}

bool Grid::getIsOpen()
{
  return isOpen;
}

int Grid::getMineCount()
{
  return mineCount;
}

int Grid::getGridOpenCount()
{
  return gridOpenCount;
}

void Grid::render()
{
  if (!getIsOpen())
  {
    cout << "\u2B1C";
  }
  else
  {
    if (getMineCount() == 0 && !getIsMine())
    {
      cout << "  ";
    }
    else if (getIsMine() && isExplode) // (contains mine) is opend and is exploded
    {
      cout << "\U0001F4A5";
    }
    else if (getIsMine() && !isExplode) // (contains mine) is opend and is 'not' exploded
    {
      cout << "\U0001F4A3";
    }
    else
    {
      cout << setw(2) << getMineCount();
    }
  }
}

void Grid::resetGridOpenCount()
{
  gridOpenCount = 0;
}