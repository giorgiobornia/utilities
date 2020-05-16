
 #!/bin/bash


# Run the script as: ./scriptname number_increment



echo Cleaning the out directory 

mkdir -p out
cd out
rm -rf *

my_increment=$1


# if [  "$my_increment" =~ "[0-9]+" ] 
if ! [[  $my_increment =~ '^[0-9]+$' ]] 
then 
  echo The first argument is not a number
  exit
fi


#for  myvar in {1..100}
for  myvar in `seq 10 $my_increment 99`
 do
    touch $myvar.out
#   mv 0$myvar.out z0$myvar.out
 done
