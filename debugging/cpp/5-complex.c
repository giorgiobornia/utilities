#include <stdio.h>

#define ERRCODE -1

float myfoo(float totest)
{
  int ck;
  float res;

  res = totest-1.;     ck = __LINE__;
  if(res < 0)
    {
      fprintf(stderr, "ERROR in function %s, %s:%d \n", 
	      __func__, __FILE__, ck);
      fprintf(stderr, "parameter totest = %f gives a negative res = %f \n", 
	      totest, res);
      return(ERRCODE);
    }
  return(res);
}


int main(int argc, char *argv[])
{
  float a, b;
  char name[100];


  sprintf(name, "%s", argv[0]);

#ifdef __GNUC__
  printf("%s compiled with gcc version %d.%d.%d \n",
	 name, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#else
  printf("%s NOT Compiled with GNU compiler \n", name);
#endif
  printf("This version of %s has been compiled in date %s - %s \n", 
	 name, __DATE__, __TIME__);


  printf("Insert a \n");
  scanf("%f", &a);
    
  b = myfoo(a);
  
  if(b != ERRCODE) 
    {
      printf("b = %f \n", b);
    }
  else
    {
      /*
	Error management
      */
    }
}
