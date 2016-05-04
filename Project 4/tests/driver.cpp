// this prints out collision numbers that can be printed in Matlab

#include "twochoice.hpp"
#include "hash.hpp"
#include "HashTable.hpp"

#include <fstream>
#include <math.h>

// reads the file given to us by a collaborating group
void read_test_data(std::vector<int>&);
void print(int[], int, std::string);

int main() {
	std::cout << "reading in test data..." << std::endl;
	std::vector<int> data(2000000);
	read_test_data(data);

	int lengths[5] = {101, 1009, 10007, 100003, 1000003};

	// for each test length
	for (int i = 0; i < 5; i++) {

		// arrays to hold execution times for each length
		int c1[9];
		int c2[9];
		int c3[9];
		
		// show inserting from 10% to 90% load
		for (int percent = 1; percent < 10; percent++) {
			// initializing tables
			twochoice<int, int> h1(lengths[i]);
			HashTable<int> h2(lengths[i]);
			dhash::HashTable<int> h3(lengths[i]);

			int collisions = 0;

			// insert to the specified percentage of the table size
			for (int j=0; j < round(((double)percent/10)*lengths[i]); j++) {
				// two-choice hashing
				collisions += h1.insert(data[j], data[j]);

				// quadratic probing
				h2.insert(data[j], data[j]);

				// double hashing
				h3.load(data[j]);
			}

			c1[percent-1] = collisions;
			c2[percent-1] = h2.initialcollisions + h2.totalprobes;
			c3[percent-1] = h3.getCollisions();
		}

		std::cout << "% collisons from 10% - 90% full, " << lengths[i] << " items" << std::endl;
		print(c1, 9, "tc" + std::to_string(lengths[i]));
		print(c2, 9, "q" + std::to_string(lengths[i]));
		print(c3, 9, "d" + std::to_string(lengths[i]));
		std::cout << std::endl;
	}

	return 0;
}

// reads the file given to us by a collaborating group
void read_test_data(std::vector<int>& v) {
	std::ifstream f("../inputs/test_data.txt");
	int i=0;

	for (std::string line; std::getline(f, line); i++)
    {
        v[i] = std::stoi(line);
    }
}

void print(int v[], int size, std::string name) {
		std::cout << name << " = [";
		for (int i=0; i < size; i++)
			std::cout << v[i] << " ";

		std::cout << "];" << std::endl;
}
