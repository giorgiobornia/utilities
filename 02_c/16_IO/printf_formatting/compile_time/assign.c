#include <stdio.h>

/* Variable assignment 
  FORMATTING printf
 */

int main () {

 double a,b,c;
 
          printf("a = %+-28.15e, b = %+-28.15e, c = %+-28.15e \n",a,b,c);

 a = 3.;
          printf("a = %+-28.15e, b = %+-28.15e, c = %+-28.15e \n",a,b,c);

 b = 0.1;
          printf("a = %+-28.15e, b = %+-28.15e, c = %+-28.15e \n",a,b,c);    

 c = a + b;

          printf("a = %+-28.15e, b = %+-28.15e, c = %+-28.15e \n",a,b,c);
	  
	  
return 0;
}

/*Variable assignment
 - assign one by one
 - then try to align the formatting
    -use only precision for e,f
    -use .15
    -use 15
    -use 28.15
    -try to align the commas (fix the [width])
    -try to align the dots
          - with f it's ok
          - with e you can use right alignment (%-)
 */



/*   STRING FORMATTING
 	The syntax for a format placeholder is "%[parameter$][flags][width][.precision][length]type". type is the only MANDATORY indication. 
        The format placeholder is what starts with "%" and ends with a "[type]". The "type" indicator is a CONVERSION SPECIFIER,
	in the sense that it SPECIFIES how to CONVERT the corresponding VARIABLE (put in the arguments, in order)
	to a format for printing to output
*/

/* [parameter$] position of the argument (parameter) to display using this format specifier, followed by $, allowing the parameters provided to be output multiple times.
               It is a POSIX extension, not in C99
               It clearly cannot be specified at runtime because you fix the position of an argument in the printf() call at compile time 
               and you clearly cannot modify it later... 
               No [parameter$] specification means: take the current argument as considered in the given order
               */
/*[flags] specify the addition of a + sign, left alignment, ...*/
/*[width] indicates the MINIMUM field width, so if the representation requires more digits you get more than "width"*/
/*[.precision] (after the dot) has different meanings for the different types: 
 *    d: minimum number of digits
 *    e,f: number of digits after the radix (virgola); the simbols for the exponent DO NOT occupy precision spaces
 *    g: maximum number of significant digits        
 * f indicates just the NUMBER of CHARACTERS after the DOT */
/*[length] is a letter that indicates a LENGTH MODIFIER of the specified type
 * Let us just recall "Lf", "Le", "Lg" for "long double" corresponding argument
 */
/*[type] is 
   d: integers
   f: double
   e: double in exponential notation
   g: either "f" or "e": usually "f", "e" for SMALL or LARGE numbers (if the exponent from its conversion is less than -4 or greater than or equal to the precision)
      In practice, it uses the shorter of %e or %f
   E: like e but "E" instead of "e" for exponent character
   F: like f but capital letters for "NAN" and "INF",instead of "nan" and "inf"
   G: either E or F
*/


/* Specifying formatting options at RUNTIME for PRINTF
 * You can specify at runtime some options of the format placeholder, in particular [width] and [precision].
   You can pass these options as arguments of type "int" in the printf() function call.
   In order to indicate what argument to take, 
   you can use "*" or "*m$".
   The "*" indicates to take the current argument for that purpose and the following argument for the variable to be formatted.
     For instance:
   %*t uses the current variable in the order of the arguments (which must be int) for the [width] number
   %.*t uses the current int variable for the [precision] number
  In practice the * means: "use the argument you have to do the thing he has to do in this point"
 
  If the number you want to specify with * is not at the corresponding current position, you use "*m$" instead of "*", where m is the desired position
   */

/* SCANF
 * The format placeholder is " %[*][a][width][modifiers]type "
   The format placeholders for SCANF have some differences wrt PRINTF.
          [*]: assignment suppression: the input string is read but not assigned to any variable, like IGNORED
          [a]: it is a GNU extension for string conversion
      [width]: MAXIMUM FIELD WIDTH to be read by the input
  [modifiers]: they customize the type to be read
               l: in front of f for double
       "type"  is the type of conversion that scanf must perform,
               not to be confused with the type of the variable in which the input string will be stored.
               If the conversion type does not match with the corresponding variable type, the compiler tells you sthg.
               The most important are 
               d: matches pointer to int
               f: matches pointer to float
             e,E: = f
               g: = f
               a: = f
               s      Matches a sequence of non-white-space characters
               c      Matches a sequence of characters whose length is specified by the maximum field width
*/

/* PRINTF vs SCANF
 * (for SCANF the program has to know BEFORE how to read...)
   the arguments of printf are variables, the arguments of scanf are POINTERS to variables
  "%f" for printing double, "%lf" for scanning doubles
  "%%" for printing percent symbol, "%%" for reading percent (same)
  
*/

/*Examples of PRINT and SCAN
          printf("%*d   ciao  %*d",14,63,32,82);
          
          
*/
