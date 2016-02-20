#include "../libraries/queue.cpp"
#include <cassert>

int main()
{
  Queue<double> Q;
  for( double i = 0; i < 1000000; i++ )
  {
    Q.enqueue( i );
  }
  for( double i = 0; i < 1000000; i++ )
  {
    assert( Q.getData() == i );
    Q.dequeue();
  }
}
