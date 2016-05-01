#include "twochoice.hpp"

int main() {
	twochoice h;

	h.insert(3);
	std::cout << h.search(3) << std::endl << h << std::endl;

}