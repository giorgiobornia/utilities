#include <stdio.h>

char *strcpy(char *dest, char *source)
{
char *ptrdest=dest;
while( *dest++ = *source++ );
return(ptrdest);
}

int main(void)
{
char destinazione[1000];
char *sorgente= "Pascal";
strcpy(destinazione, sorgente);
printf("%s\n", sorgente);
printf("%s\n", destinazione);
}
