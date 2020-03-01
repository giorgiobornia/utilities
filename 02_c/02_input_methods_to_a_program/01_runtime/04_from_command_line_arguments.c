#include <stdio.h>

/*
 * - The main function can be defined with VARIABLE ARGUMENTS! You can put whatever list of arguments you want there
 * - Let us put the arguments that allow defining an interface with command line
 * - If the first argument is an int, it will contain the COUNT of the ARGUMENTS, unless you overwrite it inside the program
 * - If the second argument in a char **, it will contain the LIST of ARGUMENTS
 */


int main(int argc, double foo) {
    
    foo = 7.;
    
  /*  printf("%s Hello\n", argv[1]);

    double  myvar = (double) (* argv[1]);
  */  
        printf("%d Hello\n", argc);
 
       printf("%lf Hello\n", foo);
 
    
}
