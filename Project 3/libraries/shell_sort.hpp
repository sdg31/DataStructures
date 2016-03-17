#include "insertion_sort.hpp"

//TODO: implement the strange offset seen in the book and ODSA
//that starts with an offset > 1/2. I didn't really get it and didn't implement it.

//shellsort divides the list into a sublist of two, starting at 0 plus some offset
//(the offset begins at n/2), and sorts array[x] and array[x+offset] until x+offset
//goes beyond the bounds of the array. The offset is then divided in two, thus
//increasing the size of the sublist. 
//once the offset reaches 1, the array is sorted by insertion sort.
template<typename T>
void shell_sort( std::vector<T> &array )
{
	int capacity = array.size();
	int offset = capacity / 2;
	while( offset > 1 )
	{
		for( int i = 0; i < capacity; i++ )
		{
			if( i + offset <= capacity )
			{
				if( array[i] > array[i + offset] )
					swap( array[i], array[i+offset] );
			}
		}
		offset /= 2;
	}
	insertion_sort( array );
}