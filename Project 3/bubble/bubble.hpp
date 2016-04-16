#include<algorithm>
#include<iostream>

//Performs a bubble sort of the elements betweent first and last
//First and last must be random access iterators supporting ++, --, and *
//operations.
template<typename It>
void bubblesort(It first, It last)
{
  //Do a sorting pass that terminates at each element of the range
  while (first!=--last)
  {
    It p=first;
    //Sort through the range exchanging adjacent elements that are out of order
    while (p!=last)
    {
      It left = p;
      ++p;
      //If elements are out of order, exchange them
      if(*p < *left)
      {
        std::swap(*left, *p);
      }
    }
  }
}

//Performs a bubble sort and outputs the number of comparisons and swaps 
//performed
template<typename It>
void bubblesort_with_count(It first, It last)
{
  int comps = 0;
  int swaps = 0;
  while (first!=--last)
  {
    It p=first;
    while (p!=last)
    {
      It left = p;
      ++p;
      ++comps;
      if(*p < *left)
      {
        std::swap(*left, *p);
        ++swaps;
      }
    }
  }
  std::cerr<<"swaps = " << swaps<<'\n';
  std::cerr<<"comps = " << comps<<'\n';
}
