#include <stdio.h>


char convert_between_lowercase_and_uppercase(char c) {
    
  char cc = c;
  
       if ( c >= 'a' && c <= 'z') {   printf("Converting to uppercase...\n");  cc = c - ('a'-'A'); }
  else if ( c >= 'A' && c <= 'Z') {   printf("Converting to lowercase...\n");  cc = c + 'a'-'A'; }
  else { printf("Not an alphabetical character\n"); }
  
  return cc;
}


int main() {
    
  char c;

  printf("Insert a character\n");
      
  scanf("%c", &c);
  
  printf("The conversion is %c\n", convert_between_lowercase_and_uppercase(c));

    
 return 0;   
    
}
