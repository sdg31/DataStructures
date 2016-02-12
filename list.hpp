#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

#include <iostream>

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
  void push_back( T data );
  void pop_front();
  void insert();
  void print();  
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
    head = new Node<T>(data, nullptr);
    tail = head;
  }
  else
  {
    head = new Node<T>(data, head);
  }
}

template<typename T>
void List<T>::push_back( T data )
{   
  if( !head )
  {
    head = new Node<T>(data, nullptr);
    tail = head;
  }
  else
  {
    Node<T>* temp = new Node<T>(data, nullptr);
    tail->next = temp;
    tail = temp;
  }
}

template<typename T>
void List<T>::pop_front()
{
  if ( !head )
      return;

  if( head == tail)
  {
    delete head;
    head = tail = nullptr;
  }
  else
  {
    Node<T>* temp = head->next;
    delete head;
    head = temp;
  }
}

template<typename T>
void List<T>::print()
{
  Node<T>* temp = head;
  while( temp ) {
    std::cout << temp->data << ' ';
    temp = temp->next;
  }
  std::cout << std::endl;
}

template<typename T>
List<T>::~List()
{
  while( head )
    this->pop_front();
}

#endif
