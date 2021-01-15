////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////


#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <vector>

using std::vector;

//internal helper functions for heap sort

//leftChild returns the index of the left child of a specific position
inline int leftChild(int i)
{
    return 2 * i + 1;
}
//percDown percolates the hole down from position i where n is the logical size of the heap
template <typename Comparable>
void percDown(vector<Comparable> & vec, int i, int n)
{
    int child;
    Comparable tmp;

    for (tmp = std::move( vec[i] ); leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if(child != n - 1 && vec[child] < vec[child + 1])
        {
            ++child;
        }
        if (tmp < vec[child])
        {
            vec[i] = std::move( vec[child] );
        }
        else
        {
            break;
        }
    }
    vec[i] = std::move(tmp);
}

//heap sort
template<typename Comparable>
void heapSort(vector<Comparable> & vec)
{
    for (int i = vec.size() / 2 - 1; i >=0; --i)
    {
        percDown(vec, i, vec.size());
    }
    for (int j = vec.size() - 1; j >0; --j)
    {
        std::swap(vec[0], vec[j]);
        percDown(vec, 0, j);
    }
}

#endif // HEAPSORT_H_INCLUDED
