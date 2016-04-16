add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
#project(bubble_lib CXX)

#add radix library .cpp files to a GLOB
#file(GLOB bubble_lib_src
#    bubble/*.cpp
#)

# add radix library
#add_library(bubble_lib STATIC
#    ${bubble_lib_src}
#)

