#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>

// insertion sort that can accept a start and increment
template<typename T> 
void insertion(std::vector<T>& v, int start = 0, int increment = 1)
{
	// this tracks an element while it is sorted
	int moving;

	// loop to end of array excluding first
	for(int i=start+increment; i < v.size(); i+=increment) {
		// the current i is stored
		moving = i;

		// loop to front of array from i
		for(int j=i-increment; j >= start; j-=increment) {
			// if the value is less then swap
			// and update moving to the place
			// it is in after the swap
			if(v[moving] < v[j]) {
				std::swap(v[moving], v[j]);
				moving = j;
			} else
				break;
		}
	}
}

// //it's more efficient to write my own swap than include
// //all of <utility> in a header file
// //std::swap likely has this same implentation anyways
// template<typename T>
// void swap( T& a, T& b )
// {
// 	T temp = a;
// 	a = b;
// 	b = temp;
// }

// //insertion sort works by creating a sorted sublisted of the array
// //that begins at element 0, with each outer for loop iteration,
// //the sorted sublist size increases by one. the element directly
// //to the right of the sorted sublist is compared to the elements inside
// //the sorted sublist, and placed in the appropriate position.
// template<typename T> 
// void insertion_sort( std::vector<T> &array )
// {
// 	//the 4 byte overhead of this variable is worth it,
// 	//compared to calling a function in a for loop
// 	int capacity = array.size();

// 	//i contains the size of the sorted portion of the insertion sort
// 	//j contains the size of the unsorted portion
// 	for( int i = 0; i < capacity; i++ )
// 	{
// 		for( int j = 0; j < i; j++ )
// 		{
// 			if( array[i] < array[j] )
// 			{
// 				swap( array[i], array[j] );
// 			}
// 		}
// 	}
// }

#endif