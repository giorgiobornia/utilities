#include <math.h>
#include <stdio.h>
#define OUTFILE "ser5.dat"
#define eps 1.e-6
/* --------------------------------------- *
 * Serie 5                                 *
 * f(x)= sin^(-1)(x)                       *
 * ----------------------------------------*/

double fx(double);
/* ---------------------------------------- */
int main ()
{
  FILE *fp;
  int i;
  double tmp,num,den,numer,denom,coef;
  double x,xodd,x2,sp,value,term,error;

  /* *********************************** *
   * 1 - apri il file: cognome.dat       *
   * 2 - scrivi nome e cognome,          *
   *     numero di matricola e           *
   *     numero di esame                 *    
   * *********************************** */
  if ((fp=fopen(OUTFILE,"w")) == NULL) {
    (void) fprintf(stderr,"Non si apre: %s !\n",
		   OUTFILE);
    return 1;
  }
  
  fprintf(fp,"Nome: Ruben, Cognome: Scardovelli \n");
  fprintf(fp,"Matricola: 30586 \n");
  fprintf(fp,"E-mail: raus@mail.ing.unibo.it \n");
  fprintf(fp,"Esame: SER-5 \n\n");


  /* ************************************ *
   * 2 - stampa i valori dei coefficienti *
   * ************************************ */
  i = 0;
  numer = 1.;
  denom = 1.;
  coef = 1.;
  fprintf(fp,"i:%2d, num,den,tmp,ratio: %7.2e, %7.2e, %7.2e, %13.8e \n",
            i,numer,denom,coef,coef);

  for (i=1; i<=10; i++) {
    num = 2.*i - 1.;
    den = 2.*i;
    numer *= num;
    denom *= den;
    tmp = den + 1.;
    coef = numer/(denom*tmp);
  fprintf(fp,"i:%2d, num,den,tmp,ratio: %7.2e, %7.2e, %7.2e, %13.8e \n",
            i,num,den,tmp,coef);
  }
  fprintf(fp,"\n");

  /* ************************************ *
   * 3 - stampa le somme parziali         *
   * ************************************ */
  x = -0.4;
  x2 = x*x;
  i = 0;
  numer = 1.;
  denom = 1.;
  coef = 1.;
  sp = x;
  xodd = x;
  value = asin(x);
  fprintf(fp,"i:%2d, sp,asin: %13.8e, %13.8e \n",
            i,sp,value);

  for (i=1; i<=10; i++) {
    num = 2.*i - 1.;
    den = 2.*i;
    numer *= num;
    denom *= den;
    tmp = den + 1.;
    coef = numer/(denom*tmp);
    xodd *= x2;
    sp += coef*xodd;
  fprintf(fp,"i:%2d, sp,asin: %13.8e, %13.8e \n",
            i,sp,value);
  }
  fprintf(fp,"\n");

  /* ************************************ *
   * 3 - somma termini maggiori di eps    *
   * ************************************ */
  x = 0.6;
  x2 = x*x;
  i = 0;
  numer = 1.;
  denom = 1.;
  coef = 1.;
  sp = term = x;
  xodd = x;
  value = asin(x);
  /*
  fprintf(fp,"i:%2d, term,sp,asin: %13.8e, %13.8e, %13.8e \n",
            i,term,sp,value);
  */
  while (term > eps) {
    fprintf(fp,"i:%2d, term,sp,asin: %13.8e, %13.8e, %13.8e \n",
            i,term,sp,value);
    i++;
    num = 2.*i - 1.;
    den = 2.*i;
    numer *= num;
    denom *= den;
    tmp = den + 1.;
    coef = numer/(denom*tmp);
    xodd *= x2;
    term = coef*xodd; 
    sp += term;
  }
  fprintf(fp,"\n Numero dei termini considerati: %2d\n\n",i);
  

  /* ************************************ *
   * 5 - stampa gli errori relativi       *
   * ************************************ */
  x = 0.6;
  x2 = x*x;
  i = 0;
  numer = 1.;
  denom = 1.;
  coef = 1.;
  sp = x;
  xodd = x;
  value = asin(x);
  error = fabs(sp-value)/fabs(value);
  fprintf(fp,"i:%2d, sp,asin, error: %13.8e, %13.8e, %13.8e \n",
            i,sp,value,error);

  for (i=1; i<=10; i++) {
    num = 2.*i - 1.;
    den = 2.*i;
    numer *= num;
    denom *= den;
    tmp = den + 1.;
    coef = numer/(denom*tmp);
    xodd *= x2;
    sp += coef*xodd;
    error = fabs(sp-value)/fabs(value);
  fprintf(fp,"i:%2d, sp,asin, error: %13.8e, %13.8e, %13.8e \n",
            i,sp,value,error);
  }
  fprintf(fp,"\n");


  fclose(fp);
}
