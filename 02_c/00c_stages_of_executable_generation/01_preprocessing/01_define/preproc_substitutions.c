#include <stdio.h>


/*
 * A #define directive is used to define a so-called "macro" 
 * 
 * It tells the preprocessor to physically substitute the defined macro everywhere
 * 
 * Notice: it doesn't work inside double quotes!
 * 
 * Notice: comments are removed from the preprocessor, so they are not involved in substitutions
 */



#define MYSUB_1  5.


#define MYSUB_2  " A\n"

// #define "MYSUB_3"  5. /* doesn't work, an identifier cannot start with double quotes */


#define MYSUB_3   MYSUB_1   /*works! So the substitution parses multiple times?! */



/* Wrote the main function all with #define  =========== */
#define MAIN_RETURN_TYPE  int

#define MAIN_STRING main

#define PARENTHESES  ()

#define FUNCTION_OPEN  {

#define FUNCTION_CLOSED   }
/* Wrote the main function all with #define  =========== */




 /* Main function ********** */

 
MAIN_RETURN_TYPE   MAIN_STRING   PARENTHESES   FUNCTION_OPEN 

    
  double a_1 = MYSUB_1; 
//   double a_2 = "MYSUB"; /* doesn't work */
  double a_2 = MYSUB_3; /* doesn't work */


  printf(" MYSUB_1 \n");   /* Substitution doesn't work inside double quotes! */
  printf( MYSUB_2 );
  printf(" %f \n", a_1);

  
  return 0;

  FUNCTION_CLOSED
  
  
