#!/bin/bash 


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
