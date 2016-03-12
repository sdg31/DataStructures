#ifndef SORTVECTOR_HPP
#define SORTVECTOR_HPP

#include "node.hpp"
#include "iohelper.hpp"

#include <vector>

// this is a vector that maintains a
// sorted order for faster searches
template<typename D, typename W>
struct SortVector {
private:
	std::vector<Leaf<D, W>*> _v;
	int binary_search(D d, int, int, bool&);

public:
	SortVector(const char*);
	std::vector<Leaf<D, W>*> get_vector();
	void insert(D d);
};

// returns the internal vector
template<typename D, typename W>
std::vector<Leaf<D, W>*> SortVector<D, W>::get_vector() {
	return _v;
}

// uses binary search to find a Leaf Node
// returns the index of the Node if found (was_found == true)
// returns the index to insert if not found (was_found == false)
template<typename D, typename W>
SortVector<D, W>::SortVector(const char* file_name) {
	std::ifstream ifile;

	ifile.open(file_name);
	while(!ifile.eof())
		insert(get(ifile, new D()));

	ifile.close();
}

// uses binary search to find a Leaf Node
// returns the index of the Node if found (was_found == true)
// returns the index to insert if not found (was_found == false)
template<typename D, typename W>
int SortVector<D, W>::binary_search(D d, int min, int max, bool& was_found) {
	// not found, insert at the min
	// when they invert the min contains
	// the index it belongs
	if (max < min) {
		was_found = false;
		return min;
	}		
	else {
		int mid = min + (max-min)/2;

		if (_v[mid]->data() > d)
			return binary_search(d, min, mid-1, was_found);
		if (_v[mid]->data() < d)
			return binary_search(d, mid+1, max, was_found);
		else {
			was_found = true;
			return mid;
		}
	}
}

// this either adds the leaf node if it was not found
// or it will increase the weight of a leaf node if it
// already exists
template<typename D, typename W>
void SortVector<D, W>::insert(D d) {
	bool was_found = false;
	int index = binary_search(d, 0, _v.size()-1, was_found);

	if (was_found)
		_v[index]->inc_weight();
	else
		_v.insert(_v.begin()+index, new Leaf<D, W>(d, 1));
}

#endif
