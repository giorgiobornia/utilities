#!/bin/bash

file_var=$1

if [ -e $file_var ]
then
  ls -l $file_var
else
  echo The file $file_var is not there
fi
