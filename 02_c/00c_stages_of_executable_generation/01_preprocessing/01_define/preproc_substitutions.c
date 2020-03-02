#include <stdio.h>


/*
 * A #define directive is used to define a so-called "macro" 
 * 
 * It tells the preprocessor to physically substitute the defined macro everywhere
 * 
 * Notice: it doesn't work inside double quotes!
 * 
 * Notice: comments are removed from the preprocessor, so they are not involved in substitutions
 * 
 * Notice: operators such as *, + are also separated when preprocessor substitutions are made 
 * 
 * Notice: although still correct, it is good practice to write all #define directives outside of any function body
 */




 /* ============ */ 
#define SOME_TEST MYSUB_1    /* This works!!! In fact, first SOME_TEST is REPLACED with MYSUB_1, then MYSUB_1 is replaced with its value defined right after */

#define MYSUB_1  5.

#define MYSUB_3   MYSUB_1   /* This works too! So, the Preprocessor parses multiple times: for each #define directive, it goes over all the rows AFTER that #define */
 /* ============ */ 

/* The above scheme is counterintuitive with respect to the usual way of filling variables in C.
   In fact, in C you wouldn't do something like

   some_test = mysub_1;
   mysub_1 = 5.;
   mysub_3 = mysub_1;
*/



 
 /* ============ */ 
#define MYSUB_2  "Something to print from a define\n"  /* You can define things in double quotes */
 /* ============ */ 

 
 
 /* Errors ============ */ 
// #define "MYSUB_3"  5. /* doesn't work, an identifier cannot start with double quotes */

// #define FILE hello  /* This is a problem because FILE is a word in C corresponding to a type!!! You cannot use words of the language! */
 /* Errors ============ */ 



/* Wrote the main function all with #define  =========== */
#define MAIN_RETURN_TYPE  int

#define MAIN_STRING main

#define PARENTHESES  ()

#define FUNCTION_OPEN  {

#define FUNCTION_CLOSED   }
/* Wrote the main function all with #define  =========== */




 /* Main function ********** */

 
MAIN_RETURN_TYPE   MAIN_STRING   PARENTHESES   FUNCTION_OPEN 


  FILE* outfile;
  double b_1 = SOME_TEST;    
  double a_1 = MYSUB_1; 
  double a_2 = MYSUB_3;


  printf("MYSUB_1");   /* Substitution doesn't work inside double quotes! */
  printf("\n");
  printf( MYSUB_2 );   /* Instead, if the variable was defined with the double quotes, this works! */
  printf(" %f \n", a_1);

  
  return 0;

  FUNCTION_CLOSED
  
  
