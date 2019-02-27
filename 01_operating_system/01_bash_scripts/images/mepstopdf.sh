#! /bin/sh
# multiple epstopdf script

for file in *.eps
	do
	filename=`basename $file .eps`
	if [ -f $filename.pdf ]
	then
		echo "no convertion for $filename.eps"
	else
		echo "converting $filename.eps to $filename.pdf..."
		epstopdf $file
	fi
done