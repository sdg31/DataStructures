#include "twochoice.hpp"

#include <fstream>
#include <math.h>

// reads the file given to us by a collaborating group
void read_test_data(std::vector<int>&);

int main() {
	std::cout << "reading in test data..." << std::endl;
	std::vector<int> data(2000000);
	read_test_data(data);

	int lengths[5] = {101, 1009, 10007, 100003, 1000003};

	// for each test length
	for (int i = 0; i < 1; i++) {
		std::cout << "intializing hash table with " << lengths[i] << " elements..." << std::endl;
		twochoice<int, int> h(lengths[i]);
		long long int collisions = 0;

		for (int j=0; j < round(0.50*lengths[i]); j++)
			collisions += h.insert(data[j], data[j]);

		std::cout << "collisions: " << std::endl;
		std::cout << collisions << std::endl;
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
