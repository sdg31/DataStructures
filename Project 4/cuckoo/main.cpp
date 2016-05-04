#include <iostream>
#include <vector>
#include "cuckoo_Hashing.hpp"
#include "Complexity_Timer.hpp"


int main()
{
    Hash hashTable;
    timer t;

    int i = 0;
    int v = 1;
    int d = 1;
    int f = 1;

    // Test to insert 100000 elements 10 times
    t.restart();
    do{
        for(i; i < 100000; ++i){
        hashTable.insert1(i);
        }
        t.record();
        t.stop();
        std::cout << "Inserting 100000 elements test " << v << ":" << t.time() << "\n";
        ++v;
    }while(v < 11);

    std::cout << "\n";


    do{
        for(i; i < 100000; ++i){
        hashTable.insert1(i);
        hashTable.Find(i);
        }

        t.record();
        t.stop();
        std::cout << "Finding 100000 elements test " << f << ":" << t.time() << "\n";
        ++f;
    }while(f < 11);

    std::cout << "\n";

    // Test to delete 100000 elements 10 times
    t.restart();
    do{
        for(i; i < 100000; ++i){
        hashTable.insert1(i);
        hashTable.Delete(i);
        }

        t.record();
        t.stop();
        std::cout << "Deleting 100000 elements test " << d << ":" << t.time() << "\n";
        ++d;
    }while(d < 11);

	return 0;
}
