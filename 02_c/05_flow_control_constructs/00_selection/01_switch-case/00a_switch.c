/* Enter a digit with scanf and print to terminal the string if it is in the range 0-5, otherwise print "Not included". Use switch-case */

#include <stdio.h>


int main() {
    
int x;

printf("Type one digit: ");

scanf("%d", & x);


switch(x) {
  case (5>9)/*0*/:      /* The cases must contain an integer value that is known at compile time */
    printf("zero\n");
    break; /* It is not necessarily needed. If not there, each instruction starting from the obtained case is executed */
  case 1:
    printf("one\n");
    break;
  case 1+1:
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
  default:  /* This is optional. If there, it takes all other cases */
    printf("Not included\n");
    break;
}

  return 0;

}
