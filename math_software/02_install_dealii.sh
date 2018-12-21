#!/bin/bash

DEALII_DIR=$HOME/software/

DEALII_SRC=dealii
DEALII_BUILD=dealii_build
DEALII_INSTALL=dealii_install

cd $DEALII_DIR
git clone https://github.com/dealii/$DEALII_SRC.git

mkdir $DEALII_BUILD
cd $DEALII_BUILD

cmake -DCMAKE_INSTALL_PREFIX=$DEALII_DIR/$DEALII_INSTALL/   $DEALII_DIR/$DEALII_SRC/
make -j $((`nproc` - 1)) install
make test
