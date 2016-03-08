// Test 1

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

#include <iostream>

int main()
{ 
    HuffmanBuilder<char, int> hb;

    hb.add('!', 6);
    hb.add('@', 3);
    hb.add('#', 14);
    hb.add('^', 12);
    hb.add('%', 66);
    hb.add('$', 3);

    HuffmanTree<char, int>* ht = hb.create();

    std::cout << ht->get_code('!') << std::endl;
    std::cout << ht->get_code('@') << std::endl;
    std::cout << ht->get_code('#') << std::endl;
    std::cout << ht->get_code('^') << std::endl;
    std::cout << ht->get_code('%') << std::endl;
    // this is to test if it's not in the tree
    std::cout << ht->get_code('*') << std::endl;
    std::cout << ht->get_code('$') << std::endl;

	return 0;
}
