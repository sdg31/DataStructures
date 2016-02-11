#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

template<typename T>
class List
{
public:
  Node<T>* head;
  Node<T>* tail;

public:
  List();
  virtual ~List();
  void push_front( T data );
  void pop_front();
  void insert();
  
};

template<typename T>
List<T>::List()
  :head(), tail()
{
}

template<typename T>
void List<T>::push_front( T data )
{
  if( !head )
  {
    head = new Node<T>;
    tail = head;
    head->next = nullptr;
    head->data = data;
  }
  else if( head == tail )
  {
    head = new Node<T>;
    head->next = tail;
    head->data = data;
    tail->next = nullptr;
  }
  else
  {
    Node<T>* temp = new Node<T>;
    temp->next = head;
    temp->data = data;
    head = temp;
    tail->next = nullptr;
  }
}

template<typename T>
void List<T>::pop_front()
{
  if( head == tail)
  {
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    delete head;
    head = head->next;
  }
}

template<typename T>
List<T>::~List()
{
  while( head )
    this->pop_front();
}

#endif
