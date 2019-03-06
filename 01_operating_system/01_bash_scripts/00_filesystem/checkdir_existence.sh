#/bin/sh
#check dir
#export DIR

for DIR in {data_in,output}
do
ls $DIR  &> /dev/null
  if [ $? != 0 ]
  then
      mkdir $DIR
      echo "Created directory $DIR "
  else
      echo "Directory $DIR was already there"
  fi
done