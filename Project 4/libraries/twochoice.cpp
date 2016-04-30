#include "twochoice.hpp"

// for speed purposes, you might as well
// initialize a bit of space in each vector
// rather than overflowing a bunch of times
// (overflowing as in running out of space in a vector,
// not a bucket)
twochoice::twochoice()
{
	Table.reserve( 128 );
	Overflow.reserve( 128 );
}

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