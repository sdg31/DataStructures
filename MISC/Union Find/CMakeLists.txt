add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
project(full_lib CXX)
project(main CXX)

#add library .cpp files to a GLOB
file(GLOB full_lib_src
    libraries/*.cpp
)

# add library
add_library(full_lib STATIC
    ${full_lib_src}
)

# test program executables
add_executable(main main.cpp)

# link libraries
target_link_libraries(main LINK_PUBLIC full_lib)

