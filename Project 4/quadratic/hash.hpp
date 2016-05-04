#ifndef HASH_HPP
#define HASH_HPP
#include <vector>
#include <iostream>
//using namespace std;
void quadratic_probing_insert(int *hashtable, int size, int *randomArray);
void quadratic_probing_deletion(int *hashtable, int size,int *randomArray);

//A hash table that stores key-value pairs with integer keys and values of
//type T.  Quadratic probing is used as a table resolution policy
template <typename T>
class HashTable
{
   //the table size
   int size;
   //the actual table
   std::vector<std::pair<int,T*>> table;
   //a pair used to designate an empty table location
   const std::pair<int,T*> nullpair = {0,nullptr}; 
   //a pair used to mark a deleted item
   std::pair<int,T*> tombstone;

   public:
      //These member variables are used for analysis purposes only
      //if testing actual time performance, they should be removed

      //the total probes beyond initial hash made by all insertions
      int totalprobes;   

      //the total number of insertions that mapped to the initial hash
      int samehash;

      //the total number of collisions caused because the keys mapped to
      //the same the initial location 
      int initialcollisions;

     //public constructor taking a hash table size 
     HashTable(int size):size(size),table(size)
     {
         //initialize analysis variables
         totalprobes=0;
         samehash=0;
         initialcollisions=0;

         //allocate the the table 
         table.reserve(size);

         //initialize table with nulls
         for(int i=0;i<size;++i)
		table.push_back(nullpair);
         //initialize the tombstone
         tombstone.first=0;
         tombstone.second=new T();
          
     } 

     //a destructor to release allocated elements
     ~HashTable()
     {
         for(int i=0;i<size;++i)
         {
	     if(table[i]!=tombstone && table[i]!=nullpair)
                delete table[i].second;
         }
         delete tombstone.second;
     }
         
     //inserts a key value pair into the hash
     void insert(int key, T value)
     {
        int hash=key % size;  //gets original hashing position
        int j=0;              //used for quadrative probing

        //if space to hash to is not empty, probe
        while (table[hash]!=nullpair && table[hash]!=tombstone)
        {
              //for analysis purposes increment probe counter if collision
              if(j>0) ++totalprobes;  

              hash=(key+(j*j))%size;  //quadradic probing alrogithm.

              //for analysis purposes increment if secondary clustering 
              if(key%size==table[hash].first%size) ++samehash;

              j++;
        }

        //increment if there were any collissions at all
        if(j>1)++initialcollisions; 
        
        //Add key-value pair to table
        table[hash].first=key;
        table[hash].second=new T(value); 

     }

     //erases a key value pair from the hash.  if the key is not present, no
     //value is returned.
     void erase(int key)
     {
         for (int i=0; i<size; i++)
         {
             int j=0;
             int hash=key % size;//initial hashing position

             //if hashing space does not contain the element, probe
             while (table[hash].first!=key)
             {
                 //key is not in the table, so exit
                 if(table[hash]==nullpair)
                    return; 
                 //quadradic probing algorithm
                 hash=((key%size)+(j*j)%size);
                 j++;
             }
             //delete the element and add a tombstone
             delete table[hash].second;
             table[hash]=tombstone;
         }
     }

     //lookup operator.  returns the value element for a key
     T& operator[] (int key)
     {
        int hash=key % size;//initial hashing position
        int j=0;

        //if space to hash to is not empty, probe
        while (table[hash]!=nullpair && table[hash].first!=key)
        {
              hash=(key+(j*j))%size;//quadradic probing alrogithm.
              j++;
        }
        return *(table[hash].second);
     }

     //constant lookup operator.  returns the value element for a key
     const T& operator[] (int key) const     
     {
        int hash=key % size;//initial hashing position
        int j=0;
        
        //if space to hash to is not empty, probe
        while (table[hash]!=nullpair && table[hash].first!=key)
        {
              hash=(key+(j*j))%size;//quadradic probing alrogithm.
              j++;
        }
        return *(table[hash].second);
     }


     //prints out the hash table
     void print()
     {
         for (int i=0;i<size;++i)
         {
            
            std::cout << i <<"    "<<table[i].first << ",";
            if (table[i].second == nullptr)
                std::cout<<table[i].second << "\n" ;
            else if (table[i]==tombstone)
                std::cout<<"Tombstone\n";
            else 
                std::cout<<*(table[i].second) << "\n" ;
         }
     }

};




#endif
