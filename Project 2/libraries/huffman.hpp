#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "minqueue.hpp"

#include <string>
#include <iostream>

// character to terminate huffman file
const char END_HUFF = 0xFF;

// forward declaration of Huffman Builder
template<typename D, typename W>
class HuffmanBuilder;

// this is the Huffman Tree class
template<typename D, typename W>
class HuffmanTree {
private:
	Node<D, W>* _root;
	std::string get_code(Node<D, W>*, D d, std::string code);
	int height(Node<D, W>*);
	void write_code(std::ofstream&, D, bool = false);
	D find_item(Node<D, W>*, const std::string&, int);
	std::string char_as_binary_string(char);

public:
	HuffmanTree(const char* file_name): HuffmanTree(HuffmanBuilder<D, W>(file_name)) { }
	HuffmanTree(HuffmanBuilder<D, W> hb): HuffmanTree(hb.create()) { }
	HuffmanTree(Node<D, W>* r): _root(r) { }
	std::string get_code(D d);
	void encode(const char*, const char*);
	void decode(const char*, const char*);
	int height();
};

// recursively searches for a key and returns it's code
template<typename D, typename W>
std::string HuffmanTree<D, W>::get_code(D d) {
	return get_code(_root, d, "");
}

// writes a file using it's coding tree
template<typename D, typename W>
void HuffmanTree<D, W>::encode(const char* in_file_name, const char* out_file_name) {
	std::ifstream in_file;
	std::ofstream out_file;

	in_file.open(in_file_name);
	out_file.open(out_file_name);

	// encode all original characters
	while (!in_file.eof()) {
		write_code(out_file, in_file.get());
	}

	// wirte a character to signify the end of the text
	write_code(out_file, END_HUFF, true);

	in_file.close();
	out_file.close();
}

// decodes an incoded file using the coding tree
template<typename D, typename W>
void HuffmanTree<D, W>::decode(const char* in_file_name, const char* out_file_name) {
	std::ifstream in_file;
	std::ofstream out_file;
	int max_code = height()-1;
	std::string code;
	D item;

	in_file.open(in_file_name);
	out_file.open(out_file_name);

	while (!in_file.eof()) {
		while (code.length() < max_code)
			code += char_as_binary_string(in_file.get());

		item = find_item(_root, code, 0);
		code = code.substr(get_code(item).length(), code.length());
		if (item == END_HUFF)
			break;
		out_file.put(item);
	}

	in_file.close();
	out_file.close();
}

// writes the code of the character to the passed in output file
template<typename D, typename W>
void HuffmanTree<D, W>::write_code(std::ofstream& out_file, D i, bool end) {
	static char buffer;
	static short buff_pos = 0;
	std::string code = get_code(i);

	// must write bits, one char at a time
	for (int i=0; i < code.length(); i++) {
		buffer = buffer << 1;
		if (code[i] == '1')
			buffer++;

		if (buff_pos == 7 || (end && i == code.length()-1)) {
			out_file.put(buffer);
			buff_pos = 0;
		} else
			buff_pos++;
	}
}

// writes the code of the character to the passed in output file
template<typename D, typename W>
D HuffmanTree<D, W>::find_item(Node<D, W>* n, const std::string& code, int depth) {
	if (n->is_leaf()) {
		return dynamic_cast<Leaf<D, W>*>(n)->data();
	} else {
		Internal<D, W>* temp_node = dynamic_cast<Internal<D, W>*>(n);
		if (code[depth] == '0')
			return find_item(temp_node->left(), code, depth+1);
		else
			return find_item(temp_node->right(), code, depth+1);
	}
}

// writes the code of the character to the passed in output file
template<typename D, typename W>
std::string HuffmanTree<D, W>::char_as_binary_string(char buffer) {
	int buff_pos = 7;
	std::string code;
	char mask = 1;
	char bit;

	while (buff_pos >= 0) {
		bit = (buffer >> buff_pos) & mask;
		if (bit == 0)
			code += '0';
		else
			code += '1';

		buff_pos--;
	}
	
	return code;
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

// recursively find the height of the tree
template<typename D, typename W>
int HuffmanTree<D, W>::height() {
	return height(_root);
}

// recursively find the height of the tree
template<typename D, typename W>
int HuffmanTree<D, W>::height(Node<D, W>* n) {
	// on a leaf node return either a code or empty if no code
	if (n->is_leaf()) {
		return 1;
	}
	// on an internal node search the sides and return 
	else {
		Internal<D, W>* temp_node = dynamic_cast<Internal<D, W>*>(n);
		int left_height = height(temp_node->left());
		int right_height = height(temp_node->right());

		return 1 + (left_height >= right_height ? left_height : right_height);
	}
}

// This class is used to help in constructing the
// Huffman Tree
template<typename D, typename W>
class HuffmanBuilder {
private:
	MinQueue<D, W> _nodes;

public:
	HuffmanBuilder(const char* file_name): _nodes(MinQueue<D, W>(file_name)) { _nodes.add(END_HUFF,1); }
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
