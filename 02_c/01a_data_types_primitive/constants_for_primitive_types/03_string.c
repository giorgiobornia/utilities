#include <stdio.h>

 
int main() {
    
  /* double quotes for strings */
    
  /* An implicit null character \0 is placed at the end of the array */
  /* If you put a null character inside a string, only the substring up to that point is printed */
  char str_var1[] = "The cat is on the table";
  char str_var2[] = "The cat is on the table\0";  /* I think this is equivalent to the previous, then I believe the compiler will NOT add a null character */
  char str_var3[] = "The ca\0t is on the table";  /* null character \0 explicitly written in the middle, the string is terminated there */
  
  /* As an array of chars, a string can be represented by representing each char in multiple ways */
  /* Instead of the symbolic representation, let us represent some characters using their numeric representation (with \ in octal or with \x in hexadecimal) */
  char str_var4[] = "The c\141t is on the table"; /* a = 97 */ 
                                                  /* The first 'a' is written with its octal representation */  
                                                  /* What if I want to put a number right afterwards??? */
  char str_var5[] = "The cat is on the t\141ble"; /* The second 'a' is written with its octal representation */
  char str_var6[] = "The c\x61t is on the table"; /* The first 'a' is written with its hexadecimal representation */
  char str_var7[] = "The cat is on the t\x61ble"; /* The second 'a' is written with its hexadecimal representation, 
                                                     but there is a 'b' right after that makes the compiler think that it is a hexadecimal digit!
                                                     Then, it says "hex escape sequence out of range"
                                                     because \xff is the largest hexadecimal accepted for chars, and \x61b is larger... */
  
  printf("%s\n", str_var1);
  printf("%s\n", str_var2);
  printf("%s\n", str_var3);
  printf("%s\n", str_var4);
  printf("%s\n", str_var5);
  printf("%s\n", str_var6);
  printf("%s\n", str_var7);

  return 0;
 
}
