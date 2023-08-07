#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "MineSweeper.h"

using namespace std;

MineSweeper::MineSweeper()
{
  explode = false;
  win = false;
}

MineSweeper::~MineSweeper()
{
  for (int i = 0; i < sizeY; i++)
  {
    delete [] map[i];
    map[i] = NULL;
  }
  delete [] map;
  map = NULL;
}

void MineSweeper::run()
{
  while (true)
  {
    newGame();
    render();
    while (!win && !explode)
    {
      int pressedPosY, pressedPosX;
      cout << "Please enter the coordinate (x, y) you want to press: ";
      cin >> pressedPosY >> pressedPosX;
      openGrid(pressedPosY, pressedPosX);
      checkWin();
      render();
    }
    explode ? cout << "Mine explode! You lose!" << endl : cout << "";
    string choice;
    cout << "Do you want to play another round?(y/n) ";
    cin >> choice;
    if (choice == "y")
    {
      resetVariable();
    }
    else
    {
      break;
    }
  }
}

void MineSweeper::newGame()
{
  createNewMap();
  generateMines();
  countMine();
}

void MineSweeper::createNewMap()
{
  // input width and height
  while (true)
  {
    cout << "Please input map width: ";
    cin >> sizeX;
    cout << "Please input map height: ";
    cin >> sizeY;
    if (sizeX < 1 || sizeY < 1)
    {
      cout << "Input Error!" << endl;
    }
    else
    {
      break;
    }
  }
  map = new Grid *[sizeY];
  for (int i = 0; i < sizeY; i++)
  {
    map[i] = new Grid [sizeX];
  }
  map[0][0].resetGridOpenCount();
}

void MineSweeper::generateMines()
{
  // input mineNum
  while (true)
  {
    cout << "Please input number of mines: ";
    cin >> mineNum;
    if (mineNum < 1 || mineNum > sizeX * sizeY)
    {
      cout << "Input Error!" << endl;
    }
    else
    {
      break;
    }
  }
  int posX, posY;
  // srand(time(NULL));
  int i = 0;
  while (i < mineNum)
  {
    posX = rand() % sizeX;
    posY = rand() % sizeY;
    if (!map[posY][posX].getIsMine())
    {
      i++;
      map[posY][posX].setMine();
    }
  }
}

