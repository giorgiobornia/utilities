#include <stdio.h>

#define GARE(a) gara##a

main()
{
char garaPrima[]   = "Stile libero";
char garaSeconda[] = "Rana";
char garaTerza[]   = "Dorso";

printf("%s\n", GARE(Prima));
printf("%s\n", GARE(Seconda));
printf("%s\n", GARE(Terza));
}
