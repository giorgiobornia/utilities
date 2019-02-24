/* --------------------------------- *
 * Scrittura e compilazione di c1.c  *
 * --------------------------------- */
main()

/* inizio blocco principale */ 
{

  /* dichiarazione di tre interi */
  int a,b,c;

  /* assegnazione ai primi due di un 
     valore, al terzo della somma */
  a=2;
  b =3;
  c = a+b;

  /* stampiamo i loro valori */
  printf("addendi, a:%2d, b:%5d;",a,b);
  printf(" loro somma:%2d \n",c);

}
/* fine blocco principale e programma */

/* ------------------------------
Compilazione ed esecuzione
raus:--> gcc -o c1 c1.c
raus:--> ./c1
addendi, a: 2, b: 3; loro somma: 5
raus:--> 
*/
