#include "shell_sort.hpp"
#include "stopwatch.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    StopWatch shell_sw;
    StopWatch log2_sw;
    StopWatch clog2_sw;

    srand( time( nullptr ) );
    std::vector<int> test1;
    std::vector<int> test2;
    std::vector<int> test3;
    std::cout << "mk1\n";
    for( int i = 0; i < 100000; i++ )
    {
	test1.push_back( rand() % 10000 );
    }
    std::cout << "mk2\n";
    test3 = test2 = test1;
    std::cout << "mk3\n";
    
    std::cout <<  __builtin_clz( test2.size() ) << '\n';

    shell_sw.start();
    shellsort( test1 );
    std::cout << "n/2 shellsort took " << shell_sw.pause() << " ns\n";
}
