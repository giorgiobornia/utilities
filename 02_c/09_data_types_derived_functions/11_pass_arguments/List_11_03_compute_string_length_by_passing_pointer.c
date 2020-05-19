#include <stdio.h>



int mystrlen(char *p)
{
  int i = 0;
  while (*p++) i++;
  return i;
}


int main()
{

    char str[] = "ATTENTION";
    
   printf("The string %s has length %d\n", str, mystrlen(str));
   
   return 0;
}
