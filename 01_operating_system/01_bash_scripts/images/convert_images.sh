#! /bin/sh
# multiple convert script

if [ $# -le 1 ]
then
	echo "$0 : You must supply the in and out extension"
	exit 1
fi

for file in *.$1
do
	filename=`basename $file .$1`
	echo "converting $filename.$1 to $filename.$2..."
	convert $file $filename.$2
done