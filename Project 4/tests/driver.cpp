#include "twochoice.hpp"

int main() {
	std::cout << "intializing hash table..." << std::endl;
	twochoice<int, std::string> h;
	
	h.insert(Item<int, std::string>(3, "testing"));
	std::cout << h.search(3) << std::endl;
}