#include "shell_sort.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand( time( nullptr ) );
	std::vector<int> jake;
	for( int i = 0; i < (rand() % 100); i++ )
	{
		jake.push_back( rand() % 10000 );
	}
	std::cout << "Jake the vector has " << jake.size() << " elements and is defined as:\n";
	for( int i = 0; i < jake.size(); i++ )
		std::cout << jake[i] << " ";
	std::cout << "\n";

	shell_sort( jake );

	std::cout << "Jake has been sorted. He was reluctant to start, but in the end he's glad he went through with it.\n";
	std::cout << "Jake is now defined as:\n";
	for( int i = 0; i < jake.size(); i++ )
		std::cout << jake[i] << " ";
	std::cout << "\n";
	return 0;
}