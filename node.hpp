template<typename T>
class Node
{
public:
  Node();
  Node<T>* next;
  T data;
};

template<typename T>
Node<T>::Node()
  : next()
{
}

