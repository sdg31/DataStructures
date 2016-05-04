#include <iostream>
#include "HashTable.hpp"

using namespace std;


int main(int argc, char** argv) {

    int elements = stoi(argv[2]);

    HashTable<int> hashtable(stoi(argv[1]));

    vector<int> input;
    input.reserve(elements);
    
    for(int i=0;i<elements;++i){
        cin >> input[i];
        hashtable.load(input[i]);
    }


    cout << "\nHash table: ";
    hashtable.showTable();

    return 0;
}


