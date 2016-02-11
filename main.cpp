#include "list.hpp"
#include <iostream>

int main()
{
  List<std::string> L;
  L.push_front( "5" );
  L.push_front( "8" );
  L.push_front( "12" );
  L.push_front( "15" );
 
  std::cout << L.head->data << "\n";
  std::cout << L.head->next->data << "\n";
  std::cout << L.head->next->next->data << "\n";
  std::cout << L.head->next->next->next->data << "\n";
  
  return 0;
}