void MineSweeper::countMine()
{
  for (int posY = 0; posY < sizeY; posY++)
  {
    for (int posX = 0; posX < sizeX; posX++)
    {
      int mineCount = 0;
      if (!map[posY][posX].getIsMine())
      {
        if (sizeY == 1) // only 1 row
        {
          if (posX == 0)
          {
            mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
          }
          else if (posX + 1 == sizeX)
          {
            mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          }
          else
          {
            mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
            mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          }
        }
        else if (sizeX == 1) // only 1 column
        {
          if (posY == 0)
          {
            mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
          }
          else if (posY + 1 == sizeY)
          {
            mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          }
          else
          {
            mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
            mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
          }
        }
        else if (posY == 0 && posX == 0) // the first grid of the 1st row
        {
          mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
          mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
          mineCount = map[posY + 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // bottom right
        }
        else if (posY == 0 && posX + 1 == sizeX) // the last grid of the 1st row
        {
          mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          mineCount = map[posY + 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // bottom left
          mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
        }
        else if (posY == 0) // 1st row of the map
        {
          mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
          mineCount = map[posY + 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // bottom left
          mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
          mineCount = map[posY + 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // bottom right
        }
        else if (posY + 1 == sizeY && posX == 0) // the first grid of the last row
        {
          mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          mineCount = map[posY - 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // upper right
          mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
        }
        else if (posY + 1 == sizeY && posX + 1 == sizeX) // the last grid of the last row
        {
          mineCount = map[posY - 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // upper left
          mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
        }
        else if (posY + 1 == sizeY) // last row of the map
        {
          mineCount = map[posY - 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // upper left
          mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          mineCount = map[posY - 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // upper right
          mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
        }
        else if (posX == 0) // first column of the map
        {
          mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          mineCount = map[posY - 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // upper right
          mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
          mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
          mineCount = map[posY + 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // bottom right
        }
        else if (posX + 1 == sizeX) // last column of the map
        {
          mineCount = map[posY - 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // upper left
          mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          mineCount = map[posY + 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // bottom left
          mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
        }
        else
        {
          mineCount = map[posY - 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // upper left
          mineCount = map[posY - 1][posX].getIsMine() ? mineCount + 1 : mineCount; // upper
          mineCount = map[posY - 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // upper right
          mineCount = map[posY][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // left
          mineCount = map[posY][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // right
          mineCount = map[posY + 1][posX - 1].getIsMine() ? mineCount + 1 : mineCount; // bottom left
          mineCount = map[posY + 1][posX].getIsMine() ? mineCount + 1 : mineCount; // bottom
          mineCount = map[posY + 1][posX + 1].getIsMine() ? mineCount + 1 : mineCount; // bottom right
        }
      }
      map[posY][posX].setMineCount(mineCount);
    }
  }
}

void MineSweeper::openGrid(int pressedPosY, int pressedPosX)
{
  if (isPosValid(pressedPosY, pressedPosX))
  {
    if (map[pressedPosY][pressedPosX].getIsMine()) // mine grid, explode the mines -> lose
    {
      explodeAllMines();
    }
    else if (map[pressedPosY][pressedPosX].getMineCount() == 0) // empty grid (mineCount = 0)
    {
      propagateWhiteSpace(pressedPosY, pressedPosX);
    }
    else // empty grid (mineCount > 0)
    {
      map[pressedPosY][pressedPosX].open();
    }
  }
}

void MineSweeper::propagateWhiteSpace(int pressedPosY, int pressedPosX)
{
  map[pressedPosY][pressedPosX].open();
  // upper left
  if (pressedPosY - 1 >= 0 && pressedPosX - 1 >= 0) 
  {
    if (!map[pressedPosY - 1][pressedPosX - 1].getIsOpen() && !map[pressedPosY - 1][pressedPosX - 1].getIsMine())
    {
      propagateWhiteSpace(pressedPosY - 1, pressedPosX - 1);
    }
  }
  // upper
  if (pressedPosY -1 >= 0) 
  {
    if (!map[pressedPosY - 1][pressedPosX].getIsOpen() && !map[pressedPosY - 1][pressedPosX].getIsMine())
    {
      propagateWhiteSpace(pressedPosY - 1, pressedPosX);
    }
  }
  // upper right
  if (pressedPosY - 1 >= 0 && pressedPosX + 1 != sizeX) 
  {
    if (!map[pressedPosY - 1][pressedPosX + 1].getIsOpen() && !map[pressedPosY - 1][pressedPosX + 1].getIsMine())
    {
      propagateWhiteSpace(pressedPosY - 1, pressedPosX + 1);
    }
  }
  // left
  if (pressedPosX - 1 >= 0)
  {
    if (!map[pressedPosY][pressedPosX - 1].getIsOpen() && !map[pressedPosY][pressedPosX - 1].getIsMine())
    {
      propagateWhiteSpace(pressedPosY, pressedPosX - 1);
    }
  }
  // right
  if (pressedPosX + 1 != sizeX) 
  {
    if (!map[pressedPosY][pressedPosX + 1].getIsOpen() && !map[pressedPosY][pressedPosX + 1].getIsMine())
    {
      propagateWhiteSpace(pressedPosY, pressedPosX + 1);
    }
  }
  // bottom left
  if (pressedPosY + 1 != sizeY && pressedPosX - 1 >= 0)
  {
    if (!map[pressedPosY + 1][pressedPosX - 1].getIsOpen() && !map[pressedPosY + 1][pressedPosX - 1].getIsMine())
    {
      propagateWhiteSpace(pressedPosY + 1, pressedPosX - 1);
    }
  }
  // bottom
  if (pressedPosY + 1 != sizeY)
  {
    if (!map[pressedPosY + 1][pressedPosX].getIsOpen() && !map[pressedPosY + 1][pressedPosX].getIsMine())
    {
      propagateWhiteSpace(pressedPosY + 1, pressedPosX);
    }
  }
  // bottom right
  if (pressedPosY + 1 != sizeY && pressedPosX + 1 != sizeX)
  {
    if (!map[pressedPosY + 1][pressedPosX + 1].getIsOpen() && !map[pressedPosY + 1][pressedPosX + 1].getIsMine())
    {
      propagateWhiteSpace(pressedPosY + 1, pressedPosX + 1);
    }
  }
}

void MineSweeper::revealAllMines()
{
  for (int posX = 0; posX < sizeX; posX++)
  {
    for (int posY = 0; posY < sizeY; posY++)
    {
      map[posY][posX].open();
    }
  }
}

void MineSweeper::explodeAllMines()
{
  explode = true;
  for (int posX = 0; posX < sizeX; posX++)
  {
    for (int posY = 0; posY < sizeY; posY++)
    {
      map[posY][posX].open();
      if (map[posY][posX].getIsMine())
      {
        map[posY][posX].setExplode();
      }
    }
  }
}

void MineSweeper::checkWin()
{
  if (sizeX * sizeY == map[0][0].getGridOpenCount() + mineNum)
  {
    cout << "You Win!" << endl;
    win = true;
    revealAllMines();
  }
}

bool MineSweeper::isPosValid(int posY, int posX)
{
  if (posX < 0 || posX >= sizeX ||
      posY < 0 || posY >= sizeY)
  {
    cout << "Invalid coordinate!" << endl;
    return false;
  }
  else
  {
    return true;
  }
}

void MineSweeper::render()
{
  cout << "   ";
  for (int i = 0; i < sizeX; i++)
  {
    cout << setw(2) << i;
  }
  cout << endl;

  // output --------
  cout << "  -";
  for (int i = 0; i < sizeX; i++)
  {
    cout << "--";
  }
  cout << "-" << endl;
  
  for (int posY = 0; posY < sizeY; posY++)
  {
    cout << setw(2) << posY << "|";
    for (int posX = 0; posX < sizeX; posX++)
    {
      map[posY][posX].render();
    }
    cout << "|" << endl;
  }

  // output --------
  cout << "  -";
  for (int i = 0; i < sizeX; i++)
  {
    cout << "--";
  }
  cout << "-" << endl;
}

void MineSweeper::resetVariable()
{
  explode = false;
  win = false;
  for (int i = 0; i < sizeY; i++)
  {
    delete [] map[i];
    map[i] = NULL;
  }
  delete [] map;
  map = NULL;
}