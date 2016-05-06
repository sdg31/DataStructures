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
Vertex<T>::AddAdjacency( Vertex<T> insertion  )
{
    Adjacencies.push_back( insertion );
}
