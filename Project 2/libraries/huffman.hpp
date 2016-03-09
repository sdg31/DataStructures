#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "minqueue.hpp"

#include <string>

// forward declaration of Huffman Builder
template<typename D, typename W>
class HuffmanBuilder;

// this is the Huffman Tree class
template<typename D, typename W>
class HuffmanTree {
private:
	Node<D, W>* _root;
	std::string get_code(Node<D, W>*, D d, std::string code);

public:
	HuffmanTree(const char* file_name): HuffmanTree(HuffmanBuilder<D, W>(file_name)) { }
	HuffmanTree(HuffmanBuilder<D, W> hb): HuffmanTree(hb.create()) { }
	HuffmanTree(Node<D, W>* r): _root(r) { }
	std::string get_code(D d);
};

// recursively searches for a key and returns it's code
template<typename D, typename W>
std::string HuffmanTree<D, W>::get_code(D d) {
	return get_code(_root, d, "");
}

// recursively searches for a key and returns it's code
template<typename D, typename W>
std::string HuffmanTree<D, W>::get_code(Node<D, W>* n, D d, std::string code) {
	// on a leaf node return either a code or empty if no code
	if (n->is_leaf()) {
		if (dynamic_cast<Leaf<D, W>*>(n)->data() == d)
			return code;
		else
			return "";
	}
	// on an internal node search the sides and return 
	else {
		Internal<D, W>* temp_node = dynamic_cast<Internal<D, W>*>(n);
		std::string temp_code;

		temp_code = get_code(temp_node->left(), d, code+"0");
		if (!temp_code.empty())
			return temp_code;
		else
			return get_code(temp_node->right(), d, code+"1");
	}
}

// This class is used to help in constructing the
// Huffman Tree
template<typename D, typename W>
class HuffmanBuilder {
private:
	MinQueue<D, W> _nodes;

public:
	HuffmanBuilder(const char* file_name): _nodes(MinQueue<D, W>(file_name)) { }
	void add(D d, W w) { _nodes.add(d, w); }
	void add(Node<D, W>* l, Node<D, W>* r) { _nodes.add(l, r); }
	Node<D, W>* create();
};

// This function creates a Huffman Tree
// from all of the nodes that have been added
template<typename D, typename W>
Node<D, W>* HuffmanBuilder<D, W>::create() {
	// while there is more than one node left in the queue
	// keep paring the lowest two and adding that back into
	// the queue
	while (_nodes.size() > 1) {
		_nodes.add(_nodes.remove(), _nodes.remove());
	}

	return _nodes.remove();
}


#endif
