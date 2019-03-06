#include <stdlib.h>
#include <stdio.h>
/* void myprint(float b); */

/* 
   Show the problems of implicit declaration of functions
   Compile with
   1 - 
   gcc test_badcall5-main.c test_badcall5-sub.c
      --> good compilation, wrong results
   2 -
   gcc test_badcall5-main.c test_badcall5-sub.c -Wall
      --> warning (very very dangerous ! (e.g. 64 bit pointers --> 32 bit int)) 
   3 -
   icc test_badcall5-main.c test_badcall5-sub.c
      --> default implicit declaration warning
*/


int main(int argc, char *argv[])
{
  double a;

  a = 3.14f;
  
  myprint(a);

  printf("GOOD END \n");
  return(0);
}

