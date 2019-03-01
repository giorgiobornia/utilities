#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <mpi.h>
#define MASTER 0

double function(double x)
{
return sin(x);
}
double IntegraleEsatto(double a,double b)
{
return cos(a)-cos(b);
}

int main(int argc, char**argv)
{
MPI_Init(&argc, &argv);

double a=0,b=1; //estremi di integrazione
double a_MPI, b_MPI;
int N=(52+1)*16+1;//atoi(argv[1]);		//numero di punti totali, estremi inclusi
int N_start_MPI,N_end_MPI;
double dx=(b-a)/(N-1);
double integrale=0.;
double fa, fb,fc;
double integraletotale=0.;
int k;

int size;
MPI_Comm_size(MPI_COMM_WORLD,&size);
int rank;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
if(rank==MASTER)
	printf("Integrale su %d punti tra %f e %f\n=============================\n",N,a,b);
N_start_MPI=N*rank/size;
N_end_MPI=N*(rank+1)/size;
if(rank==size-1) N_end_MPI--;
a_MPI=a+dx*N_start_MPI;
b_MPI=a+dx*N_end_MPI;

#pragma omp parallel 
{
#pragma omp for reduction(+:integrale)
	for(k=N_start_MPI+1;k<=N_end_MPI-1;k++)//punti interni, contano doppio
	{
		double xc=a+dx*k;
		double fm=function(xc);//middle   
		double xa=a+dx*k-dx/2;//xleft
		double fa=function(xa);//
//printf("f(%lf)=%lf\n",xa,fa);
//printf("f(%lf)=%lf\n",xc,fm);
	//	printf("sono il thread %d di %d del processo %d, f(%lf)=%lf\n",omp_get_thread_num(),omp_get_num_threads(),rank,x,f);
		//integrale+=f;
		integrale+=fm+2*fa;
		
	}


//#pragma omp single
{
fa=function(a_MPI);
fb=function(b_MPI);
fc=function(b_MPI-dx/2);
}
}

integrale=(2*integrale+fa+fb+4*fc)/2./3.*dx;

printf("processo %d di %d; integrale in [%.15lf,%.15lf] (%d %d, N punti=%d)=%.15lf (invece di %lf)\n",rank,size,a_MPI,b_MPI,N_start_MPI, N_end_MPI,N_end_MPI-N_start_MPI+1,integrale, IntegraleEsatto(a_MPI,b_MPI));
MPI_Barrier(MPI_COMM_WORLD);
MPI_Reduce(&integrale,&integraletotale, 1, 
                MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);

if(rank==MASTER){
printf("==============================\n");
printf("integrale in [%.16lf,%.16lf]=%.16lf (invece di %.15lf)\n",a,b,integraletotale, IntegraleEsatto(a,b));
}

MPI_Finalize();
return 0;
}
