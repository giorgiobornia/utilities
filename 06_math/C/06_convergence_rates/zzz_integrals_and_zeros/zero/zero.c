#include <stdio.h>
#include <math.h>
#include <stdlib.h> /*for abort*/


 #define MYFUNC 12 
#include "../myfunctions.h"

 #define MYMETHOD 0 
#include "methods.h"

#define EPS 1.e-10
#define NITMAX 40

double func(double);
double fprime(double);

int main() {

    FILE *outfile;
    int n,nfunc,nmethod,nitmax,i;
    double xa,xb; /*intervallo, che serve anche per l'inizializzazione della successione*/
    double x,x_old,eps,err,x_n[NITMAX],err_n,err_np1,conv,p; /*x_old not needed for bisection*/
    double x_oold;   /*solo per la secante*/
    double x_l,x_r;/* left & right, solo per la bisezione*/

     nmethod = MYMETHOD; /*Method-related*/
     p = CONV_ORDER; /*Method-related*/
    
    xa = X_A;
    xb = X_B;
    
    eps = EPS;
    nfunc = MYFUNC;
    nitmax = NITMAX;

    outfile = fopen(METHODFILE,"a");  /* AAA APPEND MODE*/
 fprintf(outfile,"-----------------------------------------------------\n");
 fprintf(outfile,"--------------- FUNCTION %d -------------------------\n",nfunc);
 fprintf(outfile,"----------------------------------------------------\n");
 
    /* inizializzazione delle variabili */
    err   = 10.;
    n     = 0;
    x      = xb;
    x_n[0] = x;
    x_old  = xb;
    x_oold = xa;  /*solo per la secante*/
    
    x_l    = xa;             /*solo per la bisezione*/
    x_r    = xb;             /*solo per la bisezione*/
    if (nmethod == 3)  {     /*solo per la bisezione*/
     if (func(x_l)*func(x_r)>=0.) {
       fprintf(outfile,"The bisection method cannot start --------\n"); abort();
      }
       x      = 0.5*(x_l + x_r);
       x_n[0] = x;
    }
    

 fprintf(outfile,"----------------------------------------------------\n");
 fprintf(outfile,"| it |         x      |     err      |      f(x)     |\n");
 fprintf(outfile,"----------------------------------------------------\n");
  
    while(err > eps && n < nitmax) {
      

	if (nmethod == 0)  {
	x      = x_old-func(x_old)/fprime(x_old);
	err    = fabs(x-x_old);
	x_old  = x;
	  }
	  
	else if (nmethod == 1)  {
	  x     = x_old-func(x_old)*(x_old-x_oold)/(func(x_old)-func(x_oold));
          err   = fabs(x-x_old);
         x_oold = x_old;
         x_old  = x;
	}
	
	else if (nmethod == 2)  {
	  x   = func(x_old) + x_old;
	err   = fabs(x-x_old); 
	x_old = x;
	}
	
	else if (nmethod == 3)  {
          x      = 0.5*(x_l + x_r);
	  if (func(x_l)*func(x)<0.) {x_r = x;}
	  else                      {x_l = x;} /*qui ci puo' essere un problema se becchi ESATTAMENTE lo zero*/
	  err=fabs(x_l-x_r);                   /*one of the two is surely x, the other is x_old */
	}
	

	n++;
        x_n[n] = x;  /*riempi il vettore con le iterazioni intermedie*/


	fprintf(outfile,"| %2d | %20.18e | %20.18e | %20.18e |\n",n,x,err,func(x));
    }

    fprintf(outfile,"Zero sought between xa = %f and xb = %f, computed in %d iterations:  x = %12.10f\n",xa,xb,n,x);

    
    for (i=0;i<(n-1);i++) {
    /* Qui l'estremo superiore di i potrebbe essere 
      i<(n-2),
      i<(n-1) oppure anche 
      i<(n).
      Tutti questi casi consentirebbero di non sforare la memoria.      
      
      Perche' si dice di usare i<(n-2) ?
      E' una questione che riguarda gli ultimi 3 valori
      messi nel vettore x_n[], 
      cioe' x_n[n-2],x_n[n-1] e x_n[n].
      Puo' succedere che siano talmente vicini
      che la loro differenza non sia piu' significativa
      per effetto della CANCELLAZIONE NUMERICA!
      
      Ovviamente il valore "analitico" di riferimento e' x,
      che e' dentro a x_n[n].
      Ora, in base alle distanze relative

      x_n[n-2] <--- D1 ---> x_n[n-1] <--- D2 ---> x_n[n]
                                                  |||
                                                   x 

      possono succedere tante cose.
      
      Prendiamo il caso i<(n), questo e' banale in quanto
      l'ultimo valore della costante della convergenza e' ZERO
      avendo uno zero esatto al numeratore. 
      Al denominatore infatti un qualcosina di DIVERSO da zero lo si ha sempre,
      (anche perche' probabilmente si sfora dentro ai numeri subnormali
      che permettono, pur non usando la virgola mobile, di rappresentare
      numeri molto molto piccoli... qual e' la soglia per passare 
      dai numeri in virgola mobile ai subnormali 2^(-2^(11))?
      no forse non passi ai numeri subnormali).
      
      Prendiamo il caso i<(n-1).
      L'ultimo valore che si calcola in tal caso e' (D2) / D1^p .
      Se D2     e' zero allora l'ultimo numero della costante C e' ZERO.
      Se D2 non e' zero e D1^p e' molto minore di D2,
      allora (D2) / D1^p diventa un numero GRANDE.
      Se D2 non e' zero e D1^p e' molto maggiore di D2,
      allora (D2) / D1^p diventa un numero PICCOLO.
      

      */
    
      err_n   = fabs( x_n[i]   - x);
//       fprintf(outfile,"=== BEWARE OF NUMERIC CANCELLATION ============  pow(err_n,p) è %20.18e\n",  pow(err_n,p));
      
     if ( err_n < 1.e-18 )   { 
       fprintf(outfile,"Probably x was computed exactly, or the difference between two values is very small\n"); }
                                    /* evitiamo la divisione per zero
                                      La condizione "uguale a zero" 
                                      e' sostituita con "minore di un numero molto piccolo"
				      a causa degli errori di arrotondamento
				      nelle operazioni tra double */ 
     else {
       
       err_np1 = fabs( x_n[i+1] - x);
//       fprintf(outfile,"=== BEWARE OF NUMERIC CANCELLATION ========== err_np1 è %20.18e\n", err_np1);

       conv = err_np1 / pow(err_n,p) ;
      
       fprintf(outfile,"The constant C in the convergence rate formula is %20.18e\n", conv);
     }
     
    }
   
   
    return 0;
}


double func(double x) {
    double y;
    y = FUNC(x);
    return y;
}


double fprime(double x) {
    double y;
    y = FDERIVATIVE(x);
    return y;
}


/* Voglio fare un test per tutte le funzioni che ho, e con tutti i metodi
 Facciamo con un metodo tutte le funzioni, le stampiamo su un unico file 
 per ogni funzione compiliamo e lanciamo l'eseguibile. Quindi il file viene sempre sovrascritto.
 Dovrei fare tanti file diversi. Se ne faccio uno unico non mi piace fare l'append,
 perche' rischio sempre di aumentare il file. Quindi posso fare che all'inizio dello script 
 il file, il cui nome so qual e', venga prima di tutto RIMOSSO,
 fuori dal loop sulle funzioni
 Se pero' voglio usare il file da solo, il rischio di append c'e' sempre
 
 
 Il punto fisso e' molto pericoloso, non converge quasi mai...
 
 */
