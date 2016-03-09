// Test 1 is used to compare the time of N enqueues
// followed by N dequeues on our queue vs the std::queue

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

#include <iostream>

int main()
{ 
    HuffmanTree<char, int> ht("../inputs/file1.txt");

    std::cout << ht.get_code('!') << std::endl;

	return 0;
}