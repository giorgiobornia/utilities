#include <stdio.h>
#define EQ ==

/* ------------------------------------ *
 * Read a string corresponding to an arithmetic expression from scanf, 
 * and use a switch-case structure to print the correct result to terminal.
 * ------------------------------------ */

int main() {
    
  float value1, value2;
  char operator;

  printf("Write an arithmetic expression (of the type Number1 Operator Number2): ");
  
  scanf("%f %c %f", &value1, &operator, &value2);

  switch (operator)
    {
    case '+':
      printf("risultato: %f\n",value1 + value2);
      break;
    case '-':
      printf("risultato: %f\n",value1 - value2);
      break;
    case '*':
      printf("risultato: %f\n",value1 * value2);
      break;
    case '/':
      if (value2 EQ 0.)
	printf("divisione per zero!\n");
      else
	printf("risultato: %f\n",value1/value2);
      break;
    default:
      printf("operatore sconosciuto\n");
      break;
    }

  return 0;  
    
}
