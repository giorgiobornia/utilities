/* Enter a digit with scanf and print to terminal the string if it is in the range 0-5, otherwise print "Not included". Use swutch-case */
#include <stdio.h>

int main() {
    
int x;

printf("Type one digit: ");

scanf("%d", &x);

switch(x) {
  case 0:
    printf("zero\n");
    break;
  case 1:
    printf("one\n");
    break;
  case 2:
    printf("two\n");
    break;
  case 3:
    printf("three\n");
    break;
  case 4:
    printf("four\n");
    break;
  case 5:
    printf("five\n");
    break;
  default:
    printf("Not included\n");
    break;
}

}
