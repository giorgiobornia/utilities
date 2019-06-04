#!/bin/bash 



if (test "$1" = "--help") then
echo " function variable  delimiter delimiter_out";
return;
fi

echo $1 | tr $2 $3
