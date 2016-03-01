#include "unionfind.hpp"

// basic constructor taking the size of the tree as input
UnionFind::UnionFind(int size): _size(size), _tree(new int[size]), _weights(new int[size]) {
	for (int i=0; i < size; i++) {
		_tree[i] = -1;
		_weights[i] = 1;
	}
}

// destructor deallocates arrays
UnionFind::~UnionFind() {
	delete _tree;
	delete _weights;
}

// merge is used to union two nodes
void UnionFind::merge(int a, int b) {
	int r1 = find(a);
	int r2 = find(b);

	// this reorders so that if they are equal weight
	// the lesser value chronologically is chosen as root
	int temp = r1;
	if (r2 < temp) {
		r1 = r2;
		r2 = temp;
	}

	if (r1 != r2) {
		if (_weights[r2] > _weights[r1]) {
			_tree[r1] = r2;
			_weights[r2] += _weights[r1];
		} else {
			_tree[r2] = r1;
			_weights[r1]+= _weights[r2];
		}
	}
}

// this finds the root for the selected node
int UnionFind::find(int cur) {
	if (_tree[cur] == -1) return cur;
	while(_tree[cur] != -1) cur = _tree[cur];
	return cur;
}

// this is a basic print
void UnionFind::print() {
   for (int i=0; i < _size; i++) {
    	std::cout << _tree[i] << " ";
    }
    std::cout << std::endl;
}