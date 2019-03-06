#include <omp.h>
#include <stdio.h>

#define N 100
void Initialize(int *vett, size_t n , int val)
{
size_t k;
for (k=0;k<n;k++)
	vett[k]=val;
}

int CalcolaSomma(int *vett, size_t n)
{
size_t k;
int tot=0;
for (k=0;k<n;k++)
	tot+=vett[k];
return tot;
}

int main(int argc, char**argv)
{
int a[N],b[N],c[N];
int num_threads_expected=3;
int *vettori[]={a,b,c};
int k;
int somma=0;
int totale_parziale[3];
Initialize(a,N,1);
Initialize(b,N,2);
Initialize(c,N,3);

#ifdef USE_OPENMP
omp_set_num_threads(num_threads_expected);
#endif

#pragma omp parallel 
{
int rank=0;
int size=1;

#pragma omp for reduction(+:somma)
	for(k=0;k<3;k++)
	{
#ifdef USE_OPENMP
	size=omp_get_num_threads();
	rank=omp_get_thread_num();
#endif

		totale_parziale[k]=CalcolaSomma(vettori[k],N);
		printf("ciao sono il thread %d di %d, il mio totale parziale e'%d \n",
			rank, size, totale_parziale[k]);
		somma+=totale_parziale[k];
	}

#pragma omp master
{
for (k=0;k<3;k++)
	printf("Il totale del vettore %d vale %d\n",k, totale_parziale[k]);
}
}
return 0;
}
