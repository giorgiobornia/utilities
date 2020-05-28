#!/bin/bash 

#preprocessing - from source code to preprocessed code

gcc -E 00_main.c -o 01_preprocessing.i 

#compiling - from human program to assembly code
gcc -S 00_main.c -o 02_compiling.s 

#assembly - from assembly code to machine code
gcc -c 00_main.c -o 03_assembly.o 

#linking
gcc    00_main.c -o 04_linking.exe
