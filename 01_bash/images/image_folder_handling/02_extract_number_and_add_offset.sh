#!/bin/bash


#first sort by number
#put the zeros
#adjust the images (rotate,...)
#then convert from .tif to .pdf  / tiff2pdf
#then merge pdf  /pdfmerge


#first sort by number====================
#two directories are necessary here because you may overwrite files otherwise!
DIR_IN=$1    #from scanner files directory
DIR_OUT=$2   
OFFSET=$3
BASEFILENAME=$4

# MAXNUM_DIGITS=$4

mkdir -p $DIR_OUT
for file in $DIR_IN/*.tif 
do
	FILENAME=$(basename $file .tif)
	DIRNAME=$BASEFILENAME   #$(basename $DIR_IN)
	NUM=$(echo $FILENAME | sed s,${DIRNAME}-,,)
	ABSNUM=$(( $NUM + $OFFSET ))
# i=1
# while ABSNUM>=10 {
#  ABSNUM = ABSNUM / 10;
# i++
# }
# for j=0 ; j< i; j++ ZEROS << 0;
	cp $file $DIR_OUT/${ABSNUM}.tif
done



#put the zeros (launch the command inside the output directory)========================
#find the number of digits
# for gigigo in [1-9].tif;do mv $gigigo 00${gigigo};done

# for gigigo in [1-9][0-9].tif;do mv $gigigo 0${gigigo};done

# for gigigo in [1-9][0-9][0-9].tif;do mv $gigigo ${gigigo};done


#==adjust the image==========================================

#put the rotate.scm script into .gimp-2.6/scripts
# cd to the output directory
# launch ;;  gimp -i -b '(myrotate "*.tif" 1)' -b '(gimp-quit 0)'
# # # # batch command executed successfully

#============convert from .tif to .pdf  / tiff2pdf
#go to the output directory
# for file in *.tif;do tiff2pdf $file -o $(basename $file .tif).pdf; done

#===============then merge pdf
# (run this command only once, if you stay in the same directory!)
# pdftk *.pdf cat output combined.pdf 

#===============clean...=============
