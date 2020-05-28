#include <stdio.h>

int main()
{
  /* null-terminated string has a 0 in its last position, so it stops there  */

  int len; 
  char str[] = "mia stringa";
  
   for( len=0; str[len]; len++) ;  /* either semicolon, or {} */

       
   printf ("String length: %d \n", len);

   
 return 0;
}
