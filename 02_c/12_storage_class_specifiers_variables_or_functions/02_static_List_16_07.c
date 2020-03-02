#include <stdio.h>

#define FATTORE 25173
#define MODULO         65535
#define INCREMENTO     13849
#define SEME_INIZIALE      8
#define LOOP 10

unsigned rand(void);

void main()
{
int i;
for(i=0; i<LOOP; i++)
   printf("Il numero casuale %d e' %6u\n\n", i+1, rand());
}

unsigned rand(void)
{
static unsigned seme = SEME_INIZIALE;
seme = (FATTORE*seme+INCREMENTO) % MODULO;
return(seme);
}
