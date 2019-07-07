#include <stdio.h>

int main()  {

  printf("Hello world! \n");
  /*
  PRINTF("Hello world! \n");
  */
  
}



  /*

 gcc -c c0.c    (oggetto: c0.o)
 gcc -o c0 c0.o (link: c0)
 ./c0           (esecuzione) 

  
[ora inserisco prima solo la seconda, 
 poi solo la terza]

 gcc -o c0 c0.c
c0.c:11:10: warning: character constant too 
long for its type
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
- main(...): inizio programma
- main and printf are FUNCTIONS (see later when we talk about functions)
- printf: funzione per lo standard output
- \n: manda a capo (nuova linea)
- C is case-sensitive: printf or PRINTF are different functions
- { ....}: isolates a block of instructions
- commento con /* ...
- ; : terminatore di istruzione
  */


