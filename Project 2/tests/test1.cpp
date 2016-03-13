// Test 1
// encodes and decodes the file by character

#include "huffman.hpp"
#include "stopwatch.hpp"

#include <iostream>

int main()
{ 
	StopWatch sw;
    std::string file = "bible";
    
	std::string infile = "../inputs/" + file + ".txt";
	std::string enfile = "../encoded/" + file + "_char.txt";
	std::string defile = "../decoded/" + file + "_char.txt";

	std::cout << "Creating HuffmanTree<char> ... ";
	sw.start();

    HuffmanTree<char, int> ht(infile.c_str());

    int height = ht.height();

    std::cout << "(" << sw.pause() << " ms) height: " << height << std::endl << "Encoding File " << file << ".txt ... ";
    sw.start();

    ht.encode(infile.c_str(), enfile.c_str());

    std::cout << "(" << sw.pause() << " ms)" << std::endl << "Decoding File " << file << "_char.txt ... ";
    sw.start();

    ht.decode(enfile.c_str(), defile.c_str());

    std::cout << "(" << sw.pause() << " ms)" << std::endl << "Complete..." << std::endl;

	return 0;
}
