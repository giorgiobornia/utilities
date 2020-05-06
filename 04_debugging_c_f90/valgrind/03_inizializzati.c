
/**
gcc 03_inizializzati.c -O0 -g -Wall -o init
valgrind -v --log-file=valgrind.report ./init
valgrind -v --leak-check=full --log-file=valgrind.report ./init
valgrind -v --show-reachable=yes --leak-check=yes --log-file=valgrind.report ./init
valgrind -v --show-reachable=yes --leak-check=yes --leak-resolution=high --log-file=valgrind.report ./init
*/

#include <stdlib.h>
#include <stdio.h>
  
  int main()
{
   int i;
   float x,y; 
   FILE *fd;
   y=10.0;
   y=x;
   printf ("x = %f\n",x);
   fprintf (stderr,"i = %d\n",i);
   fflush(stderr);
   
   fd= fopen("file.dat", "w");
//    x=0;
   fwrite(&x, sizeof(float), 1, fd);
   
//    fclose(fd);
   
   
 return 0;  
}
