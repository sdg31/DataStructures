// This test is used to compare the run times of several
// different sorts with varying length.  These outputs will 
// be put into Matlab to create visualizations

// our code
#include "shell_sort.hpp"
#include "stopwatch.hpp"

// other group's adapted code
#include "bubble.hpp"
#include "emersonRadix.hpp"
#include "InsertionSort.hpp"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

void print(const char* name, int a[], int size);
template <typename T>
void print(std::vector<T> v);

int main()
{
	srand(time(0)); // seed random number

	// intialize variables
	int num_tests = 100;
	int max_vector_size = 10000;

	// vectors to hold execution times
	int shell_times[num_tests];
	int bubble_times[num_tests];
	int insertion_times[num_tests];
	int standard_times[num_tests];

	// find amount to increment each loop
	int increment = max_vector_size / num_tests;
	int vector_size = increment;

	std::cout << "Testing " << num_tests << " loops of sorting " << vector_size << " - " << (num_tests * increment) << " values:" << std::endl;

	for (int i=0; i < num_tests; i++) {

		std::cout << "\r" << (int)(((double)i/num_tests)*100) << "%" << std::flush;

		StopWatch sw;
		std::vector<int> shell(vector_size);

		// intialize a vector to random values
		for (int i=0; i < vector_size; i++)
			shell[i] = rand();

		// verify that the original array is unsorted
		if (std::is_sorted(shell.begin(), shell.end()))
			break;

		// copy to other vectors
		std::vector<int> bubble(shell.begin(), shell.end());
		std::vector<int> insertion(shell.begin(), shell.end());
		std::vector<int> standard(shell.begin(), shell.end());

		// test shell
		sw.start();
		shellsort(shell);
		shell_times[i] = sw.pause();

		// test bubble
		sw.start();
		bubblesort(bubble.begin(), bubble.end());
		bubble_times[i] = sw.pause();

		// test insertion
		sw.start();
		InsertionSort(insertion);
		insertion_times[i] = sw.pause();

		// test standard
		sw.start();
		std::sort(standard.begin(), standard.end());
		standard_times[i] = sw.pause();

		vector_size += increment;
	}

	std::cout << "\r100%" << std::flush << std::endl << std::endl;

	print("shell", shell_times, num_tests);
	print("bubble", bubble_times, num_tests);
	print("insertion", insertion_times, num_tests);
	print("standard", standard_times, num_tests);

	std::cout << std::endl;

	return 0;
}

void print(const char* name, int a[], int size) {
	std::cout << name << " = [";

	for (int i=0; i < size; i++)
		std::cout << a[i] << " ";

	std::cout << "];" << std::endl;
}
