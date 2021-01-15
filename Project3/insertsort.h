////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#ifndef INSERTION_H_INCLUDED
#define INSERTION_H_INCLUDED

#include <vector>

using std::vector;

//insertion sort
template <typename Comparable>
void insertionSort(vector<Comparable> & vec)
{
    for (int p = 1; p < vec.size(); ++p)
    {
        Comparable tmp = std::move( vec[p] );

        int j;
        for (j = p; j > 0 && tmp < vec[j-1]; --j)
        {
            vec[ j ] = std::move( vec[j-1] );
        }
        vec[j] = std::move(tmp);
    }
}

#endif // INSERTION_H_INCLUDED
