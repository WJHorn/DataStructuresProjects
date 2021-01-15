////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Project 2                                          //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>

#include "empmaps.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns a vector of employees using the Employee     //
//class file. You can prompt the user for the input file in this function.      //
//Give the user a nice error message if the input file does not exist and exit. //
//////////////////////////////////////////////////////////////////////////////////

vector<Employee> employees()
{
    //string to store the file name the user will input
    string fileName;

    //while loop with nested if else statements to make sure that we are using one
    // the correct files.
    while (1)
    {
        //ask the user for the name of the file
        cout << "Hello user, please enter the file name: ";
        //bring in the filename from the user
        cin >> fileName;
        //If records.dat is input, let the user know and break the loop
        if (fileName == "records.dat")
        {
            break;
        }
        //If records2.dat is input, let the user know and break the loop
        else if (fileName == "records2.dat")
        {
            break;
        }
        //If debug.dat is input, let the user know and break the loop
        //this is solely for debugging purposes.
        else if (fileName == "debug.dat")
        {
            break;
        }
        // if the user enters quit or exit, break from the loop
        else if (fileName == "quit" || fileName == "q")
        {
            //this will run the rest of the program with empty maps.
            break;
        }
        //if the user inputs something incorrect, let them know that won't work
        else
        {
            //cute error message, this will continue the loop
            cout << "Maybe that was a typo, Let's try again." << endl;
        }
    }

    //create a temporary vector to populate and return
    vector<Employee> myEmployees;
    //string to hold each line of the file
    string line;
    //counter variable to keep track of the total number of employees
    int counter = 0;
    //ifstream to bring data in from the file
    std::ifstream inFile;
    //open the file
    inFile.open(fileName);
    //integers to hold the ID and salary of each employee
    int ID, salary;

    //loop until EOF
    while (getline(inFile, line))
    {
        //create a stringstream variable
        std::stringstream sstream(line);

        //string to hold the employees last name
        string lastName;

        //use sstream to fill the temporary values
        sstream >> ID >> lastName >> salary;

        //create an employee class with the variables we created earlier
        //push this onto the vector of Employee class
        myEmployees.push_back(Employee(ID, lastName, salary));

        //increment the counter
        counter++;
    }
    //output the number of employees
    cout << endl << "Number of employees are: " << counter << endl;


    //return the newly populared vector.
    return myEmployees;
}


//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an ordered map. The key for this map is the  //
//employee’s department id. The department id is the first four most            //
//significant digits of the employee identifier.                                //
//////////////////////////////////////////////////////////////////////////////////

map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp)
{
    //create a map to return at the end
    map<int, vector<Employee>> empDeptMap;
    //integer variables for the ID and key. The key is the first 4 digits of the ID
    int KEY;
    //iterate through the vector we bring in and use it to populate the map.
    for (int i = 0; i < emp.size(); i++)
    {
        //set the key to be the first 4 digits of the ID
        KEY = emp[i].id() / 100;

        //put all of the elements from the temporary vector into the maps vector
        empDeptMap[KEY].push_back(emp[i]);
    }
    //return the map we have created
    return empDeptMap;
}


//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an ordered map. The key for this map is      //
//related to the employee’s salary based on 10,000 range increments.            //
//////////////////////////////////////////////////////////////////////////////////

map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)
{
    //create a map to return at the end
    map<int, vector<Employee>> salRangeMap;
    //integer variables for the salary and key. The key is the salary in tens of thousands
    int KEY;
    //iterate through the vector we bring in and use it to populate the map.
    for (int i = 0; i < emp.size(); i++)
    {
        //set the key to be the salary in tens of thousands
        KEY = emp[i].sal() / 10000;

        //put all of the elements from the temporary vector into the maps vector
        salRangeMap[KEY].push_back(emp[i]);

    }
    //return the map we have created
    return salRangeMap;
}


