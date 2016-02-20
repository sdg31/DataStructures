#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

//This queue derives from our singly linked list
template<typename T>
class Queue : List<T>
{
public:
  void enqueue( T data );
  void dequeue();
  void print();
  T getData() const;
};

//to enqueue calls push_back, since
//an enqueue always happens at the back of the queue
template<typename T>
void Queue<T>::enqueue( T data )
{
  this->push_back( data );
}

//dequeue calls pop_front, since
//dequeues always happen at the head
template<typename T>
void Queue<T>::dequeue()
{
  this->pop_front();
}

template<typename T>
void Queue<T>::print()
{
  List<T>::print();
}

template<typename T>
T Queue<T>::getData() const
{
  return this->head->data;
}
#endif
