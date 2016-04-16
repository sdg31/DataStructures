#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

template<typename Comparable>
void InsertionSort(Comparable A[], int numberOfElements)
{
  for (int i = 1; i < numberOfElements; i++)
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
