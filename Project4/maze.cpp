////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#include "maze.h"

using std::cout;

maze::maze(int r, int c)
{
    //set the row and cell data
    row = r;
    col = c;

    //populate the first cell
    theMaze.push_back(mazeCell(false, true, false, true));
    //populate the maze
    for (int i = 1; i < (r * c) - 1; i++)
    {
        theMaze.push_back(mazeCell());
    }
    //populate the last cell
    theMaze.push_back(mazeCell(true, false, true, false));
}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const
{
    //if neigh is above cell
    if(neigh == (cell - col))
    {
        return true;
    }
    //if neigh is below cell
    if(neigh == (cell + col))
    {
        return true;
    }
    //if neigh is to the right of cell and cell is not on the rightmost side
    if(neigh == cell + 1 && neigh % col != 0)
    {
        return true;
    }
    //if neigh is to the left of cell and cell is not on the leftmost side
    if(neigh == cell - 1 && cell % col != 0)
    {
        return true;
    }
    //otherwise, return false
    else
    {
        return false;
    }
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall (int cell, int neigh)
{
    //if the cells are neighbors, continue
    if (neighbors(cell, neigh) == true)
    {
        //smash the right wall
        if (cell + 1 == neigh)
        {
            theMaze[cell].setRight(false);
        }
        //smash the left wall
        else if (cell - 1 == neigh)
        {
            theMaze[cell].setLeft(false);
        }
        //smash the bottom wall
        else if(neigh == cell + col)
        {
            theMaze[cell].setBot(false);
        }
        //smash the top wall
        else if(neigh == cell - col)
        {
            theMaze[cell].setTop(false);
        }
    }
}

//print the maze
void maze::printMaze()
{
    //output the top line
    cout << "  ";
    for (int i = 0; i < col - 1; i++)
    {
        cout << " _";
    }
    cout << "\n";

    //loop through the rest of the maze and output
    for (int i = 0; i < theMaze.size(); i++)
    {
        //output the rightmost wall and move down a line
        if (i % col == 0 && i != 0)
        {
            cout << "|\n";
        }
        //output every left wall as long as it has not been smashed
        if (theMaze[i].getLeft() == true)
        {
            cout << "|";
        }
        //otherwise replace it with a space
        else
        {
            cout << " ";
        }
        //output the bottom wall as long as it has not been smashed
        if (theMaze[i].getBot() == true)
        {
            cout << "_";
        }
        //otherwise replace it with a space
        else
        {
            cout << " ";
        }

    }
    //add an extra line at the end to make things easier to read
    cout << "\n";
}
