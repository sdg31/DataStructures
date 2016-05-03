#ifndef TWOCHOICE_HPP
#define TWOCHOICE_HPP

#include <prime.hpp>

#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <math.h>

template <typename K, typename D>
struct Item
{
	Item( K key, D data )
		:key( key ), data( data )
	{}
	Item() { }
	K key;
	D data;
};

// two-choice hashing uses two unrelated hash functions,
// and puts the result in the bucket that is less full
template <typename K, typename D>
class twochoice
{
public:
	twochoice(int);
	twochoice(): twochoice(130) { }
	~twochoice();
	int hash1( int key );
	int hash2( int key );
	int hash1( std::string key );
	int hash2( std::string key );

	int insert( Item<K, D> item );
	int insert( K key, D data );
	int insertBucket(int bucket, const Item<K, D>* item);
	int insertOverflow(const Item<K, D>* item);
	int positionSearch( K key );
	Item<K, D> search( K key );
	void remove( K key );
	int size();

	// ostream for hash table contents
	template <typename K1, typename D1>
	friend std::ostream& operator<<(std::ostream& os, const twochoice<K1, D1>& h);

private:
	const int BucketSize;

	// tombstone variable
	const Item<K, D>* tombstone;
	//the main hash table
	std::vector<const Item<K, D>* > Table;
	// overflow table, items inserted into a full bucket go here
	std::vector<const Item<K, D>* > Overflow;

	std::vector<int> ItemsInBucket;
	int AmountBuckets;

	int GreatestPrime;
};

// ostream for item
template <typename K, typename D>
std::ostream& operator<<(std::ostream& os, const Item<K, D>& item) {
	return os << "key: " << item.key << " data: " << item.data;
}

// ostream for hash table contents
template <typename K, typename D>
std::ostream& operator<<(std::ostream& os, const twochoice<K, D>& h) {
	os << "------table------" << std::endl;
	for (int i=0; i < h.Table.size(); i++) {
		if (h.Table[i] != h.tombstone)
			os << *h.Table[i] << std::endl;
		else
			os << "empty" << std::endl;
	}

	os << "-----overflow----" << std::endl;
	for (int i=0; i < h.Overflow.size(); i++) {
		if (h.Overflow[i] != h.tombstone)
			os << *h.Overflow[i] << std::endl;
		else
			os << "empty" << std::endl;
	}

	return os;
}

// for speed purposes, you might as well
// initialize a bit of space in each vector
// rather than overflowing a bunch of times
// (overflowing as in running out of space in a vector,
// not a bucket)
template <typename K, typename D>
twochoice<K, D>::twochoice(int size)
	:tombstone(new Item<K, D>()), Table( size, tombstone ), BucketSize(round(log2(log2(size)))),
	AmountBuckets( size / BucketSize ), ItemsInBucket(size / BucketSize, 0 ),
	GreatestPrime( greatest_prime_factor(size / BucketSize) )
{ 
	std::cout << "BucketSize = " << BucketSize << std::endl;
}

// for the time being, these hash functions
// return modulo of two different prime numbers
// they could be more complicated, but for testing
// this will work
template <typename K, typename D>
int twochoice<K, D>::hash1( int key )
{
	return key % AmountBuckets;
}

template <typename K, typename D>
int twochoice<K, D>::hash2( int key )
{
	return key % GreatestPrime;
}

template <typename K, typename D>
int twochoice<K, D>::hash1( std::string key )
{
	int sum = 0;
	for (int i=0; i < key.size(); i++)
		sum += key[i];

	return hash1(sum);
}

template <typename K, typename D>
int twochoice<K, D>::hash2( std::string key )
{
	int sum = 0;
	for (int i=0; i < key.size(); i++)
		sum += key[i];

	return hash2(sum);
}

