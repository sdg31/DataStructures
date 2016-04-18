#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include "insertion_sort.hpp"
#include <cmath>
#include <iostream>

// runs insertion sort over increments divisible by 2
// from the length of the vector
template <typename T>
void shellsort(std::vector<T>& v) {
	// get a different increment value
	for (int i=v.size()/2; i > 1; i/=2)
		// loop from 0 to the increment value
		// and run insertion on that
    	for (int j=0; j<i; j++)
      		insertion(v, j, i);

    // run a standard insertion 
  	insertion(v);
}

#endif
