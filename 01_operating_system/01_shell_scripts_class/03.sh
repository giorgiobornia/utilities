#!/bin/bash

mkdir out_while

myvar=1

while [ $myvar -le 10  ]
do
 touch out_while/$myvar.out
 let myvar=$myvar+1
done
