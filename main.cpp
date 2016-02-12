#include "queue.hpp"

int main()
{
  Queue<double> q;
  q.enqueue( 5.4 );
  q.enqueue( 2.2 );
  q.enqueue( 12.3 );
  q.enqueue( 3.14 );
  q.dequeue();
 
  q.print();
  
  return 0;
}
