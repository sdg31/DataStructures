add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
#project(insertion_lib CXX)

#add insertion library .cpp files to a GLOB
#file(GLOB insertion_lib_src
#    insertion/*.cpp
#)

# add insertion library
#add_library(insertion_lib STATIC
#    ${insertion_lib_src}
#)

