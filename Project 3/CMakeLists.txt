add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

# add other group code
add_subdirectory(
	bubble
)
add_subdirectory(
	radix
)

#project declarations
#project(shell_lib CXX)
project(test_driver CXX)
project(validate_sorts CXX)
project(test1 CXX)

#add shell library .cpp files to a GLOB
#file(GLOB shell_lib_src
#    libraries/*.cpp
#)

# add shell library
#add_library(shell_lib STATIC
#    ${shell_lib_src}
#)

include_directories(
	libraries
	bubble
	radix
	insertion
)

# test program executables
add_executable(test_driver tests/test_driver.cpp)
add_executable(validate_sorts tests/validate_sorts.cpp)
add_executable(test1 tests/test1.cpp)

# link libraries
#target_link_libraries(test_driver LINK_PUBLIC shell_lib)
#target_link_libraries(validate_sorts LINK_PUBLIC shell_lib bubble_lib radix_lib)
#target_link_libraries(test1 LINK_PUBLIC shell_lib)
