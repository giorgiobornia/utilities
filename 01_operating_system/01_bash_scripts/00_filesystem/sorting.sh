#! /bin/bash

DIR_IN=$1
DIR_OUT=$2
OFFSET=$3

mkdir -p $DIR_OUT
for file in $DIR_IN/*.tif 
do
	dir=$(echo $DIR_IN | sed s,$(dirname $PWD)/,,)
	NUM=$(basename $(echo $file | sed s!${dir}-!!) .tif)
	cp $file $DIR_OUT/$(( $NUM + $OFFSET )).tif
done

