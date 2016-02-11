#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

template<typename T>
class Queue : List<T>
{
  void enqueue( T data );
  void dequeue();
};

template<typename T>
void Queue<T>::enqueue( T data )
{
  this->push_front( data );
}

template<typename T>
void Queue<T>::dequeue()
{
  this->pop_front();
}

#endif
