// Test 1
// encodes and decodes the file by words

#include "huffman.hpp"
#include "stopwatch.hpp"

#include <iostream>

int main()
{ 
	StopWatch sw;
    std::string file = "bible";
    
	std::string infile = "../inputs/" + file + ".txt";
	std::string enfile = "../encoded/" + file + "_string.txt";
	std::string defile = "../decoded/" + file + "_string.txt";

	std::cout << "Creating HuffmanTree<std::string> ... ";
	sw.start();

    HuffmanTree<std::string, int> ht(infile.c_str());

    int height = ht.height();

    std::cout << "(" << sw.pause() << " ms) height: " << height << std::endl << "Encoding File ... ";
    sw.start();

    ht.encode(infile.c_str(), enfile.c_str());

    std::cout << "(" << sw.pause() << " ms)" << std::endl << "Decoding File ... ";
    sw.start();

    ht.decode(enfile.c_str(), defile.c_str());

    std::cout << "(" << sw.pause() << " ms)" << std::endl << "Complete..." << std::endl;

	return 0;
}
