#!/bin/bash


#Substitute strings in files
#every * is independent, it is like *_1 and *_2

for file in Caso*/*.xmf 
do
   sed -i 's|data_in/||g' $file
done


#Other useless way: useless to 'cd $file' then 'cd ..' at every cycle if you can write the paths directly in the 'sed' command

# for file in Caso*
# do
#    cd $file
#     sed -i 's|meshxmf.h5|../meshxmfVAR.h5|g' *.xmf
#    cd ..
# done