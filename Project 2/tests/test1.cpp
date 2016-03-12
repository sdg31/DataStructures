// Test 1

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

int main()
{ 
	StopWatch sw;

	std::cout << "Creating Huffman Tree ... ";
	sw.start();

    HuffmanTree<char, int> ht("../inputs/bible.txt");

    std::cout << "(" << sw.pause() << ")" << std::endl << " Encoding File ... ";
    sw.start();

    ht.encode("../inputs/bible.txt", "../inputs/huff_bible.txt");

    std::cout << "(" << sw.pause() << ")" << std::endl << " Decoding File ... ";
    sw.start();

    ht.decode("../inputs/huff_bible.txt", "../inputs/bible2.txt");

    std::cout << "(" << sw.pause() << ")" << std::endl << " Complete" << std::endl;

	return 0;
}
