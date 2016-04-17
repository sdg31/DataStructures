#ifndef MERGE_HPP
#define MERGE_HPP

#include <vector>

template <typename T>
void merge(int low, int pivot, int high, std::vector<T>& v)
{
        int start = low;
        int mid = pivot + 1;
        while((start <= pivot) && (mid <= high)){
            if (v[start] > v[mid])
            {
                int temp = v[mid];
                v[mid] = v[start];
                v[start] = temp;
                mid++;
             }
            else
                start++;
    }
}

template <typename T>
void MergeSort(std::vector<T>& v, int low, int high)
{
    int pivot;
    if (high > low)
    {
        pivot = low + ((high - low)/2);
        MergeSort(v, low, pivot);
        MergeSort(v, pivot+1, high);
        merge(low, pivot, high, v);

    }
}

#endif
