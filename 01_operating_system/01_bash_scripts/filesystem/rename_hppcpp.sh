#!/bin/bash

# with the FIND COMMAND i was able to perform a RECURSIVE FOR LOOP even in multiple subdirectories

for file in $(find . -iname "*.C"); do echo $file ${file%.C}.cpp ; done