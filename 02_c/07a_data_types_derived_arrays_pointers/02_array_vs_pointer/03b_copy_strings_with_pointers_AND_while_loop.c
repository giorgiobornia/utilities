#include <stdio.h>

char *strcpy(char *dest, char *source)
{
    
char *ptrdest = dest;

  while( *(dest++) = *(source++) ) ;
         /* the logical condition here is an ASSIGNMENT operation.
          * Assignment operations have the feature that they RETURN the assigned value,
          * so this code stops when the assigned value is the NULL character \0, that denotes the END OF STRING */

return(ptrdest);

}

int main()
{
    
  char destination[1000];
  char * source = "Greetings";
  
  strcpy(destination, source);
  printf("%s\n", source);
  printf("%s\n", destination);

return 0;

}
