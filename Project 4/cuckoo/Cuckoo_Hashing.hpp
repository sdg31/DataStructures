
#include <iostream>
#include <vector>

//Class that uses a vector as a hash
struct Hash
{
private:
    //vector used for the hash table
    std::vector<int> HashTable1;
	std::vector<int> HashTable2;

public:
    //default initialize the hash table to be capacity 7 and fill it will -1 as the "empty" value
    Hash()
    {
		HashTable1.reserve(100000);
        for(int i = 0; i < HashTable1.capacity(); ++i)
            HashTable1.push_back(-1);

        HashTable2.reserve(100000);
        for(int i = 0; i < HashTable2.capacity(); ++i)
            HashTable2.push_back(-1);
    }

    //insert the value into the hash table
    void insert1(int value)
    {
        if(!isHash1Full() || !isHash2Full())
            rehash(-1);

    	//find the index given by the first hash function
        int index1 = hash1(value);

	//if the index given by the first hash function is empty in the hash, put the value there and return
        if(HashTable1[index1] == -1)
        {
            HashTable1[index1] = value;
            return;
        }

	//find the index given by the second hash function
        int index2 = hash2(value);

	//if the index given by the second hash function is empty in the hash, put the value there and return
        if(HashTable2[index2] == -1)
        {
            HashTable2[index2] = value;
            return;
        }

	//create a vector to store the values that have been popped out of their location in the hash table
        std::vector<int> StoredValues;

        //save the popped value before changing it
        int poppedValue = HashTable1[index1];

	//replace the current value with the value being inserted
        HashTable1[index1] = value;

	//call insert2 to begin inserting while checking to see if an infinite cycle occurs
        insert2(poppedValue, StoredValues);
    }

    //second insert function used to check if an infinite cycle is occurring
    void insert2(int value, std::vector<int> storedValues)
    {
    	//check the stored values vector to see if the value has already been attempted to be inserted this cycle
        for(int i = 0; i < storedValues.size(); ++i)
        {
            //if the value is in the vector, call the rehash function to remake the hash and insert value into that hash
            if(value == storedValues[i])
            {
                rehash(value);
                return;
            }
        }

	//push the value into the vector so if we attempt to re insert it again in this cycle it will be stopped
        storedValues.push_back(value);

		//find the index for value using the second hash function
        int index1 = hash1(value);

	//set the value at the index in the hash table to be value if it is empty
        if(HashTable1[index1] == -1)
        {
            HashTable1[index1] = value;
            return;
        }

	//find the index for value using the second hash function
        int index2 = hash2(value);

	//set the value at the index in the hash table to be value if it is empty
        if(HashTable2[index2] == -1)
        {
            HashTable2[index2] = value;
            return;
        }

	//save the popped value
        int poppedValue = HashTable1[index1];

	//put the value in for the popped value
        HashTable1[index1] = value;

	//recall itself with the new popped value and updated stored values vector
        insert2(poppedValue, storedValues);

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
    	//save the size of the hash table
        int capacity = HashTable1.capacity();

        //allocate more memory that is the next biggest prime number
        HashTable1.reserve(nextPrime(capacity));

	//make all the newly allocated slots -1, or "empty"
        for(int i = capacity; i < HashTable1.capacity(); ++i)
            HashTable1.push_back(-1);

        //allocate more memory that is the next biggest prime number
        HashTable2.reserve(nextPrime(capacity));

	//make all the newly allocated slots -1, or "empty"
        for(int i = capacity; i < HashTable2.capacity(); ++i)
            HashTable2.push_back(-1);

	//insert the last popped value into the hash table if the value is not -1
        if(value != -1)
            insert1(value);

    }

    //check if the first hash table is full
    bool isHash1Full() const
    {
        for(int i = 0; i < HashTable1.capacity(); ++i)
        {
            if(HashTable1[i] == -1)
                return false;
        }
        return true;
    }

    //check if the second hash table is full
    bool isHash2Full() const
    {
        for(int i = 0; i < HashTable2.capacity(); ++i)
        {
            if(HashTable2[i] == -1)
                return false;
        }
        return true;
    }

    //the first hash function, the key mod size
    int hash1(int key)
    {
        return key % HashTable1.capacity();
    }

    //the second hash function, the key squared mod size
    int hash2(int key)
    {
        return (key * key) % HashTable1.capacity();
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
