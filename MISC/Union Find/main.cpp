#include "libraries/unionfind.hpp"

int main () {
    UnionFind u(16);
    
    u.merge(0,2);
    u.merge(1,2);
    u.merge(3,4);
    u.merge(3,1);
    u.merge(3,5);
    u.merge(9,11);
    u.merge(12,14);
    u.merge(3,9);
    u.merge(4,14);
    u.merge(6,7);
    u.merge(8,10);
    u.merge(8,7);
    u.merge(7,0);
    u.merge(10,15);
    u.merge(10,13);

    u.print();

    return 0;
}