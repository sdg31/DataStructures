#ifndef TWOCHOICE_HPP
#define TWOCHOICE_HPP

#include <vector>
#include <iostream>
#include <string>
#include <cassert>

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
	twochoice();
	int hash1( int key );
	int hash2( int key );
	int hash1( std::string key );
	int hash2( std::string key );

	void insert( Item<K, D> item );
	int positionSearch( K key );
	Item<K, D> search( K key );
	void remove( K key );

	// ostream for hash table contents
	template <typename K1, typename D1>
	friend std::ostream& operator<<(std::ostream& os, const twochoice<K1, D1>& h);

private:
	// tombstone variable
	const Item<K, D>* tombstone;
	//the main hash table
	std::vector<const Item<K, D>* > Table;
	// overflow table, items inserted into a full bucket go here
	std::vector<const Item<K, D>* > Overflow;

	std::vector<int> ItemsInBucket;
	int AmountBuckets;
};

// ostream for item
template <typename K, typename D>
std::ostream& operator<<(std::ostream& os, const Item<K, D>& item) {
	return os << "key: " << item.key << " data: " << item.data;
}

// ostream for hash table contents
template <typename K, typename D>
std::ostream& operator<<(std::ostream& os, const twochoice<K, D>& h) {
	for (int i=0; i < h.Table.size(); i++)
		os << *h.Table[i] << std::endl;

	for (int i=0; i < h.Overflow.size(); i++)
		os << *h.Overflow[i] << std::endl;

	os << std::endl;

	return os;
}

// for speed purposes, you might as well
// initialize a bit of space in each vector
// rather than overflowing a bunch of times
// (overflowing as in running out of space in a vector,
// not a bucket)
template <typename K, typename D>
twochoice<K, D>::twochoice()
	:tombstone(new Item<K, D>()), Table( 130, tombstone ), AmountBuckets( Table.size() / 10 ),
	 ItemsInBucket(Table.size() / 10, 0 ) 
{
}

// for the time being, these hash functions
// return modulo of two different prime numbers
// they could be more complicated, but for testing
// this will work
template <typename K, typename D>
int twochoice<K, D>::hash1( int key )
{
	return key % 13;
}

template <typename K, typename D>
int twochoice<K, D>::hash2( int key )
{
	return key % 7;
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
void twochoice<K, D>::insert( Item<K, D> tempItem )
{
	const Item<K, D>* item = new Item<K, D>(tempItem.key, tempItem.data);
	
	int h1 = hash1( item->key );
	int h2 = hash2( item->key );

	if( ItemsInBucket[h1] <= ItemsInBucket[h2])
	{
		int position = h1*10 + ItemsInBucket[h1];
		if( position < h1*10 + 10 )
		{
			//if the position is empty, insert
			if( Table[position] == tombstone )
				Table[position] = item;
		}
		else
		{
			Overflow.push_back( item );
		}

		ItemsInBucket[h1]++;
	}
	else
	{
		int position = h2*10 + ItemsInBucket[h2];

		if( Table[position] == tombstone )
			Table[position] = item;

		ItemsInBucket[h2]++;
	}
}

template <typename K, typename D>
int twochoice<K, D>::positionSearch( K key )
{
	int h1 = hash1( key );
	int h2 = hash2( key );

	// find the appropriate buckets
	int b1 = h1*10;
	int b2 = h2*10;

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
	else
		Table[position] = tombstone;
}

#endif
