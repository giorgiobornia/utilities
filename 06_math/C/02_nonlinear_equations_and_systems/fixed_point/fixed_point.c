#include <stdio.h>
#include <math.h>

/* Zero di una funzione con il metodo del punto fisso */

/* definizione della funzione di cui si vuole calcolare
   lo zero e della sua derivata                         */
double func(double);


int main() {

    /* numero di iterazioni */
    int n;
    /* punto di partenza, soluzione, soluzione vecchia, precisione
       desiderata, errore                                          */
    double x0,x,x_old,eps,err;
    FILE *outfile; 

      x0 =-0.75;
     eps=0.0000001;

    /* inizializzazione delle variabili */
    x     = x0;
    x_old = x0;
    err   = 10.;
    n     = 0;
  
    /* apertura del file di output e scrittura della intestazione */
    outfile = fopen("fixed_point.out","w");
    fprintf(outfile,"----------------------------------------------------\n");
    fprintf(outfile,"| it |       x      |     err      |      f(x)     |\n");
    fprintf(outfile,"----------------------------------------------------\n");
  
    /* la condizione del while e' determinata dalla precisione cercata */
    while(err > eps) {
	/* aggiornamento del numero di iterazioni eseguite */
	n++;

	/* calcolo della nuova soluzione secondo la formula di Newton-Raphson */
	x = func(x_old) + x_old;  /*qui ci va g(x), la funzione "ausiliaria"*/
	/* calcolo dell'errore assoluto */
	 err = fabs(x-x_old);
	
	fprintf(outfile,"| %2d | %16.10f | %16.10e | %+e |\n",n,x,err,func(x));
	x_old = x;
    }

    /* risultato finale a schermo */
    fprintf(stdout,"Zero calcolato a partire da x0 = %f con precisione %e.\n x = %12.10f in %d iterazioni\n",
	    x0,eps,x,n);       

    return 0;
}

/* funzione studiata */
double func(double x) {
    double y;
    y =  x*x -x; /* qui ci va f(x), la funzione originaria     */
    return y;
}