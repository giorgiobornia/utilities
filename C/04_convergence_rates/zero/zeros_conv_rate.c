#include <stdio.h>
#include <math.h>

/* Calcolo dello zero di una funzione
 * e calcolo dell'ordine di convergenza */

#define ITMAX    100

double func(double);
double fprime(double);

int main() {

    int n,i;
    double x0,x,x_old,eps,err,xx[ITMAX],p,err_n,err_np1,conv;
    FILE *outfile;

    x0  = +130.;      /* soluzione di primo tentativo */
    eps = 1.e-16;   /* tolleranza sulla distanza tra due soluzioni numeriche consecutive */

    /* inizializzazione delle variabili */
    x     = x0;
    xx[0] = x0;
    x_old = x0;
    err   = 10.;
    n     = 0;
  
    outfile = fopen("zero.out","w");
    fprintf(outfile,"----------------------------------------------------\n");
    fprintf(outfile,"| it |         x      |     err      |      f(x)     |\n");
    fprintf(outfile,"----------------------------------------------------\n");

    
    while(err > eps && n < ITMAX) {
      
	n++;
	
	  x = x_old - func(x_old)/fprime(x_old);        /* Newton */
	err = fabs(x - x_old);
	
	xx[n] = x;
    
	fprintf(outfile,"| %2d | %14.10f | %e | %+e |\n",n,x,err,func(x));
	x_old = x;

    }
    
    /*A questo punto il ciclo while precedente si puo' essere arrestato per due ragioni,
     una "matematica" o una "informatica". Potrebbe essersi arrestato anche per entrambe contemporaneamente*/
    if      (err > eps && n== ITMAX ) fprintf(outfile,"Arresto informatico: numero massimo di iterazioni\n");
    else if (err < eps && n < ITMAX ) fprintf(outfile,"Arresto matematico: errore minore della tolleranza ammessa\n");
    else                              fprintf(outfile,"Coincidenza tra arresto matematico e arresto informatico, molto perspicaci...\n");
      
    /* risultato finale a schermo */
    fprintf(stdout,"Zero calcolato a partire da x0 = %f con precisione %e.\n x = %12.10f in %d iterazioni\n",
	    x0,eps,x,n);       

    /*Calcolo dell'ordine di convergenza.
     La variabile x contiene il valore finale dello zero,
     l'array xx[] contiene i valori intermedi. */
    
    p = 2.;             /* ord convergenza */
    /*p = 1.9;*/        /* ord convergenza */
    /*p = 2.1;*/        /* ord convergenza */
  
    for (i=0; i < n - 2; i++)  {
    
      err_n   = fabs( xx[i]   - x);
      
     if ( err_n > 1.e-18 )   { /* evitiamo la divisione per zero
                                      La condizione "diverso da zero" 
                                      e' sostituita con "maggiore di un numero molto piccolo"
				      a causa degli errori di arrotondamento
				      nelle operazioni tra double */ 
      err_np1 = fabs( xx[i+1] - x);

      conv = err_np1 / pow(err_n,p) ;
      
       fprintf(outfile,"La costante C della formula dell'ordine di convergenza è %12.10f\n", conv);
     }
     else { fprintf(outfile,"Probabilmente x e' stato calcolato esattamente, oppure lo scarto tra due valori e' molto piccolo\n");
        }
    }
    
    return 0;
}

/* funzione studiata */
double func(double x) {
    double y;
    y = x*x +2.*x ;
    return y;
}

/* derivata prima della funzione precedente */
double fprime(double x) {
    double y;
    y = 2.*x + 2. ;
    return y;
}


/*
 COMMENTI:
 - Non forniamo a priori il valore ANALITICO della soluzione
   che ci servirebbe per calcolare l'ordine di convergenza,
   ma usiamo  al suo posto il valore NUMERICO calcolato al termine
   del nostro algoritmo (bisezione, tangente, secante, qualsiasi).
 - Doppia condizione per l'arresto del ciclo while:
   condizione "matematica" sull'errore tra due iterazioni successive,
   condizione "informatica" sul numero massimo di iterazioni,
   che ci evita calcoli infiniti 
   e ci evita lo sforamento dell'array xx[]
 - Cambiate eps, e vedete come cambia il calcolo della costante C
 - Cambiate p, e vedete per quale valore la costante C tende ad un valore costante
 - Cambiate ITMAX, e vedete se avete concesso troppe o troppe poche iterazioni
   al vostro algoritmo. Questo si riflette sia nel valore finale 
   della soluzione x, sia nel successivo calcolo della costante C.
  */
