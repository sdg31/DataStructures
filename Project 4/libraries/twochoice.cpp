#include "twochoice.hpp"

// for the time being, these hash functions
// return modulo of two different prime numbers
// they could be more complicated, but for testing
// this will work
int twochoice::hash1( int key )
{
	return key % 13;
}

int twochoice::hash2( int key )
{
	return key % 7;
}