/*!
 *  Exercise: implementing partition and quicksort
 *  @date April, 3rd.
 *
 *  In this exercise you should complete the code below,
 *  implementing the partition algorithm presente earlier.
 *  After that, think about how would you apply the partition
 *  result to design an algorithm to sort ranges.
 *  Think recursively and draw some inspiration from methods
 *  such as binary search.
 *
 */
#include <iostream>  // cout, endl
#include <iterator>  // std::next
#include <array>     // std::array
#include <functional>// std::less, std::function<>
#include <algorithm>

//=== Alias and constants
typedef bool(*Compare)(int,int); //!< Comparison function needed for sorting.
//using Compare = std::function< bool(int, int) >; // alternative version.


/*!
 * Partition reorders the elements in the range [first;last) in such a way that
 * all elements **less** than the pivot appear before the pivot, and all elements
 * equal or greater than the pivot appear after the pivot.
 *
 * Any relative order among elements of the array might not be preserved.
 *
 * By **less** we mean a _strict order_ binary relation among the elements we
 * wantt to partition.
 *
 * \note We assume the pivot is a valid iterator in [first; last).
 *
 * @param first The first element in the range we want to reorder.
 * @param last Past the last element in the range we want to reorder.
 * @param pivot Location of the pivot element we need to partition the array.
 * @param comp A comparison function that returns true if the first parameter is **less** than the second.
 * @return An iterator just past the location of the pivot (second group).
 */
int* partition( int *first, int *last, int *pivot, Compare comp )
{
	//It is the pointer that is going to be compared with pivot. 
	int *wall = first;
	int *current = first;
//	*pivot = *first;
	
		while(std::distance(current, pivot) > 0) {
			if(comp(*current, *pivot)) {
				std::swap(*current, *wall);
				wall++;
			}
			current += 1;
			
		}
		std::swap(*wall,*pivot);
		
    return wall; // Just a stub, replace it as necessary.
}

/*!
 * This function return `true` if the first parameter is **less**
 * than the second parameter.
 * By **less** we mean a relation of _strict order_ that there exists
 * among elements of the type int.
 * \param a The first element.
 * \param b The second element.
 * \return true if a < b, false otherwise.
 */
bool compare( int a, int b )
{
    return a < b;
}

void quick_sort(int *first, int *last) {
	if(std::distance(first, last) > 1) {
	int *pivot = partition(first, last, last-1, compare);

		quick_sort(first, pivot);
		quick_sort(pivot+1, last);
	}
}
// The driver function.
int main()
{
    // The array we wish to partition, then sort.
    constexpr size_t AR_SIZE=10; //!< The array size.
    std::array< int, AR_SIZE > A { { 9, 8, 1, 2, 10, 7, 5, 3, 4, 6 } };

    //================================================================================
    // Print the original array.
    //--------------------------------------------------------------------------------
    std::cout << ">>> Original array: [ ";
    std::copy( A.begin(), A.end(), std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "]\n";

    //================================================================================
    // Do the partition process.
    //--------------------------------------------------------------------------------
    std::cout << ">>> Partitioning the array...\n";
    // Choosing the pivot.
    int * target ( & A.back() );  // Choosing a pivot.
    std::cout << ">>> Pivot is " << *target << ", located at position " << std::distance( A.begin(), target ) << std::endl;

    //*** Calling the partition function ***//
    auto pivot = partition( A.begin(), A.end(), target, compare );

    //================================================================================
    // Show (possibly) new location of pivot after partition.
    //--------------------------------------------------------------------------------
    std::cout << ">>> Pivot is now located at position " << std::distance( A.begin(), pivot) << ".\n";
    // Visually show the partition while printing out the modified array.
    std::cout << "[ "; // The first part
    std::copy( A.begin(), pivot, std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "] ";
    std::cout << *pivot << " [ "; // The pivot, then the second part.
    std::copy( std::next(pivot), A.end(), std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "]\n";


    // TODO: after successfuly finished partition, code the quick sort.

	quick_sort(A.begin(), A.end());	
    std::cout << "[ "; // The first part
    std::copy( A.begin(), A.end(), std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "] ";

    std::cout << ">>> Normal exiting...\n\n";
    return  EXIT_SUCCESS;
}
