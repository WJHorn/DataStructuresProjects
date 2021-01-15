////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////
#include "DisjSets.h"
#include "maze.h"
#include "mazeCell.h"

#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

void twoRandom(int & n1, int &n2, int maxN);


int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    //integers to store input from tthe user
    int rows, cols;
    char iterate;

    //ask the user for input
    cout << "Please enter the number of rows greater than 1: ";
    cin >> rows;
    cout << "Please enter the number of columns greater than 1: ";
    cin >> cols;
    cout << "Would you like to see each iteration of the maze: ";
    cin >> iterate;

    //create a maze object using the variables specified by the user
    maze myMaze(rows, cols);
    //create a DisjSets object using the variables specified by the user
    DisjSets mySet(rows * cols);
    //print the maze
    myMaze.printMaze();

    //create a variable for the size of the elements minus one for ease of use later
    int elems = (rows * cols) - 1;

    //while there is not a path from the top left to the top right, loop this
    while(mySet.isConnected(0, elems) == false)
    {
        //create ttwo variables to be used with the twoRandom function
        int rand1 = -1, rand2 = -1;
        //call the twoRandom function
        twoRandom(rand1, rand2, elems);

        //if the two random ints are neightbors and they are not connected, continue
        if ((myMaze.neighbors(rand1, rand2)) && (mySet.isConnected(rand1, rand2) == false))
        {
            //smash the walls between the two cells
            myMaze.smashWall(rand1, rand2);
            myMaze.smashWall(rand2, rand1);
            //union the two sets
            // call the find function to make sure that we are passing the roots into the unionSets function
            mySet.unionSets(mySet.find(rand1), mySet.find(rand2));

            //output each step if desired
            if (iterate == 'y' || iterate == 'Y')
            {
                cout << "\nNeighbors " << rand1 << ", " << rand2 << " wall smashed below\n\n";
                myMaze.printMaze();
            }
        }
    }

    //if the user did not want to see all the steps, output the final maze
    if (iterate == 'n' || iterate == 'N')
    {
        myMaze.printMaze();
    }

    return 0;
}

void twoRandom(int & n1, int &n2, int maxN)
{
    maxN = maxN + 1;
    n1 = rand() % maxN;
    n2 = rand() % maxN;
}

