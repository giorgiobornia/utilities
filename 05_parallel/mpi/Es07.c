#include <stdio.h>
#include <math.h>
#include <mpi.h>
#define MASTER 0
int main(int argc, char** argv)
{
int Size;
int MyId;
int *data;
int totale;
int coeff;
MPI_Status Status;
MPI_Init(&argc,&argv);
MPI_Comm_size ( MPI_COMM_WORLD ,&Size );
MPI_Comm_rank ( MPI_COMM_WORLD ,&MyId );
printf("Sono il processo %d\n",MyId);
totale=MyId;
coeff=2;
while (coeff<=Size*2){
	if(MyId%coeff!=0){
		MPI_Send(&totale,1,MPI_INTEGER, MyId/coeff*coeff,1,MPI_COMM_WORLD);
		MPI_Finalize();
		printf("Il processo %d  e' stato chiuso\n",MyId);
		return 0;
	}
	else{
		if(MyId+coeff/2<Size){
			int addendo;
			MPI_Recv(&addendo,1,MPI_INTEGER,MyId+coeff/2,1,MPI_COMM_WORLD, &Status);
			totale+=addendo;
		}
	}
coeff*=2;
}
printf("Il totale e' %d\n",totale);
printf("Il processo %d e' stato chiuso\n",MyId);
MPI_Finalize();
return 0;
}
