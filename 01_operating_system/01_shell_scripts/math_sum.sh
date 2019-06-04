#!/bin/bash 


echo "input a number"
read number1

echo "now input another number"
read number2

let answer=$number1+$number2
echo "$number1 + $number2 = $answer"
