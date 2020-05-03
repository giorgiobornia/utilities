#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 #define MYFUNC 12 
#include "../myfunctions.h"

 #define MYMETHOD 5 
#include "methods.h"


#define N 10      /* Numero di intervalli della suddivisione più grossolana */
#define NRAF 4    /* Numero di raffinamenti, compresa la suddivisione più grossolana:
                     10, 20, 40, 80 intervalli
                     AAA: Se cambi NRAF, devi cambiare l'allocazione di xxx[] e yyy[] !!! */


double fun(double);
double primitiva(double x);
double derivata(double x); /*per trapezi con correzione finale*/


int main() {

FILE   *outfile;
double a, b, dx, xxx[N*2*2*2+1], yyy[N*2*2*2+1], integr[NRAF], int_exact, conv, error_coarse, error_fine;
int    i, n, is, nraf, nmethod, nfunc;

  a = X_A;
  b = X_B;

        n = N;
     nraf = NRAF;
    nfunc = MYFUNC;
nmethod = MYMETHOD;

   outfile = fopen(METHODFILE,"a");
 fprintf(outfile, "-----------------------------------------------------\n");
 fprintf(outfile, "--------------- FUNZIONE %d -------------------------\n", nfunc);
 fprintf(outfile, "----------------------------------------------------\n");

    if (nmethod == 5)  {
      if (n % 2 != 0) { fprintf(outfile,"For the Simpson's method the number of subdivisions must be EVEN \n"); abort(); }
    }
      
   for(is = 0; is < nraf; is++) {   /*inizio ciclo is*/
     
   integr[is] = 0.;  
 
   n *= 2;   if (is == 0) n = N; /* in questo modo posso avere un N iniziale sia pari sia dispari.
                                L'inizializzazione "n = N/2" al di fuori del ciclo "is"
                                avrebbe arrotondato per difetto nel caso di N dispari.
                                "N/2" e' infatti una divisione tra intero e intero,
                                che si comporta diversamente dalla divisione tra double. */

   dx = (b-a)/n;
   
   for (i = 0; i < n+1; i++) {
     
       xxx[i] = a + i*dx;
       yyy[i] = fun(xxx[i]);
	if (nmethod == 0)  {
        	  if ( i != 0 ) { integr[is]  +=  fun( (xxx[i-1] + xxx[i])*0.5 ) ; }       /* metodo rettangoli, punto medio */
	}
	else if (nmethod == 1)  {
	       if ( i < n ) { integr[is] +=  yyy[i] ; }                            /* metodo rettangoli, estremo inferiore */
	}
	else if (nmethod == 2)  {
        	if ( i != 0 ) { integr[is] +=  yyy[i] ; }                        /* metodo rettangoli, estremo superiore */
	}
 	else if (nmethod == 3)  {
        	if ( i != 0 ) { integr[is] +=    (yyy[i-1] + yyy[i])*0.5 ; }                        /* metodo trapezi*/
	}
 	else if (nmethod == 4)  {
        	if ( i != 0 ) { integr[is] +=    (yyy[i-1] + yyy[i])*0.5 ; }                        /* sempre trap e dopo correggo*/
	}
 	else if (nmethod == 5)  {
        	 if ( i%2 == 0 && i != 0 ) { integr[is] +=  ( yyy[i-2] + 4.*yyy[i-1] + yyy[i] )/3. ; }       /* Simpson*/
	}
    
  }

    integr[is] *= dx; 
    
    if (nmethod == 4)  {  integr[is]  += - dx*dx/12.*(derivata(b)-derivata(a)); }
    
 
   fprintf(outfile,"Raffinamento n. %d con %d intervalli: l'integrale vale %.8f\n", is,n,integr[is]);

   } /*fine ciclo is*/

   int_exact = primitiva(b) - primitiva(a);
   fprintf(outfile,"--------------------------L'integrale analitico vale: %.8f\n",int_exact);

   
  /* A questo punto ho NRAF valori dell'integrale 
  e li posso usare per calcolare gli ordini di convergenza locali */   

    for (is = 0; is < nraf - 1; is++) {
      
         error_fine   = integr[is+1] - int_exact;
 
        if ( ( error_fine != 0. ) )  {  /* Evitiamo la divisione per zero */
        
         error_coarse = integr[is]   - int_exact;
       
         conv = 1./log(2.) * ( log( fabs( error_coarse / error_fine ) ) );
       
         fprintf(outfile,"Tra raffinamento n. %d e n. %d: l'ordine di convergenza locale vale %.8f\n",is,is+1,conv);
        }
       
        else {
            fprintf(outfile,"L'integrale e' stato calcolato proprio esattamente\n");
         }
   
    }


return 0;

}



double fun(double x)   {

double y;
y = FUNC(x);

return y;
}

double primitiva(double x)   {

double y;
y = FPRIMITIVE(x);

return y;
}

double derivata(double x)   {

double y;
y = FDERIVATIVE(x);

return y;
}


/*COMMENTI:
 - Calcolo dell'integrale analitico con una funzione primitiva
   nota a priori.
 - Ciclo for sul numero di raffinamenti NRAF
 - Allocazione degli array xxx[] e yyy[]
   al numero di nodi previsto dal raffinamento piu' fine: 
   N x 2^(NRAF-1) + 1 = 10 x 2^(3) + 1 = 81
 - Provate a cambiare N: controllate che il programma funzioni
   con N pari e dispari.
 - Provate a cambiare NRAF: ATTENTI a RIALLOCARE xxx[] e yyy[] !
 - Provate a cambiare le formule del metodo dei rettangoli
   (punto medio, estremo inferiore ed estremo superiore);
   confrontate gli ordini di convergenza.
 - Sostituite con altre formule di integrazione (es. trapezi, Simpson):
   verificate quali sono gli ordini di convergenza.
 */
/* 
 * Basically we have to pass to this C program 2 informations:
 * the FUNCTION and the METHOD.
 * We also had to do that for the LATEX files.
 * The difference is that we have MORE WAYS of COMMuniCATING with a program:
 * first of all we can distinguish COMPILE TIME and RUN TIME.
 * Then, both at compile and at link time we can distinguish
 * between COMMAND LINE and FILE.
 * In fact you can communicate with the PREPROCESSOR (COMPILE TIME)
 *    with -D - command line
 * or with #define in the FILE
 * Then you can communicate with the EXECUTABLE (RUN TIME)
 *    with COMMAND LINE ARGUMENTS 
 * or with an EXTERNAL FILE.
 * 
 * You cannot have this degree of flexibility with latex, I think...
 * Well, i discovered that you CAN pass arguments to latex compiler.
 * In principle, this could avoid you to MODIFY the source file IN PLACE
 * with some string manipulation (sed,awk,python...whatever).
 * But this becomes uncomfortable if you have several options to cope with.
 * In general, it is more elegant to act on the file than having a 
 * possibly very long command line...
 * 
 * HOW TO LOOP OVER the METHODS
 * In order to do a for loop over the methods, i naturally defined to 
 * ASSOCIATE a NUMBER INDEX to every method.
 * In order to make the code more readable, i could have defined an ENUM also...

*/
