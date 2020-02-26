#include <stdio.h>
#include <math.h>

/* Zero di una funzione con il metodo di Newton-Raphson */

/* definizione della funzione di cui si vuole calcolare lo zero e della sua derivata */
double func(double);
double fprime(double);

int main() {

    /* numero di iterazioni */
    int n;
    /* punto di partenza, soluzione, soluzione vecchia, precisione desiderata, errore */
    double x0, x, x_old, eps, err;

    FILE * infile;
    FILE * outfile;

    /* apertura del file di input e lettura delle variabili */
    infile = fopen("newton.in","r");
    if (infile != NULL) {
	fscanf(infile,"%lf", &x0);
	fscanf(infile,"%lf", &eps);
    }
    else {
	fprintf(stderr,"errore nel file di input!\n");
	return 1;
    }


    /* inizializzazione delle variabili */
    x     = x0;
    x_old = x0;
    err   = 10.;
    n     = 0;
  
    /* apertura del file di output e scrittura della intestazione */
    outfile = fopen("newton.out","w");
    fprintf(outfile,"----------------------------------------------------\n");
    fprintf(outfile,"| it |         x      |     err      |      f(x)     |\n");
    fprintf(outfile,"----------------------------------------------------\n");
  
    /* la condizione del while e' determinata dalla precisione cercata */
    while(err > eps) {
	/* aggiornamento del numero di iterazioni eseguite */
	n++;

	/* calcolo della nuova soluzione secondo la formula di Newton-Raphson */
	x = x_old - func(x_old)/fprime(x_old);
    
	/* calcolo dell'errore assoluto */
	err = fabs(x - x_old);
    
	fprintf(outfile,"| %2d | %12.10f | %e | %+e |\n",n,x,err,func(x));
    
     /* aggiornamento della soluzione vecchia */
	x_old = x;
    }

    /* risultato finale a schermo */
    fprintf(stdout, "Zero calcolato a partire da x0 = %f con precisione %e.\n x = %12.10f in %d iterazioni\n", x0, eps, x, n);    

    return 0;
}

/* funzione studiata */
double func(double x) {
    
    double y;
    y = x * x * sin(x) - 2. /*x*x +2.*x + 1*/ ;
    return y;
}

/* derivata prima della funzione precedente */
double fprime(double x) {
    
    double y;
    y = 2. * x * sin(x) + x * x * cos(x) /*2.*x + 2. */;
    return y;
}
