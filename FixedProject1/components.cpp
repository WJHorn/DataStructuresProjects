////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Computer Science 2                                 //
// Spring 2018                                        //
// This program ...                                   //
////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

// find greater than function
    //This function compares the value to be entered into the linked list to the values
    //already in the linked list and place them in the list in sorted order.
list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x)
{
    //while the list is not empty
    while(start != stop)
    {
        //if the first node's value is less than x, check the next one
        if ((*start) < x)
        {
            //move to the next node
            start++;
        }
        //if the node's value is greater than x, insert before that node
        else if (*start >= x)
        {
            //return the position at which the new node will be inserted
            return start;
        }
    }
    //if list is empty, return the first place in the list
    return start;
}

//print function
    //This function prints all the contents of the linked lists contained in the vector of linked lists
void print(vector <std::list<int> > adjList)
{
    //iterators to traverse through the list
    list<int>::iterator start, stop;

    //beginning of every output so that the user knows what they're looking at
    cout << endl << "The adjacency list for your graph" << endl;

    //for loop to traverse through the vector and reach every list.
    for (int i = 0; i < adjList.size(); i++)
    {
        //only print if the list is not empty.
        if (adjList[i].empty() == false)
        {
            //set the starting iterator
            start = adjList[i].begin();
            //set the ending iterator
            stop = adjList[i].end();

            //display the list number at the beginning of each line
            cout << "list" << i << " ";

            //while loop to output all contents of the current list
            while(start != stop)
            {
                //output the value at the current node
                cout << (*start) << " ";
                //move to the next node in the list
                start++;
            }
            //move down a line for the next list so that everything looks nice
            cout << endl;
        }
    }
}

//connComponent FUNCTION
    //take in two lists
    //if they have a common component return TRUE
    //else return FALSE
        //use for merge2 function

bool connComponent(const list<int> &first, const list<int> &second)
{
    //iterate through first list
    for (list<int>::const_iterator iter1 = first.begin(); iter1 != first.end(); ++iter1)
    {
        //iterate through second list
        for (list<int>::const_iterator iter2 = second.begin(); iter2 != second.end(); ++iter2)
        {
            //if there are any matching links, return true
            if ((*iter1) == (*iter2))
                {
                    return true;
                }
        }
    }
    //if no matches are found, return false
    return false;
}

//merge2 FUNCTION
    //this will be the function merging two lists together
    //need to delete the smaller merged list from the vector
    //assuming the smaller list will be the second.

bool merge2(list<int> &first, list<int> &second)
{


    if (connComponent(first, second))
    {
        while (second.empty() == false)
        {
            //iterators for traversing the lists
            list<int>::iterator start1 = first.begin();
            list<int>::iterator end1 = first.end();
            list<int>::iterator start2 = second.begin();
            list<int>::iterator end2 = second.end();
            //temporary placeholder to pass the value through the insert function
            int temp = (*start2);

            //insert the new nodes into the larger list
            first.insert(find_gt(start1, end1, temp), temp);
            //remove the old node from the smaller list
            second.remove(temp);
            //get rid of duplicates
            first.unique();
        }
        return true;
    }
    //if they don't have any connected components, return false
    else
    {
        return false;
    }
}

int main()
{
    // vector of integer lists called adjList (adjacency list)
    vector <list<int> > adjList;

    //variable to store the filename entered by the user
    std::string fileName;
    //boolean to continue loop until the file name is correct.
    bool looper = true;
    //counter to make traversing the vector easier
    int counter = 0;
    //empty list
    list<int> mtList;

    //loop to repeat until a correct file is input
    while (looper)
    {
        cout << "Please give us the filename to read in:";
        cin >> fileName;
        //if the filename does not match, inform the user of this and repeat
        if (fileName != "graph.dat")
        {
            cout << endl << "That doesn't seem to be it. Let's try that again:" << endl;
        }
        //else continue on to populating the vector of lists.
        else
        {
            //we no longer need to loop
            looper = false;
            //temporary placeholder to be used to put ints into the list
            int temp;
            //string to hold each line from the file
            std::string line;

            std::ifstream file;
            file.open(fileName);

            //loop as long as we are still receiving data from the file
            while (getline(file,line))
            {
                //push an empty list onto the vector as a starting point
                adjList.push_back(mtList);

                //sstream value to make the population process easier
                std::stringstream sstream(line);

                //loop while we are able to move integers from sstream to temp
                while (sstream >> temp)
                {
                    //declaring, as variables, the beginning and end iterators to be passed to fing_gt function
                    list<int>::iterator first = adjList[counter].begin();
                    list<int>::iterator last = adjList[counter].end();
                    //insert into the proper place using the find_gt function
                    adjList[counter].insert(find_gt(first, last, temp), temp);

                }
                //increase the counter for each iteration
                counter++;
            }
            //call output function
            print(adjList);
            std::string inptLine;
            int list1 = 0, list2 = 0;

            while (1)
            {
                //let the user know that they now have the option to merge lists
                cout << endl << "Enter the two ids to potentially merge together or -1 to quit:";
                //take in the first lists number
                cin >> list1;
                //catch if the first entry was a -1 and break from the loop if that is the case
                if(list1 == -1)
                {
                    break;
                }
                //take in the second lists number
                cin >> list2;
                //declare variables for the two lists
                list<int> first = adjList[list1];
                list<int> second = adjList[list2];

                //runs if merge2 returns true
                if (merge2(first, second))
                {
                    cout << "The lists are merged.";
                    //set the list in adjList to be the newly merged list
                    adjList[list1] = first;
                    //erase the smaller list that was merged
                    adjList.erase(adjList.begin()+(list2));
                    //print it all out!
                    print(adjList);
                }
                //runs if merge2 returns false
                else
                {
                    cout << "The lists are not merged.";
                    //print it all out!
                    print(adjList);
                }
            }
        }
    }
}
