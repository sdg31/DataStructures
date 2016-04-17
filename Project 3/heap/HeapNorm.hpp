/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapNorm.h
 * Author: Jason
 *
 * Created on April 8, 2016, 2:28 PM
 */

#ifndef HEAPNORM_H
#define HEAPNORM_H

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class HeapNorm {
public:
    HeapNorm(){
        push(0);
    }

    // Adding copy constructor
    HeapNorm(const std::vector<T>& v) {
        heap = std::vector<T>(v.begin(), v.end());
    }

    // return referece to vector
    std::vector<T> getvector() {
        return heap;
    }

    void push(int n){
        heap.push_back(n);
    }
    
    void buildHeap(){
        int pos = (heap.size()-1)/2;

        while(pos){
            siftDown(pos, heap.size());
            --pos;
        }
    }
    
    void siftDown(int start, int end){
        if(start*2>=end) return;
        
        int max = maxChild(start*2,start*2+1);
        if (heap[start] < heap[max]) swap(start, max);
        
        siftDown(max, end);
    }
    
    int maxChild(int l, int r){
        if(heap[r]) return (heap[l]>heap[r]) ? l : r;
        return l;
    }
    
    void swap(int c, int p){
        T temp = heap[c];
        heap[c] = heap[p];
        heap[p] = temp;
    }
    
    void sort(){
        int start = 1, end = heap.size() - 1;
        
        while (end > 2){
            int parent = (end % 2) ? (end - 1) / 2 : end / 2;
            swap(start, end);
            swap(start, parent);
            siftDown(start, --end);
        }
        
        if (heap[start] > heap[end]) swap(start, end);
    }
    
    void print(){
        cout << "\nHeap: ";
        for(int i=0;i<heap.size();++i) cout << " " << heap[i] << " ";
        cout << endl;
    }
private:
    vector<T> heap;
};

#endif /* HEAPNORM_H */

