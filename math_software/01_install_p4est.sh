 
 MY_DEALII_VERSION=9.0.0
 MY_P4EST_PACKAGE=p4est-2.0.tar.gz
 MY_DEALII_P4EST_SCRIPT=p4est-setup.sh
 
 cd $HOME/software
 #clear the current directories
 rm $MY_DEALII_P4EST_SCRIPT

#  git clone https://github.com/cburstedde/p4est.git
 wget http://p4est.github.io/release/$MY_P4EST_PACKAGE
 
 wget https://www.dealii.org/$MY_DEALII_VERSION/external-libs/$MY_DEALII_P4EST_SCRIPT
 sh  ./$MY_DEALII_P4EST_SCRIPT  $MY_P4EST_PACKAGE   $HOME/software/p4est-install
