#include <stdio.h>
#include <mpi.h>


int main(int argc, char * argv[])
{
int err,me,ptot;
err = MPI_Init(&argc, &argv);
printf("Hello world!\n");

err = MPI_Comm_size(MPI_COMM_WORLD,&ptot);
err = MPI_Comm_rank(MPI_COMM_WORLD,&me);
printf("I am process %d of %d\n",me,ptot);
err = MPI_Finalize();
}