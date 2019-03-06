#include <stdio.h>

int main(int argc, char *argv[])
{

#ifdef AAA
  printf("AAA \n");
#elif BBB
  printf("BBB \n");
#else
  printf("UNKNOWN \n");
#endif

}
