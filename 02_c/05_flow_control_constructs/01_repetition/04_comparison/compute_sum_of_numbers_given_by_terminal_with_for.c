/* For loop to compute the sum of 5 integer numbers input from terminal */

#include <stdio.h>

int main()
{

 int i, sum, number;

 printf("Sum 5 numbers from terminal\n");

sum = 0;

for(i = 1; i <= 5; i = i+1) {
	printf("Insert int: ");
	scanf("%d", &number);
	sum = sum + number;
	}

  printf("Sum: %d\n", sum);

return 0;

}
