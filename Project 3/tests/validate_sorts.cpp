// our code
#include "shell_sort.hpp"
#include "stopwatch.hpp"

// other group's code
#include "bubble.hpp"
#include "emersonRadix.hpp"
#include "InsertionSort.hpp"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0)); // seed random numbe

	int n = 10000;

	std::vector<int> shell(n);

	// intialize a vector to random values
	for (int i=0; i < n; i++)
		shell[i] = rand();

	// verify that the original array is unsorted
	if (!std::is_sorted(shell.begin(), shell.end()))
		std::cout << "Original vector confirmed unsorted" << std::endl << std::endl;

	// copy to other vectors
	std::vector<int> bubble(shell.begin(), shell.end());
	std::vector<int> radix(shell.begin(), shell.end());
	std::vector<int> insertion(shell.begin(), shell.end());

	// test shell
	shell_sort_clog2(shell);
	if (!std::is_sorted(shell.begin(), shell.end()))
		std::cout << "Shell sort FAIL" << std::endl;
	else
		std::cout << "Shell sort PASS" << std::endl;

	// test bubble
	bubblesort(bubble.begin(), bubble.end());
	if (!std::is_sorted(bubble.begin(), bubble.end()))
		std::cout << "Bubble sort FAIL" << std::endl;
	else
		std::cout << "Bubble sort PASS" << std::endl;

	// test radix
	emersonSort(radix);
	if (!std::is_sorted(radix.begin(), radix.end()))
		std::cout << "Radix sort FAIL" << std::endl;
	else
		std::cout << "Radix sort PASS" << std::endl;

	// test insertion
	InsertionSort(insertion);
	if (!std::is_sorted(insertion.begin(), insertion.end()))
		std::cout << "Insertion sort FAIL" << std::endl;
	else
		std::cout << "Insertion sort PASS" << std::endl;

	return 0;
}
