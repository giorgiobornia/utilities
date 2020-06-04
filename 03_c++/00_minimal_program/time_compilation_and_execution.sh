#!/bin/bash

# C++ program with STL include (iostream)
time g++ 00_hello.cpp 
time ./a.out


# equivalent C program - without STL include
# # Compile with gcc and run
time gcc 01_hello_in_C_Faster_compilation_and_execution.c    #much faster than the C++ compilation
time ./a.out                                   #faster than the C++ execution 
# # Compile with g++ and run
time g++ 01_hello_in_C_Faster_compilation_and_execution.c    #much faster than the C++ compilation, but twice slower than before only because of using g++
time ./a.out                                   #slower execution than before, only for changing compiler?!
