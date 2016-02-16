#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

template<typename T>
class Queue : List<T>
{
public:
  void enqueue( T data );
  void dequeue();
  void print();
};

template<typename T>
void Queue<T>::enqueue( T data )
{
  this->push_back( data );
}

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

#endif
