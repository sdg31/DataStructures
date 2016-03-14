#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "minqueue.hpp"
#include "iohelper.hpp"

#include <map>

// forward declaration of Huffman Builder
template<typename D, typename W>
class HuffmanBuilder;

// this is the Huffman Tree class
template<typename D, typename W>
class HuffmanTree {
private:
	Node<D, W>* _root;
	std::map<D, std::string> _map;
	std::string get_code_rec(Node<D, W>*, D, std::string = "");
	int height(Node<D, W>*);
	void write_code(std::ofstream&, D, bool = false);
	D find_item(Node<D, W>*, std::string&, int);
	std::string as_binary_string(char);
	std::string as_binary_string(std::string);
	void map_codes(Node<D, W>*, std::string);

public:
	HuffmanTree(const char* file_name): HuffmanTree(HuffmanBuilder<D, W>(file_name)) { }
	HuffmanTree(HuffmanBuilder<D, W> hb): HuffmanTree(hb.create()) { }
	HuffmanTree(Node<D, W>* r): _root(r) { map_codes(r, ""); }
	std::string get_code(D d);
	void encode(const char*, const char*);
	void decode(const char*, const char*);
	int height();
};

// recursively searches for a key and returns it's code
template<typename D, typename W>
std::string HuffmanTree<D, W>::get_code_rec(Node<D, W>* n, D d, std::string code) {
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

		temp_code = get_code_rec(temp_node->left(), d, code+"0");
		if (!temp_code.empty())
			return temp_code;
		else
			return get_code_rec(temp_node->right(), d, code+"1");
	}
}

// recursively searches for a key and returns it's code
template<typename D, typename W>
std::string HuffmanTree<D, W>::get_code(D d) {
	return _map.find(d)->second;
}

// recursively searches for a key and adds it's code to the map
template<typename D, typename W>
void HuffmanTree<D, W>::map_codes(Node<D, W>* n, std::string code) {
	// on a leaf node return either a code or empty if no code
	if (n->is_leaf()) {
		D d = dynamic_cast<Leaf<D, W>*>(n)->data();
		_map.insert(std::pair<D, std::string>(d, code));
	}
	// on an internal node search the sides and return 
	else {
		Internal<D, W>* temp_node = dynamic_cast<Internal<D, W>*>(n);

		map_codes(temp_node->left(), code+"0");
		map_codes(temp_node->right(), code+"1");
	}
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
		write_code(out_file, get(in_file, new D()));
	}

	// wirte a character to signify the end of the text
	write_code(out_file, get_terminator(new D()), true);

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
			code += as_binary_string(get(in_file, new D()));

		item = find_item(_root, code, 0);
		if (item == get_terminator(new D()))
			break;
		out_file << item;
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

		if (buff_pos == 7) {
			out_file.put(buffer);
			buff_pos = 0;
		} else if (end && i == code.length()-1) {
			out_file.put(buffer << (8-buff_pos));
		} else
			buff_pos++;
	}
}

// writes the code of the character to the passed in output file
template<typename D, typename W>
D HuffmanTree<D, W>::find_item(Node<D, W>* n, std::string& code, int depth) {
	if (n->is_leaf()) {
		code = code.substr(depth, code.length());
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
std::string HuffmanTree<D, W>::as_binary_string(char buffer) {
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

// writes the code of the string to the passed in output file
template<typename D, typename W>
std::string HuffmanTree<D, W>::as_binary_string(std::string wrd) {
	std::string bstring;

	for (int i = 0 ; i < wrd.length(); i++) {
		bstring += as_binary_string(wrd[i]);
	}

	return bstring;
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
	HuffmanBuilder(const char* file_name): _nodes(MinQueue<D, W>(file_name)) { _nodes.add(get_terminator(new D()),1); }
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
