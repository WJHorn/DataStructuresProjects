////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>

#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "insertion.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

int main()
{
    string filename;
    int n;
    vector<int> myArr;
    vector<int> sortingArr;

    while (filename != "sorting.dat")
    {
        cout << "Please enter the filename: ";
        cin >> filename;
        if (filename != "sorting.dat")
        {
            cout << endl << "That doesn't seem to be the right filename for this project." << endl;
            cout << "Let's try that again." << endl;
        }
    }
    cout << endl << "Enter the number of integers to sort: ";
    cin >> n;

    //use the filename we obtained to open the file.
    std::ifstream inFile;
    inFile.open(filename);
    int value;
    string line;
    while (getline(inFile, line))
    {
        //use sstream to bring in all the data from the file and place it into the array
        std::stringstream sstream(line);
        sstream >> value;
        myArr.push_back(value);
    }
    inFile.close();

    //fill the sortingArray with the values in myArr
    for (int i = 0; i < myArr.size(); i++)
    {
        sortingArr.push_back(myArr[i]);
    }

/////////////////////////////////////////////////////////////////////
//////////////// HEAP SORT FOR FILE INPUT////////////////////////////
/////////////////////////////////////////////////////////////////////

    cout << endl << "vector before heap sort: ";
    //output the unsorted array
    for (int i = 0; i < myArr.size(); i++)
    {
        cout << myArr[i] << " ";
    }
    //run the heap sort
    heapSort(sortingArr);
    cout << endl << "vector after heap sort: ";
    //output the sorted array
    for (int i = 0; i < sortingArr.size(); i++)
    {
        cout << sortingArr[i] << " ";
    }

/////////////////////////////////////////////////////////////////////
////////////////MERGE SORT FOR FILE INPUT////////////////////////////
/////////////////////////////////////////////////////////////////////

    //reset the sorting array to be the original array
    sortingArr = myArr;

    cout << endl << endl << "vector before merge sort: ";
    //output the unsorted array
    for (int i = 0; i < myArr.size(); i++)
    {
        cout << myArr[i] << " ";
    }
    //run the merge sort
    mergeSort(sortingArr);
    cout << endl << "vector after merge sort: ";
    //output the sorted array
    for (int i = 0; i < sortingArr.size(); i++)
    {
        cout << sortingArr[i] << " ";
    }

/////////////////////////////////////////////////////////////////////
////////////////QUICK SORT FOR FILE INPUT////////////////////////////
/////////////////////////////////////////////////////////////////////

    //reset the sorting array to be the original array
    sortingArr = myArr;

    cout << endl << endl << "vector before quick sort (no cutoff): ";
    //output the unsorted array
    for (int i = 0; i < myArr.size(); i++)
    {
        cout << myArr[i] << " ";
    }
    //run the quick sort
    quickSort(sortingArr);
    cout << endl << "vector after quick sort (no cutoff): ";
    //output the sorted array
    for (int i = 0; i < sortingArr.size(); i++)
    {
        cout << sortingArr[i] << " ";
    }

/////////////////////////////////////////////////////////////////////
//////////////INSERTION SORT FOR FILE INPUT//////////////////////////
/////////////////////////////////////////////////////////////////////

    //reset the sorting array to be the original array
    sortingArr = myArr;

    cout << endl << endl << "vector before insertion sort: ";
    //output the unsorted array
    for (int i = 0; i < myArr.size(); i++)
    {
        cout << myArr[i] << " ";
    }
    //run the insertion sort
    insertionSort(sortingArr);
    cout << endl << "vector after insertion sort: ";
    //output the sorted array
    for (int i = 0; i < sortingArr.size(); i++)
    {
        cout << sortingArr[i] << " ";
    }


    /////////////////////////////////////////////////////////////////////
    /////////////////////////Runtime Block///////////////////////////////
    /////////////////////////////////////////////////////////////////////

    clock_t start, stop;
    vector<int> randomArr, ascendArr, descendArr;
    //populate the ascending array with the amount specified by the user
    for (int i = 0; i < n; i++)
    {
        ascendArr.push_back(i);

        //populate the random array with the amount of numbers specified by the user
        randomArr.push_back(std::rand() % 1000);
    }

    //populate the descending array with the amount specified by the user
    for (int j = n; j > 0; --j)
    {
        descendArr.push_back(j);
    }

    cout << endl << endl << "runtime of algorithms for N = " << n << " items" << endl;
    //runtime for algorithms for N = n items

/////////////////////////////////////////////////////////////////////
//////////////////////////HEAP SORT//////////////////////////////////
/////////////////////////////////////////////////////////////////////

    //sort the random array and time it
    sortingArr = randomArr;
    start = clock();
    heapSort(sortingArr);
    stop = clock();
    cout << "heap sort random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the ascending array and time it
    sortingArr = ascendArr;
    start = clock();
    heapSort(sortingArr);
    stop = clock();
    cout << "heap sort ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the descending array and time it
    sortingArr = descendArr;
    start = clock();
    heapSort(sortingArr);
    stop = clock();
    cout << "heap sort descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

/////////////////////////////////////////////////////////////////////
/////////////////////////MERGE SORT//////////////////////////////////
/////////////////////////////////////////////////////////////////////

    //sort the random array and time it
    sortingArr = randomArr;
    start = clock();
    mergeSort(sortingArr);
    stop = clock();
    cout << "merge sort random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the ascending array and time it
    sortingArr = ascendArr;
    start = clock();
    mergeSort(sortingArr);
    stop = clock();
    cout << "merge sort ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the descending array and time it
    sortingArr = descendArr;
    start = clock();
    mergeSort(sortingArr);
    stop = clock();
    cout << "merge sort descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

/////////////////////////////////////////////////////////////////////
//////////////////////////QUICK SORT/////////////////////////////////
/////////////////////////////////////////////////////////////////////

    //sort the random array and time it
    sortingArr = randomArr;
    start = clock();
    quickSort(sortingArr);
    stop = clock();
    cout << "quick sort random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the ascending array and time it
    sortingArr = ascendArr;
    start = clock();
    quickSort(sortingArr);
    stop = clock();
    cout << "quick sort ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the descending array and time it
    sortingArr = descendArr;
    start = clock();
    quickSort(sortingArr);
    stop = clock();
    cout << "quick sort descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;

/////////////////////////////////////////////////////////////////////
///////////////////////INSERTION SORT////////////////////////////////
/////////////////////////////////////////////////////////////////////

    //sort the random array and time it
    sortingArr = randomArr;
    start = clock();
    insertionSort(sortingArr);
    stop = clock();
    cout << "insertion sort random: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the ascending array and time it
    sortingArr = ascendArr;
    start = clock();
    insertionSort(sortingArr);
    stop = clock();
    cout << "insertion sort ascending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl;

    //sort the descending array and time it
    sortingArr = descendArr;
    start = clock();
    insertionSort(sortingArr);
    stop = clock();
    cout << "insertion sort descending: " << double(stop-start)/double(CLOCKS_PER_SEC) << endl << endl;




    return 0;
}
