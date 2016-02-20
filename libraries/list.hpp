#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

#include <iostream>

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
  void clear( Node<T>* p );
  void push_front( T data );
  void push_back( T data );
  void pop_front();
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

//delete the head of the list
template<typename T>
void List<T>::pop_front()
{
  //if there is no head, this is a logic error
  //we have made such an error impossible, although this is optional
  if ( !head )
      return;

  //if there is only one element (head == tail), then simply delete it
  //and set both pointers to nullptr
  if( head == tail)
  {
    delete head;
    head = tail = nullptr;
  }
  //in all other cases, a temporary node must be created that copies the second node in the list
  //the head is deleted, and temp (the second node in the list), is made into the head
  else
  {
    Node<T>* temp = head->next;
    delete head;
    head = temp;
  }
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
void List<T>::clear( Node<T>* p )
{
  //iterate through the remainder of the list, deleting each node
  while( p )
  {
    Node<T>* q = p->next;
    delete p;
    p = q;
  }
}

template<typename T>
List<T>::~List()
{
  clear( this->head );
}

#endif
