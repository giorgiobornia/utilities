#!/usr/bin/perl

package Foo;
sub bar { 
   print "Hello $_[0]\n" 
}

sub blat { 
   print "World $_[0]\n" 
}
1;

# If you want to call from the shell just one subroutine of this file,
# you just do sthg like:

# perl -MFoo -e 'Foo::blat('gigio');'

# The output of this is 'World gigio'