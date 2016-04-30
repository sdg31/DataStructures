#include "twochoice.hpp"
#include <iostream>

// for speed purposes, you might as well
// initialize a bit of space in each vector
// rather than overflowing a bunch of times
// (overflowing as in running out of space in a vector,
// not a bucket)
twochoice::twochoice()
{
	Table.reserve( 130 );
	std::vector<int> T( 130 );
	Table = T;
	Overflow.reserve( 130 );

	AmountBuckets = Table.size() / 10;
	std::vector<int> B( AmountBuckets, 0 );
	ItemsInBucket = B;
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

void twochoice::insert( int key )
{
	int h1 = hash1( key );
	int h2 = hash2( key );

	item i( key );
	if( ItemsInBucket[h1] < ItemsInBucket[h2] || ItemsInBucket[h1] == ItemsInBucket[h2] )
	{
		i.Bucket = h1;
		Table[h1*10 + ItemsInBucket[h1]] = i.Data;
		ItemsInBucket[h1]++;
	}
	else
	{
		i.Bucket = h2;
		Table[h2*10 + ItemsInBucket[h2]] = i.Data;
		ItemsInBucket[h2]++;
	}
}