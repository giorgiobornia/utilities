#include <stdio.h>

/* #include "stdio.h  */  /* This is non-system headers */

int main()  {

  printf("Hello world! \n");

  /* printf('Hello world! \n');  */    /* single quotes instead of double quotes */
  
  /* PRINTF("Hello world! \n");  */    /* C is case-sensitive: printf or PRINTF are different functions */

  /* printf( \
  "Hello world! \n"); */  /* line continuation */
  
}



  /*

  
[ora inserisco prima solo la seconda, poi solo la terza]

 gcc -o c0 c0.c
c0.c:11:10: warning: character constant too long for its type
c0.c: In function `main':
c0.c:11: warning: passing arg 1 of `printf' 
makes pointer from integer without a cast

./c0
Ciao mamma!
Segmentation fault

 gcc -o c0 c0.c
In function 'main':
: undefined reference to `PRINTF'
collect2: ld returned 1 exit status

nm  c0.o
00000000 T main
         U printf
  */

         

  
  
  /*
          Notes:
- #include preprocessor directive          
- #include <...> vs "..."
- printf is a FUNCTION for standard output, such as main
- \n: escape sequence (new line)
- ; : instruction terminator
  */


