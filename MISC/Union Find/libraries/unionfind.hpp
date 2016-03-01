#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include <iostream>

class UnionFind {
private:
	int* _tree;
	int* _weights;
	int _size;
	int find(int);

public:
	UnionFind(int);
	~UnionFind();
	void merge(int,int);
	void print();
};

#endif
