
#include <stdio.h>
#include <limits.h>

main()
{
int i, n, numero, max, min, media;

printf("MAGGIORE MINORE E MEDIA\n");
min = INT_MAX;
max = INT_MIN;
media = 0;
i = 1;

do {
  printf("\nLunghezza della sequenza: ");
  scanf("%d", &n);
}
while(n<1);

for(i=1; i<=n; i++) {
  printf("Valore int.: \t");
  scanf("%d", &numero);
  if(numero>max)
    max = numero;
  else
    if(numero<min)
      min = numero;
  media = media+numero;
}

printf("Maggiore: %d\n", max);
printf("Minore: %d\n", min);
printf("Media: %d\n", media/n);
}
