#!/bin/bash


  function my_func() { echo c \( $1 \) | bc -l; };  \
#   function my_func() { echo \( $1*$1-$1 \)  | bc -l; };  \
  n_max=20; \
  x_new=0; \
  x_old=0.1; \
  i=0; \
  while test $i -lt $n_max; do echo Iteration $i; x_new=`my_func $x_old | bc` ; echo $x_new; err=`echo $x_old - $x_new | bc`; echo sqrt\( $err \* $err \) | bc;  x_old=$x_new;  (( i++ )); done

