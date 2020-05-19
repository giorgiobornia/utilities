/*  Enter a digit with scanf between 1 and 6, and print to terminal if it is even or odd, otherwise print "Other". Use swutch-case */

#include <stdio.h>

int main() {
    
char x;

printf("Type one digit: ");

scanf("%c", &x);

switch(x) {
  case '2':
  case '4':
  case '6':
    printf("Even\n");
    break;
  case '1':
  case '3':
  case '5':
    printf("Odd\n");
    break;
  default:
    printf("Other\n");
}

}
