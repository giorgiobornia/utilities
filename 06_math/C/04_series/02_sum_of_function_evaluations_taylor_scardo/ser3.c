#include <math.h>
#include <stdio.h>
#define OUTFILE "ser3.dat"
#define eps 1.e-6
/* --------------------------------------- *
 * Serie 5                                 *
 * f(x)= (1+x)^(-1/3)                      *
 * ----------------------------------------*/

double fx(double);
/* ---------------------------------------- */
main ()
{
  FILE *fp;
  int i;
  double tmp,num,den,numer,denom,coef[11];
  double x,x0,x2,xodd,sp,value,term,error;

  /* *********************************** *
   * 1 - apri il file: cognome.dat       *
   * 2 - scrivi nome e cognome,          *
   *     numero di matricola e           *
   *     numero di esame                 *    
   * *********************************** */
  if ((fp=fopen(OUTFILE,"w")) == NULL) {
    (void) fprintf(stderr,"Non si apre: %s !\n",
		   OUTFILE);
    return;
  }
  
  fprintf(fp,"Nome: Ruben, Cognome: Scardovelli \n");
  fprintf(fp,"Matricola: 30586 \n");
  fprintf(fp,"E-mail: raus@mail.ing.unibo.it \n");
  fprintf(fp,"Esame: SER-3 \n\n");


  /* ************************************ *
   * 2 - stampa i valori dei coefficienti *
   * ************************************ */
  i = 0;
  numer = 1.;
  denom = 1.;
  coef[i] = 1.;
  fprintf(fp,"i:%2d, num,den,ratio: %7.2e, %7.2e, %15.8e \n",
            i,numer,denom,coef[i]);

  i = 1;
  num = 1.;
  den = 3.;
  numer *= -num;
  denom *= den;
  coef[i] = numer/denom;
  fprintf(fp,"i:%2d, num,den,ratio: %7.2e, %7.2e, %15.8e \n",
            i,num,den,coef[i]);

  for (i=2; i<=10; i++) {
    num = num + 3.;
    den = den + 3.;
    numer *= -num;
    denom *= den;
    coef[i] = numer/denom;
  fprintf(fp,"i:%2d, num,den,ratio: %7.2e, %7.2e, %15.8e \n",
            i,num,den,coef[i]);
  }
  fprintf(fp,"\n");

  /* ************************************ *
   * 3 - stampa le somme parziali         *
   * ************************************ */
  i = 0;
  x0 = -0.35;
  x = 1.;
  sp = 1.;
  value = pow((1.+x0),(-1./3.));
  fprintf(fp,"i:%2d, sp,power: %15.8e, %15.8e \n",
            i,sp,value);

  for (i=1; i<=10; i++) {
    x *= x0; 
    sp += coef[i]*x;
  fprintf(fp,"i:%2d, sp,power: %15.8e, %15.8e \n",
            i,sp,value);
  }
  fprintf(fp,"\n");

  /* ************************************ *
   * 3 - somma termini maggiori di eps    *
   * ************************************ */
  x0 = 0.65;
  x = 1.;
  value = pow((1.+x0),(-1./3.));
  i = 0;
  sp = 1.;
  term = 1.;
  while (fabs(term) > eps && i < 10) {
    fprintf(fp,"i:%2d, term,sp,power: %15.8e, %15.8e, %15.8e \n",
            i,term,sp,value);
    i++;
    x *= x0;
    term = coef[i]*x; 
    sp += term;
  }
  fprintf(fp,"\n Numero dei termini considerati: %2d\n\n",i);
  fprintf(fp,"i:%2d, term: %15.8e \n",i,term);

  /* ************************************ *
   * 5 - stampa gli errori relativi       *
   * ************************************ */
  x0 = 0.65;
  x = 1.;
  value = pow((1.+x0),(-1./3.));
  i = 0;
  sp = 1.;
  error = fabs(sp-value)/fabs(value);
  fprintf(fp,"i:%2d, sp,power, error: %15.8e, %15.8e, %15.8e \n",
            i,sp,value,error);

  for (i=1; i<=10; i++) {
    x *= x0;
    sp += coef[i]*x;
    error = fabs(sp-value)/fabs(value);
  fprintf(fp,"i:%2d, sp,power, error: %15.8e, %15.8e, %15.8e \n",
            i,sp,value,error);
  }
  fprintf(fp,"\n");


  fclose(fp);
}
