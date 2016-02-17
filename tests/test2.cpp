// Test 2 is used to compare the duration of enqueues
// and dequeues using our structure.  These can be
// used in Matlab to find trends.

#include "../libraries/queue.hpp"
#include "../libraries/stopwatch.hpp"

#include <queue>
#include <cstdlib>

int main()
{ 
  // stopwatch object for tracking time    
  StopWatch sw;

  // queue object
  Queue<double> our_q;
  std::queue<double> their_q;
    
  // number of iterations
  int n = 1000;
    
  // make a matlab array with enqueue durations
  std::cout << "enqueue_durations = [";
  for (int i=0; i < n; i++){
    sw.start();
    our_q.enqueue(rand());
    std::cout << sw.pause() << " ";
  }
  std::cout << "\b];" << std::endl;
  
  // make a matlab array with dequeue durations
  std::cout << "dequeue_durations = [";
  for (int i=0; i < n; i++){
    sw.start();
    our_q.dequeue();
    std::cout << sw.pause() << " ";
  }
  std::cout << "\b];" << std::endl << std::endl;
    
  sw.reset();
    
  // make a matlab array with enqueue durations
  std::cout << "enqueue_durations2 = [";
  for (int i=0; i < n; i++){
    sw.start();
    their_q.push(rand());
    std::cout << sw.pause() << " ";
  }
  std::cout << "\b];" << std::endl;
  
  // make a matlab array with dequeue durations
  std::cout << "dequeue_durations2 = [";
  for (int i=0; i < n; i++){
    sw.start();
    their_q.pop();
    std::cout << sw.pause() << " ";
  }
  std::cout << "\b];" << std::endl;
    
  return 0;
}