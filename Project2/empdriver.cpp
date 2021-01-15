////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Project 2                                          //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <ctime>

#include "empmaps.h"
#include "Employee.h"



using namespace std;

int main()
{
    //create the clock variables
    clock_t start, stop;
    //creates a vector of Employee class and initialize it with the employees() function
    vector<Employee> myEmployees = employees();
    //move down a line to make things prettier
    cout << endl;

    //start the clock for creating the map with department as the key
    start = clock();
    //create the map
    map<int, vector<Employee>> depMap = mapEmpDept(myEmployees);
    //stop the clock once the map is created
    stop = clock();
    //output the clock time
    cout << "ORDERED Map creation with departments as key clock ticks: " << double(stop - start) << endl;
    //output the number of departments
    cout << "ORDERED Map number of departments: " << depMap.size() << endl;

    //start the clock for creating a map with salary as the key
    start = clock();
    //create the map that can then be used to output with the printSalRange() function
    map<int, vector<Employee>> salMap = mapSalRange(myEmployees);
    //stop the clock
    stop = clock();
    // output the clock time
    cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop - start) << endl;
    //output the number of salary ranges
    cout << "ORDERED Map number of salary ranges: " << salMap.size() << endl;

    //call the printSalRange() function for the map we created most recently
    printSalRange(salMap);
    //move down a line to make things prettier
    cout << endl;

    //start the clock for creating an unordered_map with departments as the key
    start = clock();
    //create the unordered_map
    unordered_map<int, vector<Employee>> depUnMap = umapEmpDept(myEmployees);
    //stop the clock
    stop = clock();
    //output the clock time
    cout << "UNORDERED Map creation with departments as key clock ticks: " << double(stop - start) << endl;
    //output the number of salary ranges
    cout << "UNORDERED Map number of departments: " << depUnMap.size() << endl;

    //start the clock for creating an unordered_map with salary as the key
    start = clock();
    //create the unordered_map
    unordered_map<int, vector<Employee>> salUnMap = umapSalRange(myEmployees);
    //stop the clock
    stop = clock();
    //output the clock time
    cout << "UNORDERED Map creation with salary as key clock ticks: " << double(stop - start) << endl;
    //output the number of departments
    cout << "UNORDERED Map number of salary ranges: " << salUnMap.size() << endl;

    //call the uprintSalRange() function for the unordered_map we created most recently
    uprintSalRange(salUnMap);

    //return 0 to end the program nicely.
    return 0;
}
