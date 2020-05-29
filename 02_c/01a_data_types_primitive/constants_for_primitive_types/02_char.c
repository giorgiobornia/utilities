#include <stdio.h>

 
int main() {
    
    char a1 = 'a';   /* symbolic representation, between single quotes */
    char a2 = 97;    /* numeric representation, decimal */
    char a3 = 0141;  /* numeric representation, octal */                     /* 97 = 1*64 + 4*8 + 1 */ 
    char a5 = '\141';/* numeric representation, octal, alternative */       
    char a4 = 0x61;  /* numeric representation, hexadecimal */               /* 97 = 6*16 + 1 */
    char a6 = '\x61';/* numeric representation, hexadecimal, alternative */
    
    char a7 = 0;     /* null character */
    char a8 = '\0';  /* null character, octal */
    char a9 = '\x0'; /* null character, hexadecimal */
    
    char a10 = '\377'; /* last octal accepted:             = 255 */
    char a11 = '\400'; /* first octal out of range:        \400 = 4 * 8^2 = 256 */
    char a12 = '\xff'; /* last hexadecimal accepted:       15 * 16 + 15 = 255 */
    char a13 = '\x100'; /* first hexadecimal out of range: 16^2 = 256 */
    
  printf("%c\n", a1);
  printf("%c\n", a2);
  printf("%c\n", a3);
  printf("%c\n", a4);
  printf("%c\n", a5);
  printf("%c\n", a6);

  
 return 0;
 
}
