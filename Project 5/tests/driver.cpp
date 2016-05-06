#include "../libraries/graph.hpp"
#include <iostream>

int main()
{
    Vertex<std::string> v1, v2, v3, v4;
    Graph<std::string> G( { v1, v2, v3, v4 } );
    return 0;
}
