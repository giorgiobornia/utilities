#!/bin/bash



#this script is for replacing all whitespaces in file names with an underscore, "_"

# First, you have to rename all the directories 
# Then, you can rename all the files at the "end-points" of the filesystem tree
# If the directories do not have whitespaces, the directory loop will do nothing basically
# Then the last part works only on files... 
# but pay attention, could there be any other CHARACTER that gives us problems?! For instance,
# characters like ', even if they are INSIDE a FILENAME, they are INTERPRETED by the SHELL!
# THAT IS WHY IT IS ESSENTIAL that you use the DOUBLE QUOTES, see  "${NAMEONE}" and  "${NAMETWO}" !!!
# White these double quotes it should always be fine!

# The most radical approach would be to REMOVE from all the filenames ALL POSSIBLE CHARACTERS that are interpreted by the shell !!!
# This is a good policy
# So far we just stick with whitespaces ;)



if test "$1" != "--dir"; then
echo "Use --dir DIRECTORY_NAME to provide the directory to parse"; exit;
fi

if test "$3" == "--dry-run"; then
echo "DRY RUN";
fi


DIR_TO_PARSE=`readlink -f $2`
MAX_DEPTH=20

echo "========= First we rename the directories up to a maximum depth of " ${MAX_DEPTH}

VISUAL_CHECK_FILE=${TMPDIR}/check.txt;
rm -f ${VISUAL_CHECK_FILE};

for depth in $(seq 1 1 ${MAX_DEPTH}); 
do echo "========= Directory depth ========" $depth; 
FILE_DEPTH=${TMPDIR}/dir${depth}.txt;
find ${DIR_TO_PARSE}  -mindepth ${depth}  -maxdepth ${depth}  -type d -iname *" "*  > ${FILE_DEPTH};  
while read row; # OOOH, this while is read only if the files are NOT EMPTY!!! So, no mv operation will be performed TWICE
do 
NAMEONE=`echo "$row"`;
NAMETWO=`echo "$NAMEONE" | tr " " _`; 
if test "$3" == "--dry-run"; then
echo "${NAMEONE}" "     " "${NAMETWO}"  >> ${VISUAL_CHECK_FILE};# for checking visually the mv arguments first
else
mv  -v  "${NAMEONE}" "${NAMETWO}";# for renaming
fi
done < ${FILE_DEPTH}; 
rm ${FILE_DEPTH};
done


# Then you can rename the names, the "tips" of the branches

FILE_ENDPOINTS=${TMPDIR}/endpoints.txt;
rm -f ${FILE_ENDPOINTS};

find ${DIR_TO_PARSE} -iname *" "*  > ${FILE_ENDPOINTS}; 
while read row; 
do
NAMEONE=`echo "$row"`; 
NAMETWO=`echo "$NAMEONE" | tr " " _`; 
if test "$3" == "--dry-run"; then
echo "${NAMEONE}" "     " "${NAMETWO}" >> ${VISUAL_CHECK_FILE}; # for checking visually the mv arguments first
else
mv -v "${NAMEONE}" "${NAMETWO}"; 
fi
done < ${FILE_ENDPOINTS};

#short simple version for only files, no folders
#for file in *.zip; do mv "`echo "$file"`"  `echo "$file" | tr " " _` ; done