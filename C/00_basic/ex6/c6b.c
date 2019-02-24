#include <stdio.h>
#define EQ ==
/* ------------------------------------ *
 * Scrittura e compilazione di c6b.c:   *
 * switch                               *
 * ------------------------------------ */
main ()
{
  float value1, value2;
  char operator;

  printf
    ("Scrivi un'espressione aritmetica: ");
  scanf
    ("%f %c %f",&value1,&operator,&value2);

  switch (operator)
    {
    case '+':
      printf
	("risultato: %f\n",value1 + value2);
      break;
    case '-':
      printf
	("risultato: %f\n",value1 - value2);
      break;
    case '*':
      printf
	("risultato: %f\n",value1 * value2);
      break;
    case '/':
      if (value2 EQ 0.)
	printf("divisione per zero!\n");
      else
	printf
	  ("risultato: %f\n",value1/value2);
      break;
    default:
      printf("operatore sconosciuto\n");
      break;
    }
}
