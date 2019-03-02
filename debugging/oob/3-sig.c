#include <stdlib.h>
#include <stdio.h>

#define DIM 1039596

/* 
   Show a SIGSEGV due to an oob 
   Run test_oob3-2.c before using valgrind or debugging core 
   with gdb to show how printf() can change memory, hides the 
   problem and "solves" the SIGSEGV !
*/

int main(int argc, char *argv[])
{
  float *a;
  int i, j;
  int mydim = DIM;


  a = (float *)malloc(sizeof(float)*mydim);

  j = mydim;
  for(i=0; i<mydim; i++)
    {
      a[i] = i;
      if(i > mydim-2)
	{
	  a[j+1000] = a[i];
	}
    }

  printf("a = %f \n", a[0]);
  printf("GOOD END \n");

  free(a);

  return(EXIT_SUCCESS);
}
