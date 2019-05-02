#!/bin/bash

#cmd line args
file=$1
string_to_be_found=$2
mode=$3 #'write', or otherwise 



suppress_line_range_output='-n'  #without this it doesn't work!

insert_mode='c' 
   # c = replace 
   # i = insert without replacing (doesn't work properly, because lines change number then)

print_mode='q'


LINES=$( sed  $suppress_line_range_output "/$string_to_be_found/=" $file | tr "\n " ' ' ); 

lines_array=( $LINES )  #put the round brackets to make it an array

echo "The number of occurrences is " ${#lines_array[@]}


for pos in ${lines_array[*]};
do 
# echo $pos;
# sed "${pos} ${print_mode};d" $file  #print that line
  if (test $mode = 'write') then  #@todo see how to handle the case when mode is not provided from cmd line
     echo "write mode";
     sed  -e  "${pos} ${insert_mode}\ \\\item" -i  $file  #putting the space is the way to avoid adding other lines, do not put \ or \\n because otherwise you perturb the line numbers!
    fi
done


# the problem that if you insert a line then the number of that line changes! so you have to do the 'insert + replace' operation on the fly! Or alternatively recompute the row indices!
# If you do 'change' instead of 'insert' it is fine because you do not perturb the line numbers
