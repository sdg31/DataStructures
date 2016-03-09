// Test 1

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

#include <iostream>

int main()
{ 
    HuffmanTree<char, int> ht("../inputs/file1.txt");

    std::cout << ht.get_code('!') << std::endl;

	return 0;
}
