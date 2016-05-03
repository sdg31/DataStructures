#include "twochoice.hpp"

int main() {
	std::cout << "intializing hash table..." << std::endl;
	twochoice<std::string, double> h;

	std::cout << h.insert("pi", 3.141592654) << std::endl;
	std::cout << h.search("pi") << std::endl;

	return 0;
}