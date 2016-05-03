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
	int linearProbe(int position, const Item<K, D>* item);
	int positionSearch( K key );
	int linearPositionSearch( int position, K key );
	bool is_empty(const Item<K, D>* item);
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

	std::vector<int> Weight;
	int AmountBuckets;

	int GP; // greatest prime factor less than half of the size
	int SGP; // second greatest prime factor less than half of the size
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
		if (h.Table[i] == h.tombstone)
			os << "tombstone" << std::endl;
		else if (h.Table[i] == nullptr)
			os << "empty" << std::endl;
		else
			os << *h.Table[i] << std::endl;
	}

	os << "-----overflow----" << std::endl;
	for (int i=0; i < h.Overflow.size(); i++) {
		if (h.Overflow[i] == h.tombstone)
			os << "tombstone" << std::endl;
		else if (h.Overflow[i] == nullptr)
			os << "empty" << std::endl;
		else
			os << *h.Overflow[i] << std::endl;
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
	:tombstone(new Item<K, D>()), BucketSize(round(log2(log2(size))))
{ 
	// upgrade to table size divisible by bucket size
	for (int i = 0; i < BucketSize; i++)
		if ((size+i) % BucketSize == 0) {
			AmountBuckets = (size+i) / BucketSize;
			break;
		}

	// vector to hold weight of all buckets
	Weight = std::vector<int>( AmountBuckets, 0 );

	// intialize the table
	Table = std::vector<const Item<K, D>* >( AmountBuckets*BucketSize, nullptr );

	// these primes are used for the separate hashes
	// they contain the greatest primes below
	// half of the array
	GP = greatest_prime(AmountBuckets*BucketSize / 2);
	SGP = greatest_prime( GP - 1 );
}

// for the time being, these hash functions
// return modulo of two different prime numbers
// they could be more complicated, but for testing
// this will work
template <typename K, typename D>
int twochoice<K, D>::hash1( int key )
{
	return key % GP;
}

template <typename K, typename D>
int twochoice<K, D>::hash2( int key )
{
	return (Table.size()/2) + (key % SGP);
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
	Weight[h1/BucketSize]++;

	int h2 = hash2( item->key );
	Weight[h2/BucketSize]++;

	if (Weight[h1/BucketSize] <= Weight[h2/BucketSize])
	{
		collisions += linearProbe(h1, item);
	}
	else 
	{
		collisions += linearProbe(h2, item);
	}

	return collisions;
}

template <typename K, typename D>
int twochoice<K, D>::insert( K key, D data )
{
	return insert(Item<K, D>(key, data));
}

template <typename K, typename D>
int twochoice<K, D>::linearProbe(int position, const Item<K, D>* item) {
	int collisions = 0;
	int start = position;

	do {
		if (is_empty(Table[position])) {
			Table[position] = item;
			break;
		} 
		else {
			++collisions;
		}

		position = (position + 1) % Table.size();
	} while (position != start);

	if (position == start && Table[position] != item)
		Overflow.push_back(item);

	return collisions;
}

template <typename K, typename D>
int twochoice<K, D>::positionSearch( K key )
{
	int h1 = hash1( key );
	int h2 = hash2( key );

	int first, second, result = 0;

	if (Weight[h1/BucketSize] <= Weight[h2/BucketSize]) {
		first = h1;
		second = h2;
	} else {
		first = h2;
		second = h1;
	}

	result = linearPositionSearch(first, key);

	if (result == -1) // was not found before an empty space
		result = linearPositionSearch(second, key);

	if (result > -1)
		return result;

	for (int i=0; i < Overflow.size(); i++)
		if (Overflow[i] != tombstone && Overflow[i]->key == key)
			return Table.size() + i;

	return -1;
}

template <typename K, typename D>
int twochoice<K, D>::linearPositionSearch( int position, K key ) {
		int start = position;

		do {
			if (Table[position] == nullptr)
				return -1;
			else if (Table[position] != tombstone && Table[position]->key == key)
				return position;

			position = (position + 1) % Table.size();
		} while (position != start);

		return -2; // was not found at all
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
	else
		Table[position] = tombstone;
}

template <typename K, typename D>
int twochoice<K, D>::size( )
{
	return Table.size() + Overflow.size();
}

template <typename K, typename D>
bool twochoice<K, D>::is_empty(const Item<K, D>* item) {
	return (item == tombstone || item == nullptr);
}

template <typename K, typename D>
twochoice<K, D>::~twochoice()
{
	for( int i = 0; i < Table.size(); i++ )
	{
		if( !is_empty(Table[i]) )
			delete Table[i];
	}

	for( int i = 0; i < Overflow.size(); i++ )
	{
		if( !is_empty(Overflow[i]) )
			delete Overflow[i];
	}

	delete tombstone;
}

#endif
