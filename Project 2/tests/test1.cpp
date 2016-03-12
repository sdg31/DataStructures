// Test 1

#include "../libraries/huffman.hpp"
#include "../libraries/stopwatch.hpp"

#include <iostream>

int main()
{ 
	StopWatch sw;
	const char* infile = "../inputs/bible.txt";
	const char* enfile = "../inputs/huff_bible.txt";
	const char* defile = "../inputs/bible2.txt";

	std::cout << "Creating HuffmanTree<char> ... ";
	sw.start();

    HuffmanTree<char, int> ht(infile);

    int height = ht.height();

    std::cout << "(" << sw.pause() << " ms) height: " << height << std::endl << "Encoding File ... ";
    sw.start();

    ht.encode(infile, enfile);

    std::cout << "(" << sw.pause() << " ms)" << std::endl << "Decoding File ... ";
    sw.start();

    ht.decode(enfile, defile);

    std::cout << "(" << sw.pause() << " ms)" << std::endl << "Complete..." << std::endl;

	return 0;
}
