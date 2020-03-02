/* Esempio di definizione di una struttura */

#include <stdio.h>

struct automobile {
  char *marca;
  char *modello;
  int venduto;
};

int main()
{
struct automobile a1, a2;

a1.marca = "FERRARI";
a1.modello = "F40";
a1.venduto = 200;

a2.marca = "OPEL";
a2.modello = "ASTRA";
a2.venduto = 1200;

printf("marca auto = %s\n", a1.marca);
printf("modello auto = %s\n", a1.modello);
printf("vendute = %d\n", a1.venduto);
printf("marca auto = %s\n", a2.marca);
printf("modello auto = %s\n", a2.modello);
printf("vendute = %d\n", a2.venduto);
}
