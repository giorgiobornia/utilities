#include <stdlib.h>
#include <stdio.h>

#define DIM 25000000

/**
  test memory leaks problem
  ulimit -v 400000 
  to don't crash the node
  run on /scratch to dump core without finish the quota
  1 -
  Running with last = 2   --> all ok
  2 -
  Running with last = 10  --> all ok until i = 4, after crash ! (with the 
     same operations that work until j = 4 ! )
  Use 
  valgrind --leak-check=full --show-reachable=yes ./a.out
  to find the problem 
  
  gcc 9_allocate.c -O0 -Wall -g -o allocate
  ./allocate
  valgrind --log-file=Valgrind.Report ./allocate 
  valgrind -v --log-file=Valgrind.Report ./allocate
  valgrind -v --leak-check=full --log-file=Valgrind.Report ./allocate
  valgrind --tool=memcheck -v --log-file=Valgrind.Report ./allocate
*/

void mysub(float **a, int dim)
{
  int j;
  
  (*a) = (float *)malloc(sizeof(float)*dim);
  
  for(j=0; j<dim; j++)
    {
      (*a)[j] = 7.;
    }
}

int main(int argc, char *argv[])
{
  float *a;
  int i;
  int mydim = DIM;
  int last;


  printf("Insert last \n");
  scanf("%d",&last);
  for(i=0; i<last; i++)
    {
      printf("i = %d \n", i);
      mysub(&a, mydim);
    }

  printf("a = %f \n", a[0]);
// 	free(a);
// 	free(a);
  return(EXIT_SUCCESS);
}
