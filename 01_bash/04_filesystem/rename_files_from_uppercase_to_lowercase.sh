#!/bin/bash 



#translate from uppercase to lowercase
# for file in *; do myvar=`ls $file | tr [:upper:] [:lower:]`; mv $file $myvar; done
# for file in *; do if [ -d $file ]; then myvar1=`ls $file`; myvar2=`ls $file | tr '[:upper:]' '[:lower:]'`; cd $file; mv $myvar1 $myvar2; cd ..; fi; done
