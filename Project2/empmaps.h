////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Project 2                                          //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#ifndef EMPMAPS_H
#define EMPMAPS_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

#include "Employee.h"

using std::vector;
using std::map;
using std::unordered_map;

//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns a vector of employees using the Employee     //
//class file. You can prompt the user for the input file in this function.      //
//Give the user a nice error message if the input file does not exist and exit. //
//////////////////////////////////////////////////////////////////////////////////
vector<Employee> employees();

//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an ordered map. The key for this map is the  //
//employee’s department id. The department id is the first four most            //
//significant digits of the employee identifier.                                //
//////////////////////////////////////////////////////////////////////////////////
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an ordered map. The key for this map is      //
//related to the employee’s salary based on 10,000 range increments.            //
//////////////////////////////////////////////////////////////////////////////////
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);

//////////////////////////////////////////////////////////////////////////////////
//This function prints the number of employees within each range using an       //
//ordered map. Afterwards, it print the salary range with the most number of    //
//employees and prints the number of employees in this range.                   //
//////////////////////////////////////////////////////////////////////////////////
void printSalRange(map<int,vector<Employee>> & salRange);

//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an unordered map. The key for this map is the//
//employee’s department id. The department id is the first four most            //
//significant digits of the employee identifier.                                //
//////////////////////////////////////////////////////////////////////////////////
unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
//////////////////////////////////////////////////////////////////////////////////
//This function builds and returns an unordered map. The key for this unordered //
//map is related to the employee’s salary based on 10,000 range increments.     //
//////////////////////////////////////////////////////////////////////////////////
unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);

//////////////////////////////////////////////////////////////////////////////////
//This function prints the number of employees within each range using an       //
//unordered map. Afterwards, it print the salary range with the most number of  //
//employees and prints the number of employees in this range.                   //
//////////////////////////////////////////////////////////////////////////////////
void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);


#endif // EMPMAPS_H
