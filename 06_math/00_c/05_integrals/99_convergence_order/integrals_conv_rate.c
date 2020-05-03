#include <stdio.h>
#include <math.h>

/*
 * Calcolo di integrali 
 * per vari raffinamenti
 * e calcolo dell'ordine di convergenza
 */


#define N 11      /* Numero di intervalli della suddivisione più grossolana */

#define NRAF 4    /* Numero di raffinamenti, compresa la suddivisione più grossolana:
                     10, 20, 40, 80 intervalli
                     AAA: Se cambi NRAF, devi cambiare l'allocazione di xxx[] e yyy[] !!! */

double primitiva(double x);
double fun(double);


int main() {

FILE   *pippo;
double a,b,dx,xxx[N*2*2*2+1],yyy[N*2*2*2+1],integr[NRAF],int_exact,conv,
        error_coarse,error_fine;
int    i,n,is,nraf;

  a = 5.;
  b = 8.;

  int_exact = primitiva(b) - primitiva(a);

   pippo = fopen("miocognome.dat","w");

   fprintf(pippo,"L'integrale esatto vale: %.8f\n",int_exact);
   
   nraf = NRAF;

   for(is = 0; is < nraf; is++) {   /*inizio ciclo is*/
     
   integr[is] = 0.;  
 
   n *= 2;   if (is==0) n = N; /* in questo modo posso avere un N iniziale sia pari sia dispari.
                                L'inizializzazione "n = N/2" al di fuori del ciclo "is"
                                avrebbe arrotondato per difetto nel caso di N dispari.
                                "N/2" e' infatti una divisione tra intero e intero,
                                che si comporta diversamente dalla divisione tra double. */

   fprintf(pippo,"Raffinamento n. %d: %d intervalli.\n",is,n);
 
   dx = (b-a)/n;
   
   for (i = 0; i < n+1; i++) {
     
       xxx[i] = a + i*dx;
       yyy[i] = fun(xxx[i]);
     fprintf(pippo," %15.8f   %15.8f\n", xxx[i], yyy[i] );
      /*if ( i!= 0 ) { integr[is]  +=  (yyy[i-1] + yyy[i])*0.5 ; }*/       /* metodo rettangoli, punto medio */
       if ( i < n ) { integr[is] +=  yyy[i] ; }                            /* metodo rettangoli, estremo inferiore */
       /*if ( i!= 0 ) { integr[is] +=  yyy[i] ; }*/                        /* metodo rettangoli, estremo superiore */
    }

    integr[is] *= dx; 

   fprintf(pippo,"Raffinamento n. %d: l'integrale vale %.8f\n", is, integr[is]);

   } /*fine ciclo is*/

  /* A questo punto ho NRAF valori dell'integrale 
  e li posso usare per calcolare gli ordini di convergenza locali */   

    for (is = 0; is < nraf - 1; is++) {
      
         error_fine   = integr[is+1] - int_exact;
 
        if ( ( error_fine != 0. ) )  {  /* Evitiamo la divisione per zero */
        
         error_coarse = integr[is]   - int_exact;
       
         conv = 1./log(2.) * ( log( fabs( error_coarse / error_fine ) ) );
       
         fprintf(pippo,"Tra raffinamento n. %d e n. %d: l'ordine di convergenza locale vale %.8f\n",is,is+1,conv);
        }
       
        else {
            fprintf(pippo,"L'integrale e' stato calcolato proprio esattamente\n");
         }
   
    }


return 0;

}



double fun(double x)   {

double y;
y= x*x-5.;

return y;
}

double primitiva(double x)   {

double y;
y= x*x*x/3. - 5.*x;

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