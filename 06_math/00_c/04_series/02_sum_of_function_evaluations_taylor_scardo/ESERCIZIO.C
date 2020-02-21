#include <stdio.h>
#include <math.h>
#define h 11
#define j 0.000001

int main ()

{

FILE *Mio;
Mio = fopen("Rangoni.dat","w");
if (fopen("Rangoni.dat", "w") == NULL)
   {
   printf ("Mi dispiace ma non riesco ad aprrti il file");
   }

fprintf (Mio, "\n\n\t Nome:                       Enrico");
fprintf (Mio, "\n\t Cognome:                    Rangoni");
fprintf (Mio, "\n\t Numero di matricola:        0000218316");
fprintf (Mio, "\n\t Mail:                       movimento.statico@libero.it");
fprintf (Mio, "\n\t Esercizio:                  SER-5\n\n\n\n");



/* Bisogna calcolare la serie di Taylor della funzione f(x)= sin^-1(x) con |x|<1 */

int n, z1, z2, z3, contatore;
double a, b, c, k, f, somma, x, errore;

a=1;
b=1;
z1=1;
z2=-1;
z3=0;
n=1;

fprintf (Mio, "\n\n\t n ha valore %d", n);
fprintf (Mio, "\t Il valore del coefficiente che moltiplica la potenza è 1.000000");

for (n=2; n<=h; n++)
	{
	z2=z2+2;
    z1=z1+2;
	z3=z3+2;
	a*=z2;
	b*=z3;
    fprintf (Mio, "\n\t n ha valore %d", n);
	c=a/(b*z1);
	fprintf (Mio, "\t Il valore del coefficiente che moltiplica la potenza è %f ", c);
    }

n=1;
x=-0.4;

fprintf (Mio, "\n\n\t Valore di n=%d", n);
fprintf (Mio, "\t Valore parziale = %f", x);


a=1;
b=1;
z1=1;
z2=-1;
z3=0;
k=x;
somma=x;

for (n=2; n<=h; n++)
	{
	z2=z2+2;
    z1=z1+2;
	z3=z3+2;
	a*=z2;
	b*=z3;
	k*=(x*x);
	c=(a*k)/(b*z1);
	somma+=c;
	fprintf (Mio, "\n\t Valore di n=%d", n);
	fprintf (Mio, "\t Valore parziale = %f", somma);
	}

x=0.6;
somma=0.6;
k=x;
a=1;
b=1;
z1=1;
z2=-1;
z3=0;
contatore=1;

for (n=1; n<=10; n++)
    {
	z2=z2+2;
	z1=z1+2;
	z3=z3+2;
	a*=z2;
	b*=z3;
	k*=(x*x);
	c=(a*k)/(b*z1);
	if (c>j || c<-j)
	   {
	   somma+=c;
	   contatore++;
	   }

	}
fprintf (Mio, "\n\n\n\n\t La somma dei termini aventi valore assoluto maggiore di 0.000001 è %f", somma);
fprintf (Mio, "\n\t I termini considerati sono %d", contatore);





















f=asin(0.6);
n=1;
x=0.6;
a=1;
b=1;
z1=1;
z2=-1;
z3=0;
k=x;
somma=x;
errore=fabs(f-somma)/fabs(f);
fprintf (Mio, "\n\n\n\n\t L'errore dei primi 1 termini è %f", errore);

for (n=2; n<=h; n++)
	{
	z2=z2+2;
    z1=z1+2;
	z3=z3+2;
	a*=z2;
	b*=z3;
	k*=(x*x);
	c=(a*k)/(b*z1);
	somma+=c;
	errore= fabs(f-somma)/fabs(f);
	fprintf (Mio, "\n\t L'errore dei primi %d termini è %f", n, errore);

	}
}
