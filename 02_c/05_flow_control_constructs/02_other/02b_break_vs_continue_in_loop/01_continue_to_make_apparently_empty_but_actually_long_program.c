/*
 * This program does nothing inside the body of the for loop,
 but it updates i and checks for the condition,
 so it does stuff.
 If you want, it is an example of "finite loop" of quite long length
 */


#include <stdio.h>

int main()
{

 int i;

  for (i = 0; i < /*1e9*/1e10; i++) {
      
     continue; 
     
     printf("----- After: %d\n", i);
  }

  return 0;
 
}
