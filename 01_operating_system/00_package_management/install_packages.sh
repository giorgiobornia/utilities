#!/bin/bash


  echo "Run this script as root"
  
  echo "You may want to setup software repositories first, if you want some special packages"

  echo "Uncomment the correct command for your current package management system"
  
#uncomment one of these, depending on your package management system
INSTALL_COMMAND="zypper --non-interactive install"  #for opensuse
# INSTALL_COMMAND="apt-get --yes install"           #for ubuntu


# Development packages (compilers, libraries, etc) ==================
$INSTALL_COMMAND coreutils
$INSTALL_COMMAND binutils
$INSTALL_COMMAND diffutils
$INSTALL_COMMAND findutils
$INSTALL_COMMAND findutils-locate
$INSTALL_COMMAND emacs
$INSTALL_COMMAND vim
$INSTALL_COMMAND bash
$INSTALL_COMMAND konsole
$INSTALL_COMMAND htop
$INSTALL_COMMAND make
$INSTALL_COMMAND cmake
$INSTALL_COMMAND cmake-gui
$INSTALL_COMMAND automake
$INSTALL_COMMAND autoconf
$INSTALL_COMMAND pkg-config # for our code (the check in cmake is there)
$INSTALL_COMMAND zlib-devel
$INSTALL_COMMAND gcc
$INSTALL_COMMAND gcc-c++
$INSTALL_COMMAND gcc-fortran 
$INSTALL_COMMAND gfortran
$INSTALL_COMMAND valgrind
$INSTALL_COMMAND valgrind-devel
$INSTALL_COMMAND kcachegrind
$INSTALL_COMMAND git
$INSTALL_COMMAND git-gui 
$INSTALL_COMMAND gitk 
$INSTALL_COMMAND qgit
$INSTALL_COMMAND tig
$INSTALL_COMMAND kdiff3
$INSTALL_COMMAND kompare
$INSTALL_COMMAND gdb
$INSTALL_COMMAND kdbg
$INSTALL_COMMAND gprof # (actually, provided by binutils)
$INSTALL_COMMAND oprofile
$INSTALL_COMMAND kdevelop      #for ubuntu
$INSTALL_COMMAND kdevelop5
$INSTALL_COMMAND astyle
$INSTALL_COMMAND kate
$INSTALL_COMMAND xorg-x11
$INSTALL_COMMAND xorg-x11-devel # (for Petsc graphical output)
$INSTALL_COMMAND python
$INSTALL_COMMAND perl
$INSTALL_COMMAND swig
$INSTALL_COMMAND rpm-build
$INSTALL_COMMAND build
$INSTALL_COMMAND rpmlint
$INSTALL_COMMAND checkinstall
$INSTALL_COMMAND octave
$INSTALL_COMMAND octave-forge-symbolic
$INSTALL_COMMAND qtoctave
$INSTALL_COMMAND scilab
$INSTALL_COMMAND lapack-devel  #for trilinos
$INSTALL_COMMAND netcdf        #for trilinos
$INSTALL_COMMAND netcdf-devel  #for trilinos
$INSTALL_COMMAND blas-devel
$INSTALL_COMMAND libblas3
$INSTALL_COMMAND boost-devel 
$INSTALL_COMMAND libboost-dev # for our code (should put a check in cmake)
$INSTALL_COMMAND unzip 
$INSTALL_COMMAND unrar 

$INSTALL_COMMAND fparser-devel
$INSTALL_COMMAND flex
$INSTALL_COMMAND libtool
$INSTALL_COMMAND doxygen
$INSTALL_COMMAND doxywizard
$INSTALL_COMMAND mercurial
$INSTALL_COMMAND hgview
$INSTALL_COMMAND bison
$INSTALL_COMMAND freeglut-devel
#for hdfview
$INSTALL_COMMAND javacc
$INSTALL_COMMAND java-1_7_0-openjdk-devel
$INSTALL_COMMAND ant

# $INSTALL_COMMAND suitesparse-devel
$INSTALL_COMMAND cdecl
$INSTALL_COMMAND splint  #source code C checker
$INSTALL_COMMAND openmpi
$INSTALL_COMMAND openmpi-devel
$INSTALL_COMMAND libpsm_infinipath1


