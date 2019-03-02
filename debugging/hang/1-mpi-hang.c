#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/*
  Test to run on 2 processors: program hangs due to the second 
  rank 1 unmatched MPI_Recv. Use 
  ps -aef | grep executable
  gdb executable pid
  to attach to every running MPI process
*/

int main(int argc, char *argv[])
{
   float a;
   int b;
   int rank;
   MPI_Status status;


   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);

   fprintf(stderr, "%d : starting ... \n", rank);
   fflush(stderr);

   if(rank == 0)
     {
       a = 100.f;
       b = 200;
       MPI_Send(&a, 1, MPI_FLOAT, 1, 100, MPI_COMM_WORLD);
       /* MPI_Send(&b, 1, MPI_INT  , 1, 101, MPI_COMM_WORLD); */
     }
   else if(rank == 1)
     {
       a = -777.f;
       b = -888;
       fprintf(stderr, "%d : a, b = %f %d \n", rank, a, b);
       fflush(stderr);
       MPI_Recv(&a, 1, MPI_FLOAT, 0, 100, MPI_COMM_WORLD, &status);
       MPI_Recv(&b, 1, MPI_INT  , 0, 101, MPI_COMM_WORLD, &status);
       fprintf(stderr, "%d : a, b = %f %d \n", rank, a, b);
       fflush(stderr);
     }

   fprintf(stderr, "%d : ending ... \n", rank);
   fprintf(stderr, "%d : GOOD END \n", rank);
   fflush(stderr);

   MPI_Finalize();
}
