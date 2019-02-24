#include <stdio.h>
#include <math.h>

/* definizione della funzione di cui si vuole calcolare
   lo zero                                              */
double func(double);

int main() {

  /* numero di iterazioni */
  int n;
  /* punti di partenza, soluzione, soluzioni vecchia, precisione
     desiderata, errore,                                         */
  double x0,x1,x,x_old,x_old2,eps,err;

  FILE *infile;
  FILE *outfile;

  /* apertura del file di input e lettura delle variabili */
  infile = fopen("secante.in","r");
  if (infile != NULL) {
    fscanf(infile,"%lf",&x0);
    fscanf(infile,"%lf",&x1);
    fscanf(infile,"%lf",&eps);
  }
  else {
    fprintf(stderr,"errore nel file di input!\n");
    return 1;
  }


  /* inizializzazione delle variabili */
  x       = x1;
  x_old   = x1;
  x_old2  = x0;
  err     = 10.;
  n       = 0;

  /* apertura del file di output e scrittura della intestazione */
  outfile = fopen("secante.out","w");
  fprintf(outfile,"----------------------------------------------------\n");
  fprintf(outfile,"| it |       x      |     err      |      f(x)     |\n");
  fprintf(outfile,"----------------------------------------------------\n");
  

  /* la condizione del while e' determinata dalla precisione cercata */
  while(err > eps) {
    /* aggiornamento del numero di iterazioni eseguite */
    n++;

    /* calcolo della nuova soluzione secondo la formula di Newton-Raphson */
    x = x_old-func(x_old)*(x_old-x_old2)/(func(x_old)-func(x_old2));
    /* calcolo dell'errore assoluto */
    err = fabs(x-x_old);

    fprintf(outfile,"| %2d | %12.10f | %e | %+e |\n",n,x,err,func(x));
    x_old2 = x_old;
    x_old  = x;
  }

  /* risultato finale a schermo */
  fprintf(stdout,"Zero calcolato a partire da x0 = %f con precisione %e.\n x = %12.10f in %d iterazioni\n",
          x0,eps,x,n);

  return 0;
}

/* funzione studiata */
double func(double x) {
  double y;
  y = x*x*sin(x)-2.;
  return y;
}   

