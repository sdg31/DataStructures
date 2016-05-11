#include <iostream>
#include "graph.hpp"

Node::Node()
{
}

Node::Node( std::initializer_list<Node> List )
	:Adjacent( List )
{
}

void Graph::AddNode()
{
}

void Graph::Print( Node N  )
{
	for( int i = 0; i < N.Adjacent.size(); i++ )
	{
		std::cout << i << std::endl;
	}
}
