
#include "difference.h"


main()

{
    
  const double a = 8.; 
  const double b = 19.; 

  const double c = difference(a,b);
  
  printf("The difference is %f \n", c);

}


/* compile difference.c -> difference.o 
   compile main.c -> main.o
   link main.o with difference.o
   
   gcc -c difference.c -o difference.o
   gcc -c main.c -o main.o
   gcc main.o difference.o
 */
