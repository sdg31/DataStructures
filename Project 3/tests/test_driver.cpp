#include "insertion_sort.hpp"
#include "shell_sort.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> jason = { 3, 6, 400, 4, 9, 53, 3, 2, 1, 842 };
	shell_sort( jason );
	for( int i = 0; i < jason.size(); i++ )
		std::cout << jason[i] << std::endl;
	return 0;
}