#include <stdio.h>
#include <mpi.h>

int main (int argc, char * argv[])
{
  int err, nproc, myid;
  MPI_Status status;
  float a[2],b[2];
  err = MPI_Init(&argc, &argv);
  err = MPI_Comm_size(MPI_COMM_WORLD, &nproc);
  err = MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  if( myid == 0 ) {
    a[0] = 2.0;
    a[1] = 4.0;

   MPI_Recv(b, 2, MPI_FLOAT, 1, 11, MPI_COMM_WORLD,&status);
   MPI_Send(a, 2, MPI_FLOAT, 1, 10, MPI_COMM_WORLD);
  }
   else if( myid == 1 ) {
   a[0] = 3.0;
   a[1] = 5.0;
   MPI_Recv(b, 2, MPI_FLOAT, 0, 10, MPI_COMM_WORLD,&status);
   MPI_Send(a, 2, MPI_FLOAT, 0, 11, MPI_COMM_WORLD);
  }

printf("Il mio processo e' %d, a[1] vale %f, a[2] vale %f\n",myid,a[0],a[1]);

  err = MPI_Finalize();
}
