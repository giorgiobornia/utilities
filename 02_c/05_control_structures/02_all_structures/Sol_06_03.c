/* Visualizza un rettangolo di cornice *
   e parte interna Q; le dimensioni del rettangolo
   sono decise dall'utente                        */

#include <stdio.h>
main()
{
int i, j, linee, colonne;

do {
  printf("\nNumero di linee: ");
  scanf("%d", &linee);
}
while(linee<1);

do {
  printf("\nNumero di colonne: ");
  scanf("%d", &colonne);
}
while(colonne<1);

for(i=1; i<=linee; i++)
  for(j=1; j<=colonne; j++)
    if(i==1 || i==linee || j==1 || j==colonne) {
      printf("*");
      if(j==colonne) printf("\n");
    }
    else  printf("Q");
}