template <typename K, typename D>
int twochoice<K, D>::insert( Item<K, D> tempItem )
{
	const Item<K, D>* item = new Item<K, D>(tempItem.key, tempItem.data);

	int collisions = 0;
	
	int h1 = hash1( item->key );
	int h2 = hash2( item->key );

	// insert into bucket h1 if less or equal
	if( ItemsInBucket[h1] <= ItemsInBucket[h2])
	{
		// insert if there is room in the bucket
		if (ItemsInBucket[h1] < BucketSize)
		{
			collisions += insertBucket(h1, item);
		}
		// otherwise put in overflow
		else
		{
			collisions += insertOverflow(item);
		}
	}
	// insert into h2 if it is less full
	else
	{
		// insert if there is room in the bucket
		if (ItemsInBucket[h2] < BucketSize)
		{
			collisions += insertBucket(h2, item);
		}
		// otherwise put in overflow
		else
		{
			collisions += insertOverflow(item);
		}
	}

	return collisions;
}

template <typename K, typename D>
int twochoice<K, D>::insert( K key, D data )
{
	return insert(Item<K, D>(key, data));
}

template <typename K, typename D>
int twochoice<K, D>::insertBucket(int bucket, const Item<K, D>* item) {
	int collisions = 0;
	int position = bucket*BucketSize;

	// search through bucket for tombstone
	for (int p=position; p < position+BucketSize; p++)
		if( Table[p] == tombstone ) {
			Table[p] = item;
			break;
		} else {
			collisions++;
		}

	ItemsInBucket[bucket]++;

	return collisions;
}

template <typename K, typename D>
int twochoice<K, D>::insertOverflow(const Item<K, D>* item) {
	int collisions = 0;

	// search through overflow for a tombstone
	for (int i=0; i < Overflow.size(); i++)
		if (Overflow[i] == tombstone) {
			Overflow[i] = item;
			break;
		} else {
			collisions++;
		}

	Overflow.push_back(item);

	return collisions;
}

template <typename K, typename D>
int twochoice<K, D>::positionSearch( K key )
{
	int h1 = hash1( key );
	int h2 = hash2( key );

	// find the appropriate buckets
	int b1 = h1*BucketSize;
	int b2 = h2*BucketSize;

	// first search with the first hash function
	for( int i = 0; i < ItemsInBucket[h1]; i++ )
	{
		if( Table[b1 + i]->key == key )
			return(b1 + i);
	}
	// if nothing is found, use the second
	for( int i = 0; i < ItemsInBucket[h2]; i++ )
	{
		if( Table[b2 + i]->key == key )
			return(b2 + i);
	}
	// otherwise use overflow
	for( int i = 0; i < Overflow.size(); i++ )
	{
		if( Overflow[i] == tombstone )
			continue;
		else if( Overflow[i]->key == key )
			return  Table.size() + i;
	}

	return -1;

}

template <typename K, typename D>
Item<K, D> twochoice<K, D>::search( K key ) {
	int p = positionSearch(key);

	assert(p != -1);
	if( p >= Table.size() )
		return *Overflow[p-Table.size()];
	else
		return *Table[p];
}

//tombstone is -1 for the time being
template <typename K, typename D>
void twochoice<K, D>::remove( K key )
{
	int position = positionSearch( key );
	if( position >= Table.size() )
		Overflow[position-Table.size()] = tombstone;
	else {
		Table[position] = tombstone;
		ItemsInBucket[position/BucketSize]--;
	}
}

template <typename K, typename D>
int twochoice<K, D>::size( )
{
	return Table.size() + Overflow.size();
}

template <typename K, typename D>
twochoice<K, D>::~twochoice()
{
	for( int i = 0; i < Table.size(); i++ )
	{
		if( Table[i] != tombstone )
			delete Table[i];
	}

	for( int i = 0; i < Overflow.size(); i++ )
	{
		if( Overflow[i] != tombstone )
			delete Overflow[i];
	}

	delete tombstone;
}

#endif