# Office packages (latex, libreoffice, etc) ==================================
$INSTALL_COMMAND pdftk
$INSTALL_COMMAND gnuplot
$INSTALL_COMMAND libreoffice
$INSTALL_COMMAND gimp
$INSTALL_COMMAND acroread
$INSTALL_COMMAND doxygen
$INSTALL_COMMAND graphviz
$INSTALL_COMMAND inkscape
$INSTALL_COMMAND kile
$INSTALL_COMMAND texlive
$INSTALL_COMMAND texlive-latex-base          #for ubuntu
$INSTALL_COMMAND texlive-latex-recommended   #for ubuntu  
$INSTALL_COMMAND texlive-latex-extra         #for ubuntu
$INSTALL_COMMAND texlive-bibtex-extra        #for ubuntu
$INSTALL_COMMAND texlive-publishers          #for ubuntu
$INSTALL_COMMAND texlive-font-utils          #for ubuntu
$INSTALL_COMMAND texlive-calligra
$INSTALL_COMMAND texlive-nopageno
$INSTALL_COMMAND texlive-algorithms
$INSTALL_COMMAND texlive-libertine
$INSTALL_COMMAND texlive-moderncv
$INSTALL_COMMAND texlive-pgfplots
$INSTALL_COMMAND texlive-preprint  # for fullpage
$INSTALL_COMMAND texlive-preview
$INSTALL_COMMAND texlive-multibib
$INSTALL_COMMAND texlive-easy      # easy macros like easytable
$INSTALL_COMMAND texlive-etoolbox
$INSTALL_COMMAND texlive-background
$INSTALL_COMMAND texlive-datatool
$INSTALL_COMMAND texlive-xypic
$INSTALL_COMMAND texlive-esdiff
$INSTALL_COMMAND texlive-nomencl
$INSTALL_COMMAND texlive-adjustbox
$INSTALL_COMMAND texlive-mdframed
$INSTALL_COMMAND texlive-elsarticle
$INSTALL_COMMAND texlive-lineno
$INSTALL_COMMAND texlive-ntheorem
$INSTALL_COMMAND texlive-cleveref
$INSTALL_COMMAND texlive-showlabels
$INSTALL_COMMAND texlive-savesym
$INSTALL_COMMAND texlive-esint
$INSTALL_COMMAND texlive-threeparttable
$INSTALL_COMMAND texlive-algorithmicx
$INSTALL_COMMAND texlive-beamertheme-metropolis
$INSTALL_COMMAND texlive-tkz-euclide
$INSTALL_COMMAND texlive-wrapfig
$INSTALL_COMMAND texlive-sttools
$INSTALL_COMMAND texlive-dblfloatfix
$INSTALL_COMMAND texlive-stix
$INSTALL_COMMAND texlive-tikz-cd
$INSTALL_COMMAND texlive-tcolorbox
$INSTALL_COMMAND texlive-polynom

# Web ====================================================
$INSTALL_COMMAND phpMyAdmin
$INSTALL_COMMAND mysql-workbench

# Multimedia packages ====================================================
$INSTALL_COMMAND imagewriter
$INSTALL_COMMAND tuxguitar
$INSTALL_COMMAND audacity #audio editing
$INSTALL_COMMAND openshot #video editing
$INSTALL_COMMAND kdenlive #video editing
$INSTALL_COMMAND libjpeg-progs
$INSTALL_COMMAND dropbox
$INSTALL_COMMAND dolphin
$INSTALL_COMMAND firefox
$INSTALL_COMMAND kaffeine
$INSTALL_COMMAND mplayer
$INSTALL_COMMAND faad2
$INSTALL_COMMAND kmid
$INSTALL_COMMAND timidity
$INSTALL_COMMAND wine
$INSTALL_COMMAND wxcam
$INSTALL_COMMAND kamoso
$INSTALL_COMMAND vlc
$INSTALL_COMMAND ktorrent
$INSTALL_COMMAND aMule amule
# codecs
$INSTALL_COMMAND libxine2-codecs 
$INSTALL_COMMAND k3b-codecs 
$INSTALL_COMMAND ffmpeg 
$INSTALL_COMMAND lame 
$INSTALL_COMMAND gstreamer-plugins-bad 
$INSTALL_COMMAND gstreamer-plugins-ugly 
$INSTALL_COMMAND gstreamer-plugins-ugly-orig-addon 
$INSTALL_COMMAND gstreamer-plugins-libav 
$INSTALL_COMMAND libdvdcss2
$INSTALL_COMMAND libdvdread3
$INSTALL_COMMAND libdvdread4
