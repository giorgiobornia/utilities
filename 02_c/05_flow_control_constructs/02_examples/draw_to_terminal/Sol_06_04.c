

#include <stdio.h>
main()
{
int i, j, y, linee, colonne, volte;
char cornice, interno;

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

printf("\nCarattere della cornice: ");
scanf("%1s", &cornice);
printf("\nCarattere dell'interno: ");
scanf("%1s", &interno);

do {
  printf("\nNumero di visualizzazioni: ");
  scanf("%d", &volte);
}
while(colonne<1);

for(y=1; y<=volte; y++)
  for(i=1; i<=linee; i++)
    for(j=1; j<=colonne; j++)
      if(i==1 || i==linee || j==1 || j==colonne ) {
        printf("%c", cornice);
        if(j==colonne) printf("\n");
      }
      else printf("%c", interno);
}
