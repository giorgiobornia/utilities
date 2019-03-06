#include <stdio.h>
#ifdef USEMPI
#include <mpi.h>
#endif

int main(int argc, char *argv[])
{
  int rank, nprocs;
  float a, b;
  int right, left;
#ifdef USEMPI
  MPI_Status status;
#endif

#ifdef USEMPI
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  left  = rank-1;
  right = rank+1;
  if(rank == 0) left = nprocs-1;
  if(rank == nprocs-1) right = 0;
#else
  rank = 0;
  nprocs = 1;
  left = 0;
  right = 0;
#endif

#ifndef USEMPI
  printf("Serial version **** \n");
#else
  printf("MPI version **** \n");
#endif

  printf("rank, size = %d %d \n", rank, nprocs);
  a = 100;
  b = -1;

#ifdef USEMPI
  MPI_Send(&a, 1, MPI_FLOAT, right, 1, MPI_COMM_WORLD);
  MPI_Recv(&b, 1, MPI_FLOAT, left , 1, MPI_COMM_WORLD, &status);
#else
  b = a;
#endif
  
  printf("a, b = %f %f \n", a, b);

#ifdef USEMPI
  MPI_Finalize();
#endif

}
