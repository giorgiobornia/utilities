#!/bin/bash 


folder=$1

# if (test $folder = "") then
# echo "Specify some folder";
# return;
# fi


for file in $folder/*
do
  if [ -d $file ]; then
     echo $file
  fi
done

# one-liner:
# for file in *; do if [ -d $file ]; then ls $file; fi; done
