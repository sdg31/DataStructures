#include "libraries/queue.hpp"
#include "libraries/stopwatch.hpp"

#include <queue>
#include <cstdlib>

int main()
{ 
  // stopwatch objects for tracking time    
  StopWatch our_sw;
  StopWatch their_sw;

  // queue objects
  Queue<double> our_q;
  std::queue<double> their_q;
  
  // number of iterations
  int n = 3000000;
    
  std::cout << "OUR QUEUE" << std::endl;
  srand(0);
    
  our_sw.start();
  for (int i=0; i < n; i++){
      our_q.enqueue(rand());
  }
  std::cout << n << " enqueues took " << our_sw.pause() << "ns" << std::endl;
    
  our_sw.start();
  for (int i=0; i < n; i++){
      our_q.dequeue();
  }
  std::cout << n << " dequeues took " << our_sw.pause() << "ns" << std::endl;
    
  std::cout << "THEIR QUEUE" << std::endl;
  srand(0);
    
  their_sw.start();
  for (int i=0; i < n; i++){
      their_q.push(rand());
  }
  std::cout << n << " enqueues took " << their_sw.pause() << "ns" << std::endl;
    
  their_sw.start();
  for (int i=0; i < n; i++){
      their_q.pop();
  }
  std::cout << n << " dequeues took " << their_sw.pause() << "ns" << std::endl;
    
  std::cout << "Their queue took "<< (double)their_sw.duration()/our_sw.duration()*100 << "% of the time our queue took" << std::endl;
    
  return 0;
}