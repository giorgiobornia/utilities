#include <stdio.h>


int main () {
    
  int i, trian;

  printf("TABLE OF TRIANGULAR NUMBERS \n");
  printf("\n i     sum from 1 to i \n");
  printf("---    ---------------\n");

  /* for */
  trian=0;
  for (i=1; i<=10; i +=1) {
    trian = trian + i;
    printf(" %3d         %3d\n",i,trian);
  }
  printf("---    ---------------\n");

  /* while */
  i=1; trian=0;
  while (i<=10) {
    trian = trian + i;
    printf(" %3d         %3d\n",i,trian);
    i = i + 1;
  }
  printf("---    ---------------\n");
  
  /* while - with variants */
  i = trian = 0;
  while (i<10) {
    trian += ++i;
    printf(" %3d         %3d\n",i,trian);
  }
  printf("---    ---------------\n");
  
  return 0;
  
}



/*
TABLE OF TRIANGULAR NUMBERS

 i     sum from 1 to i
---    ---------------
   1           1
   2           3
   3           6
   4          10
   5          15
   6          21
   7          28
   8          36
   9          45
  10          55
---    ---------------
   1           1
   2           3
   3           6
   4          10
   5          15
   6          21
   7          28
   8          36
   9          45
  10          55
---    ---------------
   1           1
   2           3
   3           6
   4          10
   5          15
   6          21
   7          28
   8          36
   9          45
  10          55
---    ---------------*/
