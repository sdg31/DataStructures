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
	int vector_size = 12;

	StopWatch sw;
	std::vector<int> v(vector_size);

	// intialize a vector to random values
	for (int i=0; i < vector_size; i++)
		v[i] = rand()%20;

	std::vector<int> v2(v.begin(), v.end());

	print(v);

	shellsort(v);
	bubblesort(v2.begin(), v2.end());

	print(v);
	print(v2);

	return 0;
}

void print(const char* name, int a[], int size) {
	std::cout << name << " = [";

	for (int i=0; i < size; i++)
		std::cout << a[i] << " ";

	std::cout << "];" << std::endl;
}

template <typename T>
void print(std::vector<T> v) {
	for (int i=0; i < v.size(); i++)
		std::cout << v[i] << " ";

	std::cout << std::endl;
}
