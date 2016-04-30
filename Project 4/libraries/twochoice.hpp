#ifndef TWOCHOICE_HPP
#define TWOCHOICE_HPP


// two-choice hashing uses two unrelated hash functions,
// and puts the result in the bucket that is less full
class twochoice
{
public:
	int hash1( int key );
	int hash2( int key );
}

#endif