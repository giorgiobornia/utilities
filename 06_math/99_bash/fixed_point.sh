#!/bin/bash

# Run this script with "time" and compare it with the C implementation!


# This is the function g(x) for g(x) = x !
  function my_func() {
  
    echo  \( $1 \) \* \( $1 \)    | bc -l   #  x^2 = x 
#   echo c \( $1 \) | bc -l                 #  cos(x) = x

  }
  
  
  
  n_max=20
  x_new=0
  x_old=0.9
  i=1
  
  eps=0.0000001
  err=`echo $eps + 1 | bc`


  
 while   [   `echo $err \> $eps | bc` -eq  1     -a     $i -lt $n_max  ]  # two conditions
  do
  
    x_new=`my_func $x_old | bc -l`
    
    err=`echo \( $x_old \) - \( $x_new \)  | bc -l`
    err=`echo sqrt \( \( $err \) \* \( $err \) \) | bc -l`

    
    echo Iteration $i  Value  $x_new   Error  $err

#   Update    
    x_old=$x_new
    
    (( i++ ))
    
  done
