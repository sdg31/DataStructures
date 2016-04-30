#ifndef TWOCHOICE_HPP
#define TWOCHOICE_HPP

#include <vector>

// two-choice hashing uses two unrelated hash functions,
// and puts the result in the bucket that is less full
class twochoice
{
public:
	twochoice();
	int hash1( int key );
	int hash2( int key );

	void insert( int key );

	struct item
	{
		item( int d )
			:Data( d )
		{}
		int Bucket;
		int Data;
	};
//private:
	//the main hash table
	std::vector<int> Table;
	// overflow table, items inserted into a full bucket go here
	std::vector<int> Overflow;

	std::vector<int> ItemsInBucket;
	int AmountBuckets;
};

#endif