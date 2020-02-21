/* Funzione ricorsiva per il calcolo di base elevata a esp.
   esp può essere un intero qualsiasi                     */

double potenza(float base, int esp)
{
if(esp==0)
  return(1);
else
  if(esp<0)
    return(1/potenza(base, -esp));
  else
    return(base*potenza(base, esp-1));
}
