add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
#project(test_driver CXX)
#project(test1 CXX)
project(validate_sorts CXX)
project(test2 CXX)
project(radix CXX)

include_directories(
	libraries
	bubble
	radix
	insertion
)

# test program executables
#add_executable(test_driver tests/test_driver.cpp)
#add_executable(test1 tests/test1.cpp)
add_executable(validate_sorts tests/validate_sorts.cpp)
add_executable(test2 tests/test2.cpp)
add_executable(radix tests/radix.cpp)
