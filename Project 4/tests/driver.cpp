#include "twochoice.hpp"

int main() {
	std::cout << "intializing hash table..." << std::endl;
	twochoice<std::string, double> h;

	h.insert("pi", 3.141592654);
	std::cout << h.search("pi") << std::endl << std::endl << h  << std::endl;

	h.remove("pi");
	std::cout << h << std::endl;

	return 0;
}