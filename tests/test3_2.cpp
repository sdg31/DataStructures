// Test 3-2 is used to simply enqueue
// and dequeue n elements onto std::queue.
// This will be used by massif to compare
// heap usage

#include "../libraries/queue.hpp"

#include <queue>
#include <cstdlib>

int main()
{ 
  // queue objects
  Queue<double> our_q;
  std::queue<double> their_q;
    
  // number of elements
  int n = 4000000;

  for (int i=0; i < n; i++){
      their_q.push(rand());
  }

  for (int i=0; i < n; i++){
      their_q.pop();
  }

  return 0;
}