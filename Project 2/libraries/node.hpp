#ifndef NODE_HPP
#define NODE_HPP

// this is the base class for the Node classes
// all Nodes will contain a weight
template<typename D, typename W>
struct Node
{
private:
	W _wt;

public:
	Node() { }
	Node(W w): _wt(w) { }
	W weight() { return _wt; }
	virtual bool is_leaf() { return false; }
};

// this is the Internal Node class
// Internal Nodes contain a pointer
// to their left and right children
template<typename D, typename W>
struct Internal: Node<D, W>
{
private:
	Node<D, W>* _l;
	Node<D, W>* _r;

public:
	Internal(Node<D, W>* l, Node<D, W>* r): Node<D, W>(l->weight()+r->weight()), _l(l), _r(r) { }
	Node<D, W>* left() { return _l; }
	Node<D, W>* right() { return _r; }
};

// this is the Leaf Node class
// Leaf Nodes contain the data
// elements
template<typename D, typename W>
struct Leaf: Node<D, W>
{
private:
	D _d;

public:
	Leaf(D d, W w): Node<D, W>(w), _d(d) { }
	D data() { return _d; }
	bool is_leaf() { return true; }
};

// this is the CompareMin class
// we will be using a priority queue
// to build the tree structure and
// this class will maintain the min-order
template<typename N>
class CompareMin
{ 
public:
    bool operator() (const N left, const N right)
    {
        return left->weight() > right->weight();
    }
};

#endif
