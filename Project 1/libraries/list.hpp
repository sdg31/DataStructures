#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include <iostream>
#include <cassert>

//this singly linked list has two named nodes, a head and tail
//these are not dummy nodes and both contain data
//tail->next should always be nullptr
template<typename T>
class List
{
public:
  Node<T>* head;
  Node<T>* tail;

public:
  List();
  virtual ~List();
  void clear( Node<T>* current );
  void push_front( T data );
  void push_back( T data );
  T pop_front();
  void insert();
  void print();
};

//default constructor creates empty list
template<typename T>
List<T>::List()
  :head(), tail()
{
}

//insert a new head into the list
template<typename T>
void List<T>::push_front( T data )
{
  //if the list is empty, allocate a new head
  //since there is only one element, the head is also the tail
  if( !head )
  {
    head = new Node<T>(data, nullptr);
    tail = head;
  }
  //since the list is linked singly, there is only one special case (the list is empty),
  //so otherwise, simply create a new head and set it's next pointer to the previous head
  else
  {
    head = new Node<T>(data, head);
  }
}

//push_back is fundamentally the same as push_front
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
    tail->next = new Node<T>(data, nullptr);
    tail = tail->next;
  }
}

//delete the head
template<typename T>
T List<T>::pop_front()
{
  //if there is no head, there's a logic error, so assert
  assert( head );

  //return the data at the current head
  T return_data = head->data;

  //create a temporary to the second element in the list
  //if there is nothing, this will be nullptr, making the list empty again
  Node<T>* temp = head->next;
  delete head;
  head = temp;

  return return_data;
}

//prints the contents of every node in the list
template<typename T>
void List<T>::print()
{
  //a temporary node is created, and while it is not null, it's data is printed
  //when (temp == tail->next), it will be null, since tail->next is always a nullptr
  Node<T>* temp = head;
  while( temp ) {
    std::cout << temp->data << ' ';
    temp = temp->next;
  }
  std::cout << std::endl;
}

//delete every node in the list starting from the parameter node
template<typename T>
void List<T>::clear( Node<T>* current )
{
  //iterate through the remainder of the list, deleting each node
  while( current )
  {
    Node<T>* temp = current->next;
    delete current;
    current = temp;
  }
}

template<typename T>
List<T>::~List()
{
  clear( this->head );
}

#endif
