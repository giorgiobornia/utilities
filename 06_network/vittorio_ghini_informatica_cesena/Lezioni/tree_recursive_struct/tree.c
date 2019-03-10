/* tree.c */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_NODO {
   double	x;
   s_NODO	*destra;
   s_NODO	*sinistra;
   }  NODO;

#define FMAX 1000000.0

double frand ( double fmax );
void init_root (NODO* *ppnodo );
void visita_anticipata_albero ( NODO *pnodo );
void dealloca_albero ( NODO* *ppnodo );
int insert( double x , NODO* *ppnodo );

void main(void)
{
unsigned int n, i;
double x , seme;
NODO *root;
int ris;

seme=1.0;
srand(seme);
init_root(&root);
printf("numero nodi ? ");
scanf("%d",&n);
for(i=0;i<n;i++)
   {
   x = frand(FMAX);
   ris = insert( x , &root );
   if(ris==0)
      printf("elemento %f gia' presente\n",x);
   }
visita_anticipata_albero(root);
dealloca_albero(&root);
}

void init_root(NODO* *ppnodo)
{
*ppnodo=NULL;
}

void visita_anticipata_albero(NODO *pnodo)
{
if(pnodo)
   {
   visita_anticipata_albero(pnodo->sinistra);
   printf("%lf ",pnodo->x);
   visita_anticipata_albero(pnodo->destra);
   }
}

void dealloca_albero(NODO* *ppnodo)
{
if(*ppnodo)
   {
   dealloca_albero( &((*ppnodo)->sinistra) );
   dealloca_albero( &((*ppnodo)->destra) );
   free(*ppnodo);
   *ppnodo=NULL;
   }
}


double frand(double fmax )
{
double f;
int n;
n=rand();
f = fmax * ((double)n) /  ((double)RAND_MAX);
/* return( ((double)rand()) /  ((double)RAND_MAX)) ); */
return(f);
}

int insert( double x , NODO* *ppnodo )
{
if(  ! (*ppnodo)  )
   {
   *ppnodo = (NODO*) calloc ( 1 , sizeof(NODO) );
   if( ! (*ppnodo) )
      {   fprintf(stderr,"calloc failure\n"); exit(0); }
   (*ppnodo)->x=x;
   (*ppnodo)->destra   = NULL;
   (*ppnodo)->sinistra = NULL;
   }
else
   {
   if (x == (*ppnodo)->x )
      return(0); /* elemento gia' presente */
   else
      {
      if ( x < (*ppnodo)->x )
	 return( insert( x , & ((*ppnodo)->sinistra) )  );
      else
	 return( insert( x , & ((*ppnodo)->destra) )  );
      }
   }
}

