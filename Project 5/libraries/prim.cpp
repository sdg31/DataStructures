#include "weighted_graph.hpp"
#include "minheap.hpp"

template<typename T>
Graph<T>& Graph<T>::Prim( int key )
{
    assert( Adjacent.size() > 0 );
    MinHeap<int> Heap;
    int V;
    for( int i = 0; i < Adjacent[key].size(); i++ )
    {
	for( int j = 0; j  < Adjacent[key][i].first->Neighbors.size(); j++ )
	{
	    V++;
	}
    }
    Graph<T> MST;
    Node<T>* current = Adjacent[key][0].first;
    for( int i = 0; i < Adjacent[key].size(); i++ )
    {
	if( !current->visited )
	{
	    current->visited = true;
	    MST.AddNode( current );
	    for( int j = 0; j < current->Neighbors.size(); j++ )
	    {
		Heap.push( current->Neighbors[j].second );
	    }
	    int min = Heap.top();
	    for( int j = 0; j < current->Neighbors.size(); j++ )
	    {
		if( min == current->Neighbors[j].second )
		{
		    //MST.AddNode( current->Neighbors[j].first, min );
		    current = current->Neighbors[j].first;
		    break;
		}
	    }
	    while( !Heap.empty() )
	    {
		Heap.pop();
	    }
	}
    }

    return &MST;
}
