#include <vector>
#include <initializer_list>
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
struct Node
{
    Node();
    Node( T data );
    T Data;
    int Key;
};

template<typename T>
class Graph
{
    // adjacency list implemented as a vector of vectors of Node<T> pointers
    std::vector< std::vector< Node<T>* > > Adjacent;
public:
    Graph();
    // add a node to the graph and attach an adjacency list to it
    void AddNode( Node<T>* node  );
    void AttachAdjacency( int key,
		  std::initializer_list< Node<T>* > adjacencies  );
    // print all values in each adjacency list
    void Print();

    bool Reachable( int start, int key ) const;
    void Kruskal();
    void Prim();
};

template<typename T>
Node<T>::Node()
    :Data( T() )
{
}

template<typename T>
Node<T>::Node( T data )
    :Data( data )
{
}

template<typename T>
void Graph<T>::AddNode( Node<T>* node )
{
    Adjacent.push_back( std::vector< Node<T>* >() );
    Adjacent[ Adjacent.size() - 1 ].push_back( node );
    Adjacent[ Adjacent.size() - 1 ][0]->Key = Adjacent.size() - 1;
}

template<typename T>
void Graph<T>::AttachAdjacency( int key, 
			std::initializer_list< Node <T>* > adjacencies )
{
    // when given a list of adjacencies
    // reserve enough size and then concatenate the adjacencies
    // onto the node's adjacency list
    std::vector< Node<T>* > temp( adjacencies );
    Adjacent[key].reserve( Adjacent[key].size() + temp.size() );
    Adjacent[key].insert( Adjacent[key].end(), temp.begin(), temp.end() );
   
}

template<typename T>
void Graph<T>::Print()
{
    for( int i = 0; i < Adjacent.size(); i++ )
    {
	std::cout << "Node " << i << ": ";
    	for( int j = 0; j < Adjacent[i].size(); j++  )
	{
    	    std::cout << Adjacent[i][j]->Key << " ";
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
	if( Adjacent[start][i]->Key == key )
	    return true;
    return false;
}
