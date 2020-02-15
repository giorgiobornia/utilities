#!/bin/bash

n_functions=12

# pass to this script the word for the type of Problem ("zero" or "integral")
# and for the Method
# For every Problem and Method it shows the behaviour of ALL functions


myproblem=$1

mymethod=$2

########################
if test "${myproblem}" != "zero" && test "${myproblem}" != "integral"; then
  echo "Specify the problem (zero or integral)"
  exit
fi

#############################################
if test "${myproblem}" = "zero"; then 

if    test "${mymethod}" != "tangent"   && test "${mymethod}" != "secant" && test "${mymethod}" != "fixed_point"  && test "${mymethod}" != "bisection"; then
  echo "Specificare il metodo di risoluzione"
  exit
fi

if   test "${mymethod}" = "tangent";   then  n_mymethod=0
elif test "${mymethod}" = "secant";    then  n_mymethod=1
elif test "${mymethod}" = "fixed_point"; then  n_mymethod=2
elif test "${mymethod}" = "bisection";  then  n_mymethod=3
fi

#############################################
elif test "${myproblem}" = "integral"; then

if    test "${mymethod}" != "rectangle_midpoint"   && test "${mymethod}" != "rectangle_lower_end"  && test "${mymethod}" != "rectangle_upper_end" && test "${mymethod}" != "trapezoid" && test "${mymethod}" != "trapezoid_corrected" && test "${mymethod}" != "simpson" ; then
  echo "Specify the solution method"
  exit
fi

if   test "${mymethod}" = "rectangle_midpoint";   then  n_mymethod=0
elif test "${mymethod}" = "rectangle_lower_end";  then  n_mymethod=1
elif test "${mymethod}" = "rectangle_upper_end";  then  n_mymethod=2
elif test "${mymethod}" = "trapezoid";            then  n_mymethod=3
elif test "${mymethod}" = "trapezoid_corrected";  then  n_mymethod=4
elif test "${mymethod}" = "simpson";              then  n_mymethod=5
fi

fi  # end zero-integrale


rm ${myproblem}/${mymethod}.out

     sed '/#define MYMETHOD/ c\ #define MYMETHOD '${n_mymethod}' ' -i  ${myproblem}/${myproblem}.c

for i in  $(seq 1 1 ${n_functions})
do
     sed '/#define MYFUNC/ c\ #define MYFUNC '${i}' ' -i  ${myproblem}/${myproblem}.c
     gcc ${myproblem}/${myproblem}.c -lm -o ${myproblem}/a.out
     cd ${myproblem}
     ./a.out
     cd ..
done


# Commenti
# il comparatore di uguaglianza per la shell ha UN SOLO segno di uguale!
