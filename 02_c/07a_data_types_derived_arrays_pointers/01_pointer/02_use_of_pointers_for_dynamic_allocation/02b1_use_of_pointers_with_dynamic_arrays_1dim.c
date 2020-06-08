#include <stdio.h>
#include <stdlib.h>

void alloca_double(double* *ppvet, unsigned int n)
{
  * ppvet = (double*) calloc(n, sizeof(double));
  if( !(*ppvet) ) {
      fprintf(stderr,"calloc error\n"); abort(); 
   }
   
}

double frand(double fmax )
{
double f;
int n;
n=rand();
f = fmax * ((double)n) / (  ((double)RAND_MAX)  );
/* return( ((double)rand()) /  ((double)RAND_MAX) ) ); */
return f;

}

void init_vect_random(double *v, unsigned int n)
{
unsigned int i;
for(i=0;i<n;i++)
   v[i] = frand(1000000.0);
}

void somma_vet( unsigned int n , double *v1, double *v2, double *v3)
{
    
unsigned int i;
for(i=0;i<n;i++) v3[i] = v1[i] + v2[i];

}

void stampa_vet( unsigned int n , double *v)
{
unsigned int i;
printf("{");
for(i=0;i<n;i++)  printf(" %10.3lf", v[i]);
   printf(" }\n");

 }


int main() {

unsigned int n;
double *v1, *v2, *v3,  seme, f;

 printf("dimensione vettori ? ");
 scanf("%d",&n);

 alloca_double(&v1,n);
 alloca_double(&v2,n);
 alloca_double(&v3,n);

 seme = 1.0;
 
 srand(seme);
 
 init_vect_random(v1,n);
 
  stampa_vet(n,v1);
  
  init_vect_random(v2,n);
  
  stampa_vet(n,v2);
  
  somma_vet(n,v1,v2,v3);
  
  stampa_vet(n,v3);

  return 0;
}
