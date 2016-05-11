#ifndef MINHEAP_HPP
#define MINHEAP_HPP

//min heap, courtesy of codeconnect.wordpress.com

#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

struct compare
{
    bool operator()( std::pair<int, int> lhs, std::pair<int, int> rhs )
    {
	return lhs.second > rhs.second;
    }
};

class MinPairHeap
{
private:
    std::priority_queue<std::pair<int,int>, 
			std::vector< std::pair<int, int> >, 
			compare> Heap;
public:
    void push( std::pair<int, int> data  );
    std::pair<int, int> pop();
    bool empty();
    std::pair<int, int> top();
    void print();
    int size();
};

void MinPairHeap::push( std::pair<int, int> data )
{
    Heap.push( data );
}

std::pair<int, int> MinPairHeap::pop()
{
    assert( !Heap.empty() );
    std::pair<int, int> value = Heap.top();
    Heap.pop();
    return value;
}

bool MinPairHeap::empty()
{
    return Heap.empty();
}

std::pair<int, int> MinPairHeap::top()
{
    return Heap.top();
}

int MinPairHeap::size()
{
    return Heap.size();
}

#endif
