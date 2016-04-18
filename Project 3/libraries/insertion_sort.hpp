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

#endif