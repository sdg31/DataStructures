#include <iostream>
#include <vector>

//Class that uses a vector as a hash
struct Hash
{
private:
    //vector used for the hash table
    std::vector<int> HashTable1;
    std::vector<int> HashTable2;
    int Size;

public:
    //default initialize the hash table to be capacity 7 and fill it will -1 as the "empty" value
    Hash(int size) : HashTable1(size, -1), HashTable2(size, -1), Size(size) { }

    //insert the value into the hash table
    int insert1(int value)
    {
        int collisions = 0;

        if(isHash1Full() || isHash2Full())
            rehash(-1);

    	//find the index given by the first hash function
        int index1 = hash1(value);

	//if the index given by the first hash function is empty in the hash, put the value there and return
        if(HashTable1[index1] == -1)
        {
            HashTable1[index1] = value;
            return collisions;
        }
        collisions++;

	//find the index given by the second hash function
        int index2 = hash2(value);

	//if the index given by the second hash function is empty in the hash, put the value there and return
        if(HashTable2[index2] == -1)
        {
            HashTable2[index2] = value;
            return collisions;
        }
        collisions++;

        //save the popped value before changing it
        int poppedValue = HashTable1[index1];

	//replace the current value with the value being inserted
        HashTable1[index1] = value;

	//call insert2 to begin inserting while checking to see if an infinite cycle occurs
        return collisions + insert2(poppedValue);
    }

    //second insert function used to check if an infinite cycle is occurring
    int insert2(int value)
    {
    	int count = 0;
    	int currentValue = value;
    	int poppedValue;
        int collisions = 0;

    	//loop that continues until all values are inserted with no collisions or it attempts to insert more than 10 times
    	while(count != 10)
    	{

			++count;

			//find the index for value using the second hash function
			int index1 = hash1(currentValue);

			//set the value at the index in the hash table to be value if it is empty
			if(HashTable1[index1] == -1)
			{
				HashTable1[index1] = currentValue;
				return collisions;
			}
            collisions++;

			//find the index for value using the second hash function
			int index2 = hash2(currentValue);

			//set the value at the index in the hash table to be value if it is empty
			if(HashTable2[index2] == -1)
			{
				HashTable2[index2] = currentValue;
				return collisions;
			}
            collisions++;

			//save the popped value
			poppedValue = HashTable1[index1];

		//put the value in for the popped value
			HashTable1[index1] = currentValue;

			currentValue = poppedValue;
		}

        return collisions;
	}

    //searches for a given value in the hash table
    bool Find(int value)
    {
    		//if the value is in the hash table given by either hash function, return true
		if(HashTable1[hash1(value)] == value || HashTable2[hash2(value)] == value)
			return true;

		//if not found, return false
		return false;
	}

	//look for the value in the hash table and delete it if found
	void Delete(int value)
	{
		//if the value is in the hash table given by the index using the first hash function, change it to -1, or "empty"
		if(HashTable1[hash1(value)] == value)
		{
			HashTable1[hash1(value)] = -1;
			return;
		}

		//if the value is in the hash table given by the index using the second hash function, change it to -1, or "empty"
		if(HashTable2[hash2(value)] == value)
			HashTable2[hash2(value)] = -1;
	}

    //allocate more memory in the hash with the new size being the next biggest prime number and insert the last popped value
    void rehash(int value)
    {
    	//save the new size of the hash table
        int newSize = nextPrime(Size);

        //increase the size of the hash tables
        for(int i = 0; i < (newSize - Size); ++i)
        {
			HashTable1.push_back(-1);
			HashTable2.push_back(-1);
		}

        //set Size to be the new size of the hah tables
        Size = newSize;

		//insert the last popped value into the hash table if the value is not -1
        if(value != -1)
            insert1(value);

    }

    //check if the first hash table is full
    bool isHash1Full() const
    {
        for(int i = 0; i < Size; ++i)
        {
            if(HashTable1[i] == -1)
                return false;
        }
        return true;
    }

    //check if the second hash table is full
    bool isHash2Full() const
    {
        for(int i = 0; i < Size; ++i)
        {
            if(HashTable2[i] == -1)
                return false;
        }
        return true;
    }

    //the first hash function, the key mod size
    int hash1(int key)
    {
        return key % Size;
    }

    //the second hash function, the key squared mod size
    int hash2(int key)
    {
        return (key * key) % Size;
    }

    //checks if a number is prime
    bool isPrime( int n )
    {
        if( n == 2 || n == 3 )
            return true;

        if( n == 1 || n % 2 == 0 )
            return false;

        for( int i = 3; i * i <= n; i += 2 )
            if( n % i == 0 )
                return false;

        return true;
    }

    //finds the next prime number
    int nextPrime( int n )
    {
        if( n % 2 == 0 )
            ++n;

        for( ; !isPrime( n ); n += 2 )
            ;

        return n;
    }
};
