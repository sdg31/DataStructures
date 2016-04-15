#include "insertion_sort.hpp"
#include <cmath>
#include <iostream>

// //TODO: implement the strange offset seen in the book and ODSA
//that starts with an offset > 1/2. I didn't really get it and didn't implement it.

// shellsort divides the list into a sublist of two, starting at 0 plus some offset
// (the offset begins at n/2), and sorts array[x] and array[x+offset] until x+offset
// goes beyond the bounds of the array. The offset is then divided in two, thus
// increasing the size of the sublist. 
// once the offset reaches 1, the array is sorted by insertion sort.
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

// an optimization for shellsort is to create an offset that is the highest 
// power of 2 less than the capacity. this function finds the offset
// by first calculating the log base 2 of the capacity, subtracting one
// from it, and then computing 2^x
template<typename T>
void shell_sort_log_2( std::vector<T> &array )
{
        int capacity = array.size();
	int offset_power = log2( capacity ) - 1;
	int offset = pow( 2, offset_power );
	while( offset_power > 0 )
	{
	        offset = pow( 2, offset_power );    
		for( int i = 0; i < capacity; i++ )
		{
			if( i + offset <= capacity )
			{
				if( array[i] > array[i + offset] )
					swap( array[i], array[i+offset] );
			}
		}
		--offset_power;
	}
	insertion_sort( array );
}
