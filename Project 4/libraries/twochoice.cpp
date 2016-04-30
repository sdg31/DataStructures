#include "twochoice.hpp"
#include <iostream>

// for speed purposes, you might as well
// initialize a bit of space in each vector
// rather than overflowing a bunch of times
// (overflowing as in running out of space in a vector,
// not a bucket)
twochoice::twochoice()
	:Table( 130, -1 ), AmountBuckets( Table.size() / 10 ), ItemsInBucket( AmountBuckets, 0 ) 
{
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
		int position = h1*10 + ItemsInBucket[h1];
		i.Bucket = h1;

		//if the position is empty, insert
		if( Table[position] == -1 )
			Table[position] = i.Data;

		ItemsInBucket[h1]++;
	}
	else
	{
		int position = h2*10 + ItemsInBucket[h2];
		i.Bucket = h2;

		if( Table[position] == -1 )
			Table[position] = i.Data;

		ItemsInBucket[h2]++;
	}
}

int twochoice::search( int key )
{
	int h1 = hash1( key );
	int h2 = hash2( key );

	// find the appropriate buckets
	int b1 = h1*10;
	int b2 = h2*10;

	// first search with the first hash function
	for( int i = 0; i < ItemsInBucket[h1]; i++ )
	{
		if( Table[b1 + i] == key )
			return( b1 + i );
	}
	// if nothing is found, use the second
	for( int i = 0; i < ItemsInBucket[h2]; i++ )
	{
		if( Table[b2 + i] == key )
			return( b2 + i );
	}

	return -1;

}

//tombstone is -1 for the time being
void twochoice::remove( int key )
{
	int position = search( key );
	Table[position] = -1;
}