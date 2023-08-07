#ifndef _GRID_H_
#define _GRID_H_

class Grid
{
  private:
    bool isMine = false; // Indicate if the grid is a mine
    bool isOpen = false; // Indicate if the grid is opened
    bool isExplode = false; // Indicate if the mine is explode
    int mineCount = 0; // The neighbor mine count
    static int gridOpenCount; // The number of opened grid
  public:
    // Setters
    void setMine(); // Set isMine to true
    void setExplode(); // Set isExplode to true
    void setMineCount(int mineCount); // Set mine count
    void open(); // Set the grid to open
    // Getters
    bool getIsMine(); // Get isMine
    bool getIsOpen(); // Get isOpen
    int getMineCount(); // Get mineCount
    // Static
    // Get gridOpenCount static variable.
    static int getGridOpenCount();
    // Render
    // Render the grid by checking the grid status.
    // If the grid is not opened, render the blank icon.
    // If the grid is opened and the mineCount is 0, render 2 spaces
    // If the grid contains mine, is opened, and is exploded, render
    // the exploded icon.
    // If the grid contains mine, is opened, and is not exploded,
    // render the bomb icon.
    void render();
    void resetGridOpenCount();
};

#endif