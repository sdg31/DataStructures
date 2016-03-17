#include "insertion_sort.hpp"
#include <vector>

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