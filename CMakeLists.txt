add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")

cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)
project(list CXX)
add_executable(list main.cpp list.cpp node.cpp queue.cpp)
