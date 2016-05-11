#include <vector>
#include <initializer_list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <utility>

template<typename T>
struct Node
{
    Node();
    Node( T data );
    T Data;
    int Key;
    int x;
    int y;
    std::vector< std::pair< Node<T>*, int > > Neighbors;
};

template<typename T>
class Graph
{
    // adjacency list implemented as a vector of vectors of pairs of nodes
    // and weights
    bool Matrix[10][10];
    int Vertices;
public:
    Graph();
    // add a node to the graph and attach an adjacency list to it
    void AddEdge( int i, int j );
    void RemoveEdge( int i, int j );
    bool HasEdge( int i, int j );
    void AttachNode( Node<T>* src, Node<T>* dest, int weight );
    // print all values in each adjacency list
    void Print();

    bool Reachable( int start, int key ) const;
    void Kruskal();
    void Prim();
};

template<typename T>
Node<T>::Node()
    :Data( T() ), Neighbors()
{
}

template<typename T>
Node<T>::Node( T data )
    :Data( data ), Neighbors()
{
}

template<typename T>
void Graph<T>::AddEdge( int i, int j )
{
    Matrix[i][j] = true;
}

template<typename T>
void Graph<T>::RemoveEdge( int i, int j )
{
    Matrix[i][j] = false;
}

template<typename T>
bool Graph<T>::HasEdge( int i, int j )
{
    return Matrix[i][j];
}

template<typename T>
void Graph<T>::AttachNode( Node<T>* src, Node<T>* dest, int weight )
{
    src.Neighbors
}

template<typename T>
void Graph<T>::Print()
{
    for( int i = 0; i < Adjacent.size(); i++ )
    {
	std::cout << "Node " << i << ": ";
    	for( int j = 0; j < Adjacent[i].size(); j++  )
	{
    	    std::cout << "Key: " << Adjacent[i][j].first->Key
		      << " " << "Weight: " << Adjacent[i][j].second << " ";
	}
	std::cout << std::endl;
    }
}

template<typename T>
Graph<T>::Graph()
    :Adjacent()
{
}

template<typename T>
bool Graph<T>::Reachable( int start, int key ) const
{
    for( int i = 0; i <= key; i++ )
	if( Adjacent[start][i].first->Key == key )
	    return true;
    return false;
}
