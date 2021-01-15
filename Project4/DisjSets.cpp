////////////////////////////////////////////////////////
// Will Horn                                          //
// University of Akron                                //
// Data Structures                                    //
// Fall 2018                                          //
////////////////////////////////////////////////////////

#include "DisjSets.h"
#include <iostream>
/**
 * Construct the disjoint sets object.
 */
DisjSets::DisjSets( int numElements ) : s( numElements, -1 )
{

}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */

void DisjSets::unionSets(int root1, int root2) {
	if (s[root1] < s[root2]) {
       s[root1] += s[root2]; //update size of root1 tree
	   s[root2] = root1;  // Make root1 new root
        }
    else
	{
	   s[root2] += s[root1];  //update size of root 2
	   s[root1] = root2;     // make root2 new root
	}
}


/**
 * Perform a find with path halving per exercise 8.16a from the book.
 */
int DisjSets::find( int x )
{
    //if we are working with a root
    if( s[ x ] < 0 )
    {
        //return the position of the root
        return x;
    }
    else
    {
        //recursively call the find function with the parent of the current node
        return s[x] = find( s[ x ] );
    }
}

bool DisjSets::isConnected(int n1, int n2)
{
    //create two int varaibles that are equal to the root of the set
    const int find1 = find(n1);
    const int find2 = find(n2);

    //return whether or not they are equal
    return (find1 == find2);
}
