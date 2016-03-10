// Test 1

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

#include <iostream>

int main()
{ 
    HuffmanTree<char, int> ht("../inputs/file1.txt");

    ht.encode("../inputs/file1.txt", "../inputs/file2.txt");

    ht.decode("../inputs/file2.txt", "../inputs/file3.txt");

	return 0;
}
