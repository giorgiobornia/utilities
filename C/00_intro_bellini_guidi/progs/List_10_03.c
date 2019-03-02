int x;            /* nome globale */

f()
{
  int x;          /* x locale che nasconde x globale */
  x = 1;          /* assegna 1 a x locale */
  {
    int x;        /* nasconde il primo x locale */
    x = 2;        /* assegna 2 al secondo x locale */
  }
  x = 3;          /* assegna 3 al primo x locale */
}

scanf ("%d", &x); /* inserisce un dato in x globale */
