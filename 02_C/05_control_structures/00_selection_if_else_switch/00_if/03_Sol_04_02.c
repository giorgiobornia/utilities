/* Read 4 distinct values from scanf, and determine which one is the largest. Use nested if. */

#include <stdio.h>
 int main() {
    
int a, b, c, d;
printf("\nType four distinct integer values: ");
scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);
scanf("%d", &d);

if(a>b)
  if(a>c)
    if(a>d)
      printf("The largest is: %d\n", a);
    else
      printf("The largest is: %d\n", d);
  else
    if(c>d)
      printf("The largest is: %d\n", c);
    else
      printf("The largest is: %d\n", d);
else
  if(b>c)
    if(b>d)
      printf("The largest is: %d\n", b);
    else
      printf("The largest is: %d\n", d);
  else
    if(c>d)
      printf("The largest is: %d\n", c);
    else
      printf("The largest is: %d\n", d);
}
