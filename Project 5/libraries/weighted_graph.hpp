#include <vector>
#include <initializer_list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <utility>
#include "minheap.hpp"

template<typename T>
struct Node
{
    Node();
    Node( T data );
    T Data;
    int Key;
    bool visited;
    std::vector< std::pair< Node<T>*, int > > Neighbors;
};

template<typename T>
class Graph
{
public:
    int Vertices;
    int AmtEdges;
    std::vector< std::vector<int> > Matrix;
    // adjacency list implemented as a vector of vectors of pairs of nodes
    // and weights
    std::vector< std::vector< std::pair< Node<T>*, int > > > Adjacent;
    int AmountEdges;
    std::vector<bool> Visited;
public:
    Graph();
    Graph( int size );
    // add a node to the graph and attach an adjacency list to it
    void AddNode( Node<T>* node  );
    void AddNode( int, int, int );
    void AttachAdjacency( int key, std::pair< Node<T>*, int > );
    void AttachAdjacency( int key, 
			  std::initializer_list< std::pair< Node<T>*, 
			  int > > adjacencies );
    int FindNeighbor( int );
    int FindClosestNeighbor( int );
    std::pair<int, int> ClosestNeighborWeight( int );
    std::vector< std::pair<int, int> > FindAllNeighbors( int );
    // print all values in each adjacency list
    void Print();

    int GetVertices() const;
    bool Reachable( int start, int key ) const;
    Graph<T> Prim( int vertex );
    Graph<T> Kruskal( int vertex );

    int PositionSearch();
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

//initialize matrix to specified size, all with value -1 (infinity)
//the initialization syntax of 2D vectors is quite strange...
//also initialize visited to false
template<typename T>
Graph<T>::Graph( int size )
    :Matrix( std::vector< std::vector<int> >
	     ( size, std::vector<int>( size, -1 ) ) ),
     Visited( std::vector<bool>( size, false ) ),
     AmtEdges()
{
}

template<typename T>
void Graph<T>::AddNode( int src, int dest, int weight )
{
    assert( src >= 0 && src < Matrix.size() );
    assert( dest >= 0 && dest < Matrix.size() );
    assert( src != dest );

    if( Matrix[src][dest] == -1 )
	++Vertices;

    Matrix[src][dest] = weight;
    Matrix[dest][src] = Matrix[src][dest];
}

/*template<typename T>
void Graph<T>::AddNode( int vertex1, int vertex2, int weight )
{
    for( int i = 0; i < Matrix[vertex1].size(); i++ )
    {
	if( Matrix[vertex1][i] ==  )
	{
	    Matrix[vertex1][i] = weight;
	    //Matrix[vertex2][i] = weight;
	}
    }
    Matrix[vertex1]
}*/

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
    //++Vertices;
}

//find any neighbor to a node
template<typename T>
int Graph<T>::FindNeighbor( int start )
{
    for( int i = 0; i < Matrix.size(); i++ )
    {
        if( Matrix[start][i] != -1 )
	{
	    return i;
	}
    }
    return -1;
}

// Finds the neighbor of a vertex with the lowest edge weight
// returns -1 if the node has no neighbors
template<typename T>
int Graph<T>::FindClosestNeighbor( int vertex )
{
    int min = -1;
    // min needs to be some value in the matrix
    // so loop through and find one, break once it's found
    for( int i = 0; i < Matrix.size(); i++ )
    {
        if( Matrix[vertex][i] != -1 )
	{
	    min = Matrix[vertex][i];
	    break;
	}
    }
    //if there was no value found, discontinue search
    if( min == -1 )
	return min;
//    std::cout << min << "\n";
    //otherwise find the smallest edge weight
    for( int i = 0; i < Matrix.size(); i++ )
    {
        if( Matrix[vertex][i] != -1 && Matrix[vertex][i] < min )
	{
	    min = Matrix[vertex][i];
	}
    }
    //now find the first node that has that weight attached
    for( int i = 0; i < Matrix.size(); i++ )
    {
	if( Matrix[vertex][i] == min )
	    return i;
    }
}

template<typename T>
std::pair<int, int> Graph<T>::ClosestNeighborWeight( int vertex )
{
    int min = -1;
    int returnVertex = -1;
    // min needs to be some value in the matrix
    // so loop through and find one, break once it's found
    for( int i = 0; i < Matrix.size(); i++ )
    {
        if( Matrix[i][vertex] != -1 )
	{
	    min = Matrix[i][vertex];
	    returnVertex = i;
	    break;
	}
    }

    //if there was no value found, discontinue search
    if( min > -1 )
    {
	for( int i = 0; i < Matrix.size(); i++ )
	{
	    if( Matrix[i][vertex] != -1 && Matrix[i][vertex] < min )
	    {
		min = Matrix[i][vertex];
		returnVertex = i;
	    }
	}
    }
    return std::make_pair( returnVertex, min );

}

template<typename T>
std::vector< std::pair<int,int> > Graph<T>::FindAllNeighbors( int vertex )
{
    std::vector< std::pair<int,int> > neighbors;
    for( int i = 0; i < Matrix.size(); i++ )
    {
        if( Matrix[vertex][i] != -1 )
	{
	    neighbors.push_back( std::make_pair( i, Matrix[vertex][i] ) );
	}
    }
    return neighbors;
    
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

template<typename T>
int Graph<T>::GetVertices() const
{
    return Vertices;
}

template<typename T>
Graph<T> Graph<T>::Prim( int vertex )
{
    const int V = GetVertices();
    Graph<int> MST( V );   
    MinPairHeap Heap;

    int current = vertex;
    Visited[current] = true;
    for( int i = 0; i < V; i++ )
    {
	std::cout << "current " << current << std::endl;
	std::vector< std::pair<int, int> > temp = 
	    FindAllNeighbors( current );
	for( int j = 0; j < temp.size(); j++ )
	{
	    if( !Visited[temp[j].first] )
	    {
		Heap.push( temp[j] );
		Visited[temp[j].first] = true;
	    }
	}
	if( !Heap.empty() )
	{
	    current = Heap.pop().first;
	}
	else
	    return MST;
	
    }
    return MST;
}

template<typename T>
Graph<T> Graph<T>::Kruskal( int vertex )
{
    const int V = GetVertices();
    Graph<int> MST( V );   
    MinPairHeap Heap;
    std::vector<bool> Visited( Matrix.size(), false );
    
    int current = vertex;
    Visited[current] = true;
    std::vector< std::pair<int,int> > neighbors =
	FindAllNeighbors( vertex );

    for( int i = 0; i < neighbors.size(); i++ )
    {
	Heap.push( neighbors[i] );
    }
    while( !Heap.empty() )
    {
	std::pair<int, int> Vert = Heap.pop();
	std::cout << Vert.first << std::endl;
    }
    
}
