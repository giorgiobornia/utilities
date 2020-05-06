#! /bin/bash

# needs tiff2pdf
# in openSuSE, it's in the "tiff" package, tools for tiff

DIR_IN=$1

for file in $DIR_IN/*.tif 
do
	basefile=${file%.tif}  #only removes the .tif extension, different from 'basename' command
                               # this way it works in every directory
# 	echo $file
# 	echo $basefile
	tiff2pdf $file -o ${basefile}.pdf
done

