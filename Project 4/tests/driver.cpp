#include "twochoice.hpp"

#include <fstream>

// reads the file given to us by a collaborating group
void read_test_data(std::vector<int>&);

int main() {
	std::cout << "reading in test data..." << std::endl;
	std::vector<int> data(2000000);
	read_test_data(data);

	std::cout << "intializing hash table..." << std::endl;
	twochoice<int, int> h(103);
	int collisions = 0;

	for (int i=0; i < 93; i++)
		collisions += h.insert(data[i], data[i]);

	std::cout << collisions << " " << h.size() << std::endl;

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
