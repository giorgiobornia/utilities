#include <stdio.h>

char *strcpy(char *dest, char *source)
{
    
   for (int i = 0; ; i++){
   dest[i] = source[i];
   if( ! dest[i] )
   break;
   }

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