//////////////////////////////////////////////////////////////////////////////////
//This function prints the number of employees within each range using an       //
//ordered map. Afterwards, it print the salary range with the most number of    //
//employees and prints the number of employees in this range.                   //
//////////////////////////////////////////////////////////////////////////////////

void printSalRange(map<int,vector<Employee>> & salRange)
{
    //integers to make keeping track of the largest salary range easier
    int crntSize = 0, lrgstrSize = 0, lrgstSalRange;

    //iterate through the map we brought in
    for (auto & entry : salRange)
    {
        //output the salary range and the number of employees in that range
        cout << "ORDERED Map Salary Range " << entry.first << "0000 contains " << entry.second.size() << endl;
        //set the current size for the next iteration
        crntSize = entry.second.size();
        //if the current size is larger than the largest size
        if (crntSize > lrgstrSize)
        {
            //set the largest size to the current size
            lrgstrSize = crntSize;
            //set the salary range to the current range
            lrgstSalRange = entry.first;
        }
    }
    //output the largest salary range at the end
    cout << "ORDERED Map Salary Range with most employees: " << lrgstSalRange << "0000 containing " << lrgstrSize << endl;
}


//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an unordered map. The key for this map is the//
//employee’s department id. The department id is the first four most            //
//significant digits of the employee identifier.                                //
//////////////////////////////////////////////////////////////////////////////////

unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp)
{
    //create an unordered_map to return at the end
    unordered_map<int, vector<Employee>> empDeptUnMap;
    //integer variables for the ID and key. The key is the first 4 digits of the ID
    int KEY;
    //iterate through the vector we bring in and use it to populate the unordered_map.
    for (int i = 0; i < emp.size(); i++)
    {
        //set the key to be the first 4 digits of the ID
        KEY = emp[i].id() / 100;

        //put all of the elements from the temporary vector into the unordered_maps vector
        empDeptUnMap[KEY].push_back(emp[i]);

    }
    //return the unordered_map we have created
    return empDeptUnMap;
}


//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an unordered map. The key for this unordered //
//map is related to the employee’s salary based on 10,000 range increments.     //
//////////////////////////////////////////////////////////////////////////////////

unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp)
{
    //create an unordered_map to return at the end
    unordered_map<int, vector<Employee>> salRangeUnMap;
    //integer variables for the salary and key. The key is the salary in tens of thousands
    int SALARY, KEY;
    //iterate through the vector we bring in and use it to populate the unordered_map
    for (int i = 0; i < emp.size(); i++)
    {
        //set the key to be the salary in tens of thousands
        KEY = emp[i].sal() / 10000;

        //put all of the elements from the vector into the unordered_map
        salRangeUnMap[KEY].push_back(emp[i]);

    }
    //return the unordered_map we have created
    return salRangeUnMap;
}


//////////////////////////////////////////////////////////////////////////////////
//This function prints the number of employees within each range using an       //
//unordered map. Afterwards, it print the salary range with the most number of  //
//employees and prints the number of employees in this range.                   //
//////////////////////////////////////////////////////////////////////////////////

void uprintSalRange(unordered_map<int,vector<Employee>> & salRange)
{
    //integer variables to make keeping track of the largest salary range easier
    int crntSize = 0, lrgstrSize = 0, lrgstSalRange;

    //iterate through the unordered_map we brought in
    for (auto & entry : salRange)
    {
        //output the salary range and the number of employees in that range
        cout << "UNORDERED Map Salary Range " << entry.first << "0000 contains " << entry.second.size() << endl;
        //set the current size
        crntSize = entry.second.size();
        //if the current size is larger than the largest size
        if (crntSize > lrgstrSize)
        {
            //set the largest size to the current size
            lrgstrSize = crntSize;
            //set the largest salary range to the current salary range
            lrgstSalRange = entry.first;
        }
    }
    //output the largest salary range and how many employees are in it at the end
    cout << "UNORDERED Map Salary Range with most employees: " << lrgstSalRange << "0000 containing " << lrgstrSize << endl;
}
