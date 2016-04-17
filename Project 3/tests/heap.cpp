// This test is used to compare the run times of several
// different sorts.  These outputs will be put into
// Matlab to create visualizations

// our code
#include "shell_sort.hpp"
#include "stopwatch.hpp"

// other group's adapted code
#include "bubble.hpp"
#include "emersonRadix.hpp"
#include "InsertionSort.hpp"
#include "merge.hpp"
#include "HeapNorm.hpp"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

template <typename T>
void print(std::vector<T> v);

int main()
{
	srand(time(0)); // seed random number

	// intialize variables
	int num_tests = 10;
	int vector_size = 10;

	std::cout << "Testing " << num_tests << " loops of sorting " << vector_size << " values:" << std::endl;

	for (int i=0; i < num_tests; i++) {
		std::vector<int> bubble(vector_size);

		// intialize a vector to random values
		for (int i=0; i < vector_size; i++)
			bubble[i] = rand()%20;

		// verify that the original array is unsorted
		if (std::is_sorted(bubble.begin(), bubble.end()))
			break;

		// copy to other vectors
		HeapNorm<int> heap(bubble);

		// test bubble
		std::cout << "before bubble:" << std::endl;
		print(bubble);
		std::cout << "after bubble:" << std::endl;
		bubblesort(bubble.begin(), bubble.end());
		print(bubble);

		heap.buildHeap();
		std::vector<int> vheap = heap.getvector();

		// test radix
		std::cout << "before heap sort:" << std::endl;
		print(vheap);
		std::cout << "after heap sort:" << std::endl;
		heap.sort();
		vheap = heap.getvector();
		print(vheap);

		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}

template <typename T>
void print(std::vector<T> v) {
	for (int i=0; i < v.size(); i++)
		std::cout << v[i] << " ";

	std::cout << std::endl;
}
