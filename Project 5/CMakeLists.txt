add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
#project(hashlib CXX)
project(driver CXX)

#add library .cpp files to a GLOB
#file(GLOB hashlib_src
#    libraries/*.cpp
#)

# add library
#add_library(hashlib STATIC
#    ${hashlib_src}
#)

include_directories(
	libraries
	quadratic
	double
	cuckoo
)

# test program executables
add_executable(driver tests/driver.cpp)

# link libraries
#target_link_libraries(driver LINK_PUBLIC hashlib)
