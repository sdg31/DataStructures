add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
project(full_lib CXX)
project(test1 CXX)
project(test_driver CXX)

#add library .cpp files to a GLOB
file(GLOB full_lib_src
    libraries/*.cpp
)

# add library
add_library(full_lib STATIC
    ${full_lib_src}
)

include_directories(
	libraries
)

# test program executables
add_executable(test1 tests/test1.cpp)
add_executable(test_driver tests/test_driver.cpp)

# link libraries
target_link_libraries(test1 LINK_PUBLIC full_lib)
target_link_libraries(test_driver LINK_PUBLIC full_lib)
