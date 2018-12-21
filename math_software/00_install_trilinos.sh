#!/bin/bash


TRILINOS_SRC_FOLDER_NAME=Trilinos
TRILINOS_BUILD_FOLDER_NAME=Trilinos_build

mkdir -p $HOME/software/
cd $HOME/software/

git clone https://github.com/trilinos/$TRILINOS_SRC_FOLDER_NAME

mkdir $TRILINOS_BUILD_FOLDER_NAME
cd    $TRILINOS_BUILD_FOLDER_NAME


cmake -DTrilinos_ENABLE_ALL_PACKAGES=ON   -DCMAKE_INSTALL_PREFIX=$HOME/software/$TRILINOS_BUILD_FOLDER_NAME   $HOME/software/$TRILINOS_SRC_FOLDER_NAME   -DTPL_ENABLE_MPI=ON  -DTPL_ENABLE_Matio=OFF  -DTPL_ENABLE_BoostLib=OFF

make -j $((`nproc` - 1)) install



