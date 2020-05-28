#include <stdio.h>

/*
 * Bitwise operators 
 * They act on integer-type data
 */

int main() {

 unsigned int a, b, r_1, r_2, r_3, r_4, r_5, r_6;
//  double z = 15.29; /* It gives compile error if you involve doubles or any other type, good */

 printf("To understand how many bits are involved, use sizeof (1 byte = 8 bits): # bytes = %d\n", sizeof(unsigned int) );
 
 
 a = 13; /* 00000000 00000000 00000000 00001101 in binary */
 b = 10; /* 00000000 00000000 00000000 00001010 in binary */
 
 r_1 = (a & b);    /* BINARY: bitwise and:   00000000 00000000 00000000 00001000 -> 8 */
 r_2 = (a | b);    /* BINARY: bitwise or:    00000000 00000000 00000000 00001111 -> 15 */
 r_3 = (a ^ b);    /* BINARY: bitwise xor:   00000000 00000000 00000000 00000111 -> 7 */
 r_4 = (~ a);      /* UNARY: bitwise not: 11111111 11111111 11111111 11110010 -> 4294967282 */
 r_5 = (a >> 1);   /* BINARY (MIXED): bitwise right shift by 1 position : 00000000 00000000 00000000 00000110 -> 6 */   /* Same as division by multiples of 2 ! */
 r_6 = (a << 1);   /* BINARY (MIXED): bitwise left  shift by 1 position : 00000000 00000000 00000000 00011010 -> 26 */  /* Same as multiplication by multiples of 2 ! */
 
 printf("%u\n", r_1);
 printf("%u\n", r_2);
 printf("%u\n", r_3);
 printf("%u\n", r_4);
 printf("%u\n", r_5);
 printf("%u\n", r_6);
  
//  %d integer in decimal form

//  %u unsigned integer in decimal form
//  %o unsigned integer in octal form
//  %x unsigned integer in hexadecimal form
 
//  There is no format specifier for binary numbers, you have to do it yourself

//  #include <stdio.h>
// #include <limits.h>
// 
// void print_bin(unsigned int integer)
// {
//     int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
//     while(i--) {
//         putchar('0' + ((integer >> i) & 1)); 
//     }
// }
   
 
 
 return 0;

}
