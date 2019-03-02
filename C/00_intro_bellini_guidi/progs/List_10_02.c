#include <stdio.h>

double quad(float);
double cubo(float);
double quar(float);
double quin(float);
double pote(float, int);

main()
{
  int    base, esponente;
  double ptnz;

  printf(" Inserire base: " );
  scanf("%d", &base);
  printf(" Inserire esponente (0-5): ");
  scanf("%d", &esponente);

  ptnz = pote( base, esponente);

  if (ptnz == -1) 
    printf("Potenza non prevista\n");
  else
    printf("La potenza %d di %d e' %f \n", esponente, base, ptnz);
}

double quad(float c)
{
  return(c*c);
}

double cubo(float c)
{
  return(c*c*c);
}

double quar(float c)
{
  return(c*c*c*c);
}

double quin(float c)
{
  return(c*c*c*c*c);
}

double pote(float b, int e)
{
  switch (e) {
    case   0: return (1);
    case   1: return (b);
    case   2: return (quad( b ));
    case   3: return (cubo( b ));
    case   4: return (quar( b ));
    case   5: return (quin( b ));
    default : return (-1);
  }
}
