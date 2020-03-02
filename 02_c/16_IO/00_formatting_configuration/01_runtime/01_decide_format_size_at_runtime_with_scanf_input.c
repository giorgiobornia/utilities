#include <stdio.h>


/* The keyword "typeof" does not yield a string, so you cannot really use it for string comparison.
 * You can use it for declarations 
 * You can try to switch among different types using preprocessor directives
 * 
 * - 
 * 
 * - Can I set the size of a format at runtime? Yes
 */


#define NUM_TYPE double
#define NUM_TYPE_FORMAT_PRINTF 'f'

// #define NUM_TYPE int
// #define NUM_TYPE_FORMAT_PRINTF 'd'


int main() {
    
    
    char string[30];   /* some big number, for now */
    NUM_TYPE some_number = 9;

//     typeof(some_number)  b;  /* That's how you could use typeof */

    int size;
    
    scanf("%d", &size);
    
   string[0] = '%';   /* you need to use SINGLE quotes, not DOUBLE quotes! Double quotes are for a string of chars */
   
   string[1] = '*';
   
   string[2] = NUM_TYPE_FORMAT_PRINTF;

   string[3] = '\n';
    
    printf(string, size, some_number);   /* This allows one to pass the desired length at runtime */
 
    int precision = 6;
    
    printf("%*.*d", size, precision, 8);   
    
}
