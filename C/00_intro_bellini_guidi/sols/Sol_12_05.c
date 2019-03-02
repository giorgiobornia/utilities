/* Funzione per il calcolo di base elevata a esp.
   esp può essere un intero qualsiasi             */

double potenza(float base, int esp)
{
int s = 1;
double pot = 1;       /* inizializzazione di pot a 1
                         caso di esponente uguale a zero */
if(esp<0) {           /* l'esponente è negativo ? */
  esp = abs(esp);
  s = 0;
}

if(esp>0) {           /* calcolo della potenza */
  do
    pot = pot*base;   /* b*b*b... n volte */
  while(--esp>0);
}

if(s) return(pot);    /* l'esponente è positivo ? */
else  return(1/pot);
}
