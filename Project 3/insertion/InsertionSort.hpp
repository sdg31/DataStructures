#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

#include <vector>

template<typename T>
void InsertionSort(std::vector<T>& A)
{
  for (int i = 1; i < A.size(); i++)
  {
    for (int j = i; j > 0 && A[j] < A[j-1]; --j)
    {
      auto temp = A[j];
      A[j] = A[j-1];
      A[j-1] = temp;
    }
  }
}

#endif // INSERTIONSORT_H_INCLUDED
