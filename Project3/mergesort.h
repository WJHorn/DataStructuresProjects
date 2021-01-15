////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <vector>

using std::vector;

//internal helper functions for mergeSort

//merge is the function that is actually doing the merging
template <typename Comparable>
void merge(vector<Comparable> & vec, vector<Comparable> &tmpArr, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElem = rightEnd - leftPos + 1;

    //main loop
    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if (vec[leftPos] <= vec[rightPos])
        {
            tmpArr[tmpPos++] = std::move( vec[leftPos++] );
        }
        else
        {
            tmpArr[tmpPos++] = std::move( vec[rightPos++] );
        }
    }
    //copy rest of left half
    while (leftPos <= leftEnd)
    {
        tmpArr[tmpPos++] = std::move(vec[leftPos++]);
    }
    //copy rest of right half
    while (rightPos <= rightEnd)
    {
        tmpArr[tmpPos++] = std::move(vec[rightPos++]);
    }

    //copy tmpArray back
    for (int i = 0; i < numElem; ++i, --rightEnd)
    {
        vec[rightEnd] = std::move(tmpArr[rightEnd]);
    }
}

//mergeSort is the internal function that is making the recursive calls
template <typename Comparable>
void mergeSort(vector<Comparable> &vec, vector<Comparable> &tmpArr, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(vec, tmpArr, left, center);
        mergeSort(vec, tmpArr, center + 1, right);
        merge(vec, tmpArr, left, center + 1, right);
    }
}

//merge sort
template <typename Comparable>
void mergeSort(vector<Comparable> &vec)
{
    vector<Comparable> tmpArr(vec.size());

    mergeSort(vec, tmpArr, 0, vec.size() - 1);
}


#endif // MERGESORT_H_INCLUDED
