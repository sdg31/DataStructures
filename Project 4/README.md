# Two Choice Hashing

This implements two choice hashing in C++. Two choice hashing works by using two independent hash functions so that every input can have two different destinations depending on the hash function used. If a bucket is more filled using hash1 then it will use hash2, if all buckets are full it will be stored in an overflow location.

# Build Instructions

From this directory run the following command line instructions

1. mkdir bin (create a bin directory, this is ignored by our .gitignore)
2. cd bin (enter the directory)
3. cmake .. (run cmake up a level on the CMakeLists.txt file)
4. make -j4 (run make -j4 makes it faster using multiple jobs)

