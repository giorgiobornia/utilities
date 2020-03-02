#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define OUTFILE "f4.dat"

/* ---------------------------------------- *
s * Dati per il grafico di f(x)              *
 * -----------------------------------------*/

double fx(double);
/* ---------------------------------------- */
int main () {
    
  FILE *fp;
  int i,n;
  double a,b,h,x;

  /* *********************************** *
   * 1 - apri il file                    *
   * *********************************** */
  if ((fp=fopen(OUTFILE,"w")) == NULL) {
    (void) fprintf(stderr,"Non si apre: %s !\n",
		   OUTFILE);
    exit(0);
  }
  

  b = 4.;  a = -2.;  

  n = 50;
  h = (b-a)/(double)n;

  /* *********************************** *
   * 2 - stampa i valori delle ascissa e delle ordinate                *
   * *********************************** */
  x = a;
  for (i=0; i<=n; i++) {
    fprintf(fp,"%9.6f  %10.6f \n", x, fx(x));
    x += h;
  }
  fprintf(fp,"\n");
  

  fclose(fp);
}


/* ---------------------------------------- */
double fx(double x)
{
  double y,pihalf;
  
  pihalf = asin(1.);
  y = 0.25*x*x*x*x - 2.*x*x*x + x*x - 5.*x + 8.;                    

  return(y);
}

/* ---------------------------------------- *
 * f1:                                      *
 * y = 4.*sin(x) + 1. - x;                  *
 * b = 4.5;  a = 1.5;                       *
 * ---------------------------------------- *
 * f2:                                      *
 * y = exp(-x)  - (x+5.);                   *             
 * b = 3.;  a = -3.;                        *
 * ---------------------------------------- *
 * f3:                                      *
 * y = (x+1.)*exp(x/4.) - 2.;               *         
 * b = 3.;  a = -3.;                        *
 * ---------------------------------------- *
 * f4:                                      *
 * y = 0.25*x*x*x*x - 2.*x*x*x +  x*x - 5.*x + 8.;    *
 * b = 4.;  a = -2.;                        *
 * ---------------------------------------- *
 * f5:                                      *
 * y = exp(x) - x*(x - 1.);                 *            
 * b = 3.;  a = -3.;                        *
 * ---------------------------------------- *
 * f6:                                      *
 * y = x*x + 8.*sin(3.*x/4.)  + x - 5.;     *            
 * b = 3.;  a = -1.;                        *
 * ---------------------------------------- *
 * f7:                                      *
 * y = x*sin(pihalf*x) + 6. - 3.*x;         *  
 * b = 3.;  a = -1.;                        *
 * ---------------------------------------- *
 * f8:                                      *
 * y = x*x*x - 0.5*x*x + 2.*x + 1.;         *
 * b = 2.;  a = -2.;                        *
 * ---------------------------------------- *
 * f7':y = x*sin(pihalf*x) + 6. - 3.*x;     *            
 * f9: y = x*x*cos(0.5*pihalf*x) + 8.;      *
 * ---------------------------------------- */