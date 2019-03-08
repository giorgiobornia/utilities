#include <stdio.h>
main()
{
int i;
FILE	*fp;
char	sequenza[80];

/* Apre il file.  Il simbolo di root \ si ottiene con il doppio slash */
fp = fopen("c:\\autoexec.bat", "r");
printf("Le prime 10 sequenze di caratteri sono:\n");
for(i = 0; i < 10; i++) {
  if (fscanf(fp, "%s", sequenza) == EOF){
    printf("Fine file!\n");
    break;
  }
  else 
    printf("Sequenza %d = \"%s\"\n", i, sequenza);
}
}
