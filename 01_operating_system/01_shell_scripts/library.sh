#!/bin/bash 
# @todo do we need the above line?
# @todo does a source script need executable permission? no
# every time you change the function you have to redo source!
# on the other hand, these function could communicate, a function could be called by another function, code could be reused, and more advanced operations could be performed
# actually, if you put these scripts in $PATH, you can still retrieve them and reuse them

# is there an 'include' directive for bash scripts? it is 'source' or '.' ...


echo "Remember to re-source the script every time you change some function"
# @todo: I believe that if you change the NAME of the function, you will have BOTH the OLD name and the NEW name, since every time you do a source new stuff is created
# so you keep on living with an environment that is more and more "dirty"...
# I don't think it's possible to do 'unsource'


function find_pattern_and_replace() {

#cmd line args
file=$1
string_to_be_found=$2
mode=$3 #'write', or otherwise 



if (test "$1" = "--help") then
echo " function   filename  string_to_be_found  mode_read_or_write ";
return;
fi



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
     sed  -e  "${pos} ${insert_mode}\ " -i  $file  #putting the space is the way to avoid adding other lines, do not put \ or \\n because otherwise you perturb the line numbers!
#      sed  -e  "${pos} ${insert_mode}\ \\\item" -i  $file  #putting the space is the way to avoid adding other lines, do not put \ or \\n because otherwise you perturb the line numbers!
    fi
done


# the problem that if you insert a line then the number of that line changes! so you have to do the 'insert + replace' operation on the fly! Or alternatively recompute the row indices!
# If you do 'change' instead of 'insert' it is fine because you do not perturb the line numbers 


}


function math_sum() {

echo "input a number"
read number1

echo "now input another number"
read number2

let answer=$number1+$number2
echo "$number1 + $number2 = $answer"


}



function separate_variable_by_delimiter() {

if (test "$1" = "--help") then
echo " function variable  delimiter delimiter_out";
return;
fi

echo $1 | tr $2 $3

}



function filesystem_replace_extension_in_folder() {

if (test "$1" = "--help") then
# @todo is there a variable for the function name, such as $0 would be the variable for the function script?
echo " rename folder_path suffix_in suffix_out";
return;
fi

folder=$1

suffix_in=$2

suffix_out=$3


command_read_or_write=echo
if (test "$4" = "mv") then
   command_read_or_write=mv
fi


for f in $folder/*.${suffix_in}
do
#Strip off the suffix and add the new one
  newname=${f%${suffix_in}}${suffix_out}
# Do the name change
  $command_read_or_write $f $newname
done

}


function list_directories_only() {

folder=$1

for file in *
do
  if [ -d $file ]
  then
     ls $file
  fi
done

}
