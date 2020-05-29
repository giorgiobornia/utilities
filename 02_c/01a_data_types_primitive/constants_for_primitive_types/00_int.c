#include <stdio.h>

 
int main() {
 
  int a1 = 7;  /*decimal base*/
  int a2 = -7;  
  int a3 = 010;  /* octal base: number begins with 0 */
//   int a3 = 090;  /* compile error, 9 is not a symbol in the octal number system */
  int a4 = 0xe; /* hexadecimal base: number begins with 0x */
  
  printf("%d\n", a1);
  printf("%d\n", a2);
  printf("%d\n", a3);
  printf("%d\n", a4);
  
  long int b1 = 7l;
  long int b2 = 7L;
  long int b3 = 07l;  /* with octal representation */
  long int b4 = 0x7l; /* with hexadecimal representation */
  
  unsigned int c1 = 7u;
  unsigned int c2 = 7U;

  unsigned long int d1 = 7ul;
  unsigned long int d2 = 7UL;
  unsigned long int d3 = 7uL;
  unsigned long int d4 = 7Ul;
  
  unsigned long int d5 = 7lu;
  

  
 return 0;
 
}
