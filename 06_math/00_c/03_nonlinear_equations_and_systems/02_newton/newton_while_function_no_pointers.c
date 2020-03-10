#include <stdio.h>
#include <math.h>

/* Zero di una funzione con il metodo di Newton-Raphson */


/*
 Commenti:
 Qui non si parte da un intervallo predefinito.
 Prima l'algoritmo di bisezione richiedeva di isolare 
 un intervallo in cui la funzione era continua e aveva un solo zero.
 Qui si vuole annullare la funzione in un punto che non
 si sa dove sia, e si parte da un altro punto che non si sa
 se sia quello in cui si annulla la funzione.
- E' richiesta la conoscenza SIA della funzione
  SIA della sua derivata prima.
- Problema:
  C'e' un raggio di convergenza per ogni zero,
  non e' detto che si sappia calcolare precisamente
  ma di solito ci sono delle stime per maggiorazione,
  e questo raggio di convergenza e' FINITO, magari anche molto piccolo.
  Quindi, se parti da un punto ottieni qualcosa,
  se parti da un altro punto ottieni qualcos'altro.
  - Sicuramente se un dato punto intorno al punto che vuoi considerare
    va a convergere dentro un altro zero, allora quel punto
    non sta dentro il raggio di convergenza dello zero
    che io considero. E' un modo per determinare 
    il raggio di convergenza "per tentativi",
    come l'algoritmo dell'avvicinamento decimale per il calcolo degli zeri
    
    - think of passing function and derivative as FUNCTION POINTERS
 */


/* definizione della funzione di cui si vuole calcolare lo zero e della sua derivata */
double func(double);
double fprime(double);


void newton(FILE * outfile, const int n_max, const double eps, const double x0)  {

    
    /* numero di iterazioni */
    int n;
    /* inizializzazione delle variabili */
    double x, x_old, err;
    x     = x0;
    x_old = x0;
    err   = 10.;
    n     = 0;
  
    /* apertura del file di output e scrittura della intestazione */
    fprintf(outfile,"----------------------------------------------------\n");
    fprintf(outfile,"| it |         x      |     err      |      f(x)     |\n");
    fprintf(outfile,"----------------------------------------------------\n");
  
    /* la condizione del while e' determinata dalla precisione cercata */
    while(err > eps && n < n_max) {
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
    
}


int main() {

    /* punto di partenza, soluzione, soluzione vecchia, precisione desiderata, errore */
    double x0, eps;
    const int n_max = 50;

    FILE * outfile = stdout;

    
    x0 = -8000.;
    eps = 0.0000000001;

    
    newton(outfile, n_max, eps, x0); 


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
