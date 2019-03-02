#include  <stdio.h>

/*
 * Calcolo di integrali 
 * con il metodo dei rettangoli
 */

#define N 10

double fun(double);

int main() {

FILE   *pippo;
double xxx[N+1],yyy[N+1],a,b,sum,dx;
int    i;

a = 5.;
b = 8.;

   pippo=fopen("miocognome.dat","w");

 sum = 0.;

 dx = (b-a)/N;
   
   for(i = 0; i < N+1; i++) {
       xxx[i] = a + (b-a)*i/N;
       yyy[i] = fun(xxx[i]);
   fprintf(pippo," %15.8f   %15.8f\n",  xxx[i]  ,  yyy[i]   );
    if ( i!= 0 ) {sum +=  dx * (yyy[i]) ; } /*estremo superiore!*/
}

fprintf(pippo,"L'integrale vale: %.8f\n",sum);



return 0;

}



double fun(double x)   {

double y;
y= x-5.;

return y;
}


/*Commenti:
 - Scelta tra estremo superiore, estremo inferiore
   o punto medio del sottointervallo,
   diversi ordini di convergenza.
 - Uso della direttiva #define per allocazione statica
   ma "variabile".
 - Sforamenti degli array che possono non dare un errore in esecuzione!
 - Differenza tra ciclo sui nodi e ciclo sui sottointervalli.
 - Ottimizzazione dei cicli for, ma con attenzione agli indici!
 */