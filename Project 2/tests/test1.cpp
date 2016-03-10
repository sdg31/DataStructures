// Test 1

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

#include <iostream>

int main()
{ 
    HuffmanTree<char, int> ht("../inputs/file1.txt");

    std::cout << ht.get_code('T') << std::endl;

    ht.encode("../inputs/file1.txt", "../inputs/file2.txt");

	return 0;
}
