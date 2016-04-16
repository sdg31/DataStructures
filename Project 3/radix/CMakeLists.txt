add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
#project(radix_lib CXX)

#add radix library .cpp files to a GLOB
#file(GLOB radix_lib_src
#    radix/*.cpp
#)

# add radix library
#add_library(radix_lib STATIC
#    ${radix_lib_src}
#)

