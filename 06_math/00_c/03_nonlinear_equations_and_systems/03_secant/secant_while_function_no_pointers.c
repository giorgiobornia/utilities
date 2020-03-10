#include <stdio.h>
#include <math.h>

/* definition of the function whose root you want to compute */
double func(double);


void secant(FILE * outfile, const int n_max, const double eps, const double x0, const double x1)  {

  int n;
  double x,x_old,x_old2,err;

    
      /* inizializzazione delle variabili */
  x       = x1;
  x_old   = x1;
  x_old2  = x0;
  err     = 10.;
  n       = 0;

  /* apertura del file di output e scrittura della intestazione */
  fprintf(outfile,"----------------------------------------------------\n");
  fprintf(outfile,"| it |       x      |     err      |      f(x)     |\n");
  fprintf(outfile,"----------------------------------------------------\n");
  

  /* la condizione del while e' determinata dalla precisione cercata */
  while(err > eps && n < n_max) {
      
    /* aggiornamento del numero di iterazioni eseguite */
    n++;

    /* calcolo della nuova soluzione */
    x = x_old - func(x_old) * (x_old - x_old2) / ( func(x_old) - func(x_old2) );
    
    /* calcolo dell'errore assoluto */
    err = fabs(x - x_old);

    fprintf(outfile,"| %2d | %12.10f | %e | %+e |\n",n,x,err,func(x));
    x_old2 = x_old;
    x_old  = x;
  }

  /* risultato finale a schermo */
  fprintf(stdout, "Zero calcolato a partire da x0 = %f con precisione %e.\n x = %12.10f in %d iterazioni\n", x0, eps, x, n);

    
    
}


int main() {

  /* punti di partenza, soluzione, soluzioni vecchia, precisione desiderata, errore */
  double x0,x1,eps;
  const int n_max = 50;  
  
  FILE *outfile = stdout;


  x0 = 1.;
  x1 = 1.1;
  eps = 0.0000000001;
  
  
  secant(outfile, n_max, eps, x0, x1);
  
  

  return 0;
}

/* funzione studiata */
double func(double x) {
    
  double y;
  y = x * x * sin(x) - 2.;
  return y;
  
}   

