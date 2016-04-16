// Tyler Harbert, Apr 2016
// these are general functions to help with testing

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <vector>
#include <iostream>

// prints a vector
template <typename T>
inline void print(std::vector<T> v) {
    for (int i=0; i < v.size(); i++)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

#endif
