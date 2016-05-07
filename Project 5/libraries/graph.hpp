#include <initializer_list>
#include <vector>

template<typename T>
class Vertex
{
public:
    Vertex();
    Vertex( std::initializer_list< Vertex <T> > );
    void AddAdjacency( Vertex<T> );
    std::vector< Vertex<T> > Adjacencies;
};

template<typename T>
class Graph
{
public:
    std::vector<T> List;
    Graph();
    Graph( std::initializer_list< Vertex< T > > );
};

template<typename T>
Vertex<T>::Vertex()
    :Adjacencies()
{
}

template<typename T>
Vertex<T>::Vertex( std::initializer_list< Vertex <T> > list )
    :Adjacencies( list )
{    
}

template<typename T>
void Vertex<T>::AddAdjacency( Vertex<T> insertion  )
{
    Adjacencies.push_back( insertion );
}


template<typename T>
Graph<T>::Graph()
    :List()
{
}

template<typename T>
Graph<T>::Graph( std::initializer_list< Vertex <T> > list )
    :List( list )
{    
}
