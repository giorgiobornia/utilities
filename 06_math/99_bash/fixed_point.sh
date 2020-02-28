#!/bin/bash

# This is the function g(x) for g(x) = x !

#   function my_func() { echo c \( $1 \) | bc -l; };  \
  function my_func() { echo  \( $1 \) \* \( $1 \)    | bc -l; };
  
  
  
  n_max=20;
  x_new=0;
  x_old=0.2;
  i=0;
  
  eps=0.000001
  err=`echo $eps + 1 | bc`


  
 while   test     `echo $err \> $eps | bc`   -a      $i -lt $n_max   ;   # two conditions
  do 
    echo Iteration $i; 
    x_new=`my_func $x_old | bc -l` ;
    echo Value $x_new; 
    err=`echo \( $x_old \) - \( $x_new \)  | bc -l`; 
    echo Error
    echo sqrt \( \( $err \) \* \( $err \) \) | bc -l;  
    x_old=$x_new;  
    (( i++ )); 
  done

