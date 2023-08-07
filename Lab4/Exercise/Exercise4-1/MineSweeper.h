#ifndef _MINESWEEPER_H_
#define _MINESWEEPER_H_

#include "Grid.h"

class MineSweeper
{
  private:
    int sizeX; // The width of the grid map
    int sizeY; // The height of the grid map
    int mineNum; // The number of mine

    bool explode; // If any mine explode, player lose
    bool win; // If all the empty grid is opened, player win

    Grid **map = nullptr;
  public:
    MineSweeper();
    ~MineSweeper();
    void run(); // The main logic process of the game
  private:
    // Prepare new grid map
    // Ask player for sizeX, sizeY and mineNum. 
    // Then call createNewMap(), generateMines(), and countMine()
    void newGame();
    // Create new 2D grid map (2D Array) 
    void createNewMap();
    // Randomly choose the grid to insert mines, provided by TA. 
    // DO NOT MODIFY!
    void generateMines();
    // Count the number of neighbor grids that contains mine.
    void countMine();

    // In-game interaction
    // Open the selected grid, need to check for the validity of the 
    // input.
    // If the opened grid is mine, explode!
    // If the opened grid’s mineCount is 0, 
    // call propagateWhiteSpace()

    void openGrid(int pressedPosY, int pressedPosX);
    // Propagate the white space recursively.
    // Stop the recursion when the grid contains mine, is already 
    // opened, or its mineCount is not 0
    void propagateWhiteSpace(int pressedPosY, int pressedPosX);
  
    // After game setting
    void revealAllMines();
    void explodeAllMines();

    // Helper functions
 
    // Check if a game is won by comparing the gridOpenCount, grid 
    // map size, and mine count
    void checkWin();
    //Check if a input pos is valid
    bool isPosValid(int posY, int posX);
    // Render
    // Render the grid map
    void render();
    // Reset variable
    void resetVariable();
};

#endif