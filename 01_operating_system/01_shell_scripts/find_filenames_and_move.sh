#!/bin/bash

#find files with a certain string in their filename, and move them to a folder named with that string

MYSTR=patriziocc; MYFILES=`find . -iname "*$MYSTR*"`; mkdir $MYSTR; mv $MYFILES $MYSTR
