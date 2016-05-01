#include "twochoice.hpp"

int main() {
	std::cout << "intializing hash table..." << std::endl;
	twochoice<int, int> h;

	h.insert(Item<int, int>(3, 9000));
	std::cout << h.search(3) << std::endl;

	return 0;
}