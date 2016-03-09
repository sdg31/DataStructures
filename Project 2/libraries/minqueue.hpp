#ifndef MINQUEUE_HPP
#define MINQUEUE_HPP

#include "sortvector.hpp"

#include <queue>
#include <vector>

// this priority queue with a min comparison
// is used to construct the huffman tree
template<typename D, typename W>
class MinQueue {
private:
	std::priority_queue<Node<D, W>*, std::vector<Node<D, W>*>, CompareMin<Node<D, W>*>> _pq;

public:
	MinQueue(const char* file_name): MinQueue(SortVector<D, W>(file_name)) { }
	MinQueue(SortVector<D, W> sv): MinQueue(sv.get_vector()) { }
	MinQueue(std::vector<Leaf<D, W>*> v): _pq(v.begin(), v.end()) { }
	void add(D, W);
	void add(Node<D, W>*, Node<D, W>*);
	Node<D, W>* remove();
	int size();
};

// adds a Leaf Node to the queue
template<typename D, typename W>
void MinQueue<D, W>::add(D d, W w) {
	_pq.push(new Leaf<D, W>(d, w));
}

// adds an Internal Node to the queue
template<typename D, typename W>
void MinQueue<D, W>::add(Node<D, W>* l, Node<D, W>* r) {
	_pq.push(new Internal<D, W>(l, r));
}

// pops the Node with the smallest weight
// off the queue
template<typename D, typename W>
Node<D, W>* MinQueue<D, W>::remove() {
	Node<D, W>* temp = _pq.top();
	_pq.pop();
	return temp;
}

// returns the queue's size
template<typename D, typename W>
int MinQueue<D, W>::size() {
	return _pq.size();
}

#endif
