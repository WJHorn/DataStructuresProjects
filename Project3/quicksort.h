////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <vector>

using std::vector;

//internal helper functions for quicksort

//median 3 finds the median of the left, center and right numbers
template <typename Comparable>
const Comparable & median3(vector<Comparable> & vec, int left, int right)
{
    int center = (left + right) / 2;

    if (vec[center] < vec[left])
    {
        std::swap(vec[left], vec[center]);
    }
    if (vec[right] < vec[left])
    {
        std::swap(vec[left], vec[right]);
    }
    if (vec[right] < vec[center])
    {
        std::swap(vec[center], vec[right]);
    }

    //place pivot at position right - 1
    std::swap(vec[center], vec[right - 1]);
    return vec[right - 1];
}

//this quickSort does all the effort while the other one just gets to stand there and look pretty
template <typename Comparable>
void quicksort(vector<Comparable> & vec, int left, int right)
{
    if(left + 2 <= right)
    {
        const Comparable & pivot = median3(vec, left, right);

        //begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while (vec[++i] < pivot){}
            while (pivot < vec[--j]){}
            if (i < j)
            {
                std::swap(vec[i], vec[j]);
            }
            else
            {
                break;
            }
        }
        //restore pivot
        std::swap(vec[i], vec[right - 1]);

        //sort small elements
        quicksort(vec, left, i-1);
        //sort large elements
        quicksort(vec, i + 1, right);
    }
    else
    {
        if (vec[left] > vec[right])
        {
            std::swap(vec[right], vec[left]);
        }
    }
}

//quick sort
template <typename Comparable>
void quickSort(vector<Comparable> & vec)
{
    quicksort(vec, 0, (vec.size() - 1));
}

#endif // QUICKSORT_H_INCLUDED
