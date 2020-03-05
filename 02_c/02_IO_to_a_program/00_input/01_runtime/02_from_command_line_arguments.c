#include <stdio.h>
#include <stdlib.h>


/*
 * - The main function can be defined with VARIABLE ARGUMENTS! You can put whatever list of arguments you want there
 * - Let us put the arguments that allow defining an interface with command line
 * - If the first argument is an int, it will contain the COUNT of the ARGUMENTS, unless you overwrite it inside the program
 * - If the second argument in a char **, it will contain the LIST of ARGUMENTS
 * - This doesn't prevent the possibility to add more arguments to the main function
 * - Can I make them 'const'?
 */

/*
 * Passing to command line does not do any type checking
 * nor it lets the program at least print some helpful message before entering the input data
 * (well, it is the same for an input file actually)
 
 */

int main(int argc, char ** argv) {
    
   double base, height, area;
   char * endptr;   

   base   = strtod(argv[1], & endptr);
   height = strtod(argv[2], & endptr);
   
   area = base * height;
   
  printf("Base: %lf\n", base);
  printf("Height: %lf\n", height);
  printf("Area: %lf\n", area);
  
    
}
