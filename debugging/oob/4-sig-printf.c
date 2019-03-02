#include <stdlib.h>
#include <stdio.h>

#define DIM 1039596

/* 
   Show a SIGSEGV due to an oob 
   printf() version
   the printf() call can change memory, hides the problem and 
   "solves" the SIGSEGV !
   Use valgrind to find the problem
*/

int main(int argc, char *argv[])
{
  float *a;
  int i, j;
  int mydim = DIM;

  char *errmsg;



  a = (float *)malloc(sizeof(float)*mydim);

  errmsg = (char *)malloc(sizeof(char)*1024);
  sprintf(errmsg, "SONO ARRIVATO QUA !!!! \n");
  printf("%s", errmsg);

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
  free(errmsg);

  return(EXIT_SUCCESS);
}
