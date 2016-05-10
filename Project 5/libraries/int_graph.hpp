#include <vector>
#include <initializer_list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <utility>

struct Node
{
    Node();
    Node( T data );
    T Data;
    int Key;
    std::vector< std::pair< Node<T>*, int > > Neighbors;
};

template<typename T>
class Graph
{
    // adjacency list implemented as a vector of vectors of pairs of nodes
    // and weights
    std::vector< std::vector< std::pair< Node<T>*, int > > > Adjacent;
    int Vertices;
public:
    Graph();
    // add a node to the graph and attach an adjacency list to it
    void AddNode( Node<T>* node  );
    void AttachAdjacency( int key, std::pair< Node<T>*, int > );
    void AttachAdjacency( int key, 
			  std::initializer_list< std::pair< Node<T>*, 
			  int > > adjacencies );
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
void Graph<T>::AddNode( Node<T>* node )
{
    // Push back a vector of pairs
    // since there are no adjacencies yet, weights are 0
    // the key of element 0 is it's place in the main array
    Adjacent.push_back( std::vector< std::pair < Node<T>*, int > >() );
    Adjacent[ Adjacent.size() - 1 ].push_back( std::make_pair
					       ( node, 0  ) );
    Adjacent[ Adjacent.size() - 1 ][0].first->Key = Adjacent.size() - 1;
    ++Vertices;
}

template<typename T>
void Graph<T>::AttachAdjacency( int key, 
				std::initializer_list< std::pair< Node<T>*,
				int > > adjacencies )
{
    // when given a list of adjacencies
    // reserve enough size and then concatenate the adjacencies
    // onto the node's adjacency list
    std::vector< std::pair< Node<T>*, int > > temp( adjacencies );
    Adjacent[key].reserve( Adjacent[key].size() + temp.size() );
    Adjacent[key].insert( Adjacent[key].end(), temp.begin(), temp.end() );
    Vertices += adjacencies.size();

    Adjacent[key][0].first->Neighbors.push_back( std::make_pair(
						     Adjacent[key][1].first,
						     Adjacent[key][1].second
						     ) );
}

template<typename T>
void Graph<T>::AttachAdjacency( int key,
				std::pair< Node<T>*, int > node )
{
    assert( Adjacent[key].size() > 0 );
    Adjacent[key].push_back( node );
    Adjacent[key][0].first->Neighbors.push_back( node );
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
