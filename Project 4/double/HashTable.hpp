
#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <vector>
#include <iostream>
#include <cmath>

namespace dhash
{

enum Tombstone {
    Empty,
    Deleted
};

template <typename T>
class HashTable {
private:
    std::vector<T> table;
    int size, col;
    Tombstone type;
public:
    HashTable(int s):
        table(),
        type(Empty),
        size(s),
        col(0)
    {
        makeNewTable();
    }

    ~HashTable(){table.clear();}

    void makeNewTable(){
        table.reserve(size);
        for(int i=0;i<=size;++i) table.push_back(type);
    }

    void setTableSize(int s){size = s;}

    void showTable(){
        for(int i=0;i<getSize();++i){
            std::cout << "\nPosition " << i << ": " << table[i];
        }
        std::cout << "\nTotal collisions: " << col << std::endl;
    }

     void load(T value){
        int home = firstHash(value),
            step = secondHash(value);

        while(getStatus(home) != Empty ) {
            if(getStatus(home) == Deleted) break;

            ++col;
            home +=step;
            if(home > size) home -= size;
        }
        table[home] = value;
    }

    void remove(T value){
        int index = find(value);
        table[index] = Deleted;
    }

    /* TODO: implement case where value not found*/
    int find(T value){
        int home = firstHash(value),
            step = secondHash(value);

        while(table[home]!=value) {
            home += step;
            if(home >size) home -= size;
        }
        return home;
    }

    int getSize() { return size;}
    int getStatus(int index) {return table[index];}
    int getCollisions(){return col;}

    int firstHash(int key){ return key % size;}

    int secondHash(int key){
        int prime = findPrimeLessThan(size);
        int step = (prime -(key % prime)) + 1;
        return step;
    }

    int findPrimeLessThan(int num){

        bool isPrime = false;
        while(!isPrime) {
            int sq = floor(sqrt(--num));
            for (int i = sq; i > 1; --i) {
                if (!(num%i)) {
                    isPrime = false;
                    break;
                }
                isPrime = true;
            }
        }
        return num;
    }
};

}



#endif //HASH_TABLE_HPP
