#include "weighted_graph.hpp"
#include "minheap.hpp"

int main()
{
    Graph<int> G( 15 );
    for( int i = 0; i < G.Matrix.size(); i++ )
    {
	for( int j = 0; j < G.Matrix.size(); j++ )
	{
	    int v1 = rand() % G.Matrix.size();
	    int v2 = rand() % G.Matrix.size();
	    if( v1 != v2 )
		G.AddNode( v1, v2, rand() % 200 );
	    else if( v1 < G.Matrix.size() - 1 )
		G.AddNode( v1 + 1, v2, rand() % 200 );
	    else if( v1 > 0 )
		G.AddNode( v1 - 1, v2, rand() % 200 );
	}
    }
    for( int i = 0; i < G.Matrix.size(); i++ )
	std::cout << "\t" << i;
    std::cout << std::endl;
    for( int i = 0; i < G.Matrix.size(); i++ )
    {
	std::cout << i << "\t";
	for( int j = 0; j < G.Matrix.size(); j++ )
	    std::cout << G.Matrix[i][j] << "\t";
	std::cout << std::endl;
    }

    //G.Prim( 0 );

    G.Kruskal( 0 );
    return 0;
}
